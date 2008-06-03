% cfg.clp defines the predicates for the CFG. This actually creates the CFG sessions from the MIR. It is intended that do_cft.clp is run, which will create the cfg databases, but cfg.clp will need to be imported by client analyses.

import "src/generated/MIR.clp".
import "src/analyse/cfg.clp".
import "3rdparty/clpa/analysis/base/utility.clp".
using dotty.

analyze session_name("mir").

% To build the CFG, we go through 2 phases. First, we create the linked list
% of nodes, using program points. Secondly, we do a top-down pass through
% this list, adding CFG edges between statements. Branches add two edges, one
% to each target. Gotos and labels are passed through, adding edges between
% their predecessors and their successors.  It is important to stop processing
% if a node is already in the CFG (which may or may not happen with back
% edges). We then add these edges to the session. 
%
% Note that the second phase removes any unreachable code.



% Phase 1 - annotate the program with program points.
%
% Its a little tricky to create the CFG from lists of statements, since when
% we find a label, we dont have a way of getting the next item in the list.
% We create a straight linked list of program points for this purpose.

% Program point in a function
type pp ::=
    p_s{t_Statement}			% point of the of statement
  | p_entry{t_Method}		% entry point of function/script
  | p_exit{t_Method}			% exit point of function/script
  . 

% The first step is to add program points. Each point is a statement, but
% this joins them to make it easier to associate each one with the next one
% in the list (for labels and gotos/branches)
predicate pp_node (P:pp).
predicate pp_edge (P0:pp, P1:pp).
predicate build_pps (P:pp, STMTS:list[t_Statement], METHOD:t_Method).

% Annotate a script with program points
method (ID, _, yes{STMTs}),
	A = p_entry{ID},
	+pp_node(A),							% entry point
	+build_pps (A, STMTs, ID).		% connect to statements

% Handle a list of statements - base case
build_pps (PREV, [], METHOD), +pp_node(p_exit{METHOD}), +pp_edge (PREV, p_exit{METHOD}).

% Handle a list of statements - Recursive case
build_pps (PREV, [H|STMTs], METHOD),
	P = p_s{H},
	+pp_node(P), +pp_edge (PREV, P),
	+build_pps (P, STMTs, METHOD).

% Build a .dot file to view the PPs
%dotty_graph (Name, true, dotgraph{Nodes, Edges}, [], [], []) :-
%	Name = "PPs",
%	\/(pp_node (P), N = dg_node{P,[]}):list_all(N, Nodes),
%	\/(pp_edge (EN1, EN2), E = dg_edge{EN1,EN2, []}):list_all(E, Edges).



% Phase 2: Build the CFG

% Add a CFG edge between FROM and a cfg_node created from TO (which is in the
% pp_graph).
predicate dfs (FROM:t_cfg_node, TO:pp, METHOD:string).

% Start at the top
dfs (nentry{METHOD}, P, NAME) :-
	pp_edge (p_entry{METHOD}, P), 
	% get the name
		method (METHOD, SIG, _), 
		signature (SIG, _, _, NAME_ID, _),
		mETHOD_NAME (NAME_ID, NAME).

% End condition
dfs (N, p_exit{METHOD}, NAME), 
	+cfg(NAME)->cfg_edge (N, nexit{METHOD}).

% Normal statement - add edge and recurse
dfs (N, p_s{S}, NAME), 
	S \= statement_Branch{_}, S \= statement_Goto{_}, S \= statement_Label{_},
	N1 = nblock{S},
	+cfg(NAME)->cfg_edge (N, N1),
	% recurse
		pp_edge (p_s{S}, P1), % get next pp
		+dfs (N1, P1, NAME).

% Label - dont create a node or an edge, just follow the path
dfs (N, p_s{S}, NAME), 
	S = statement_Label{_},
	% recurse
		pp_edge (p_s{S}, P1), % get next pp
		+dfs (N, P1, NAME).



% find the PP for a LABEL_NAME
predicate label_name_loc (in LABEL_NAME:string, out PP:pp).

label_name_loc (NAME_VAL, PP) :-
	lABEL_NAME (NAME_ID, NAME_VAL),
	label (LABEL_ID, NAME_ID),
	pp_node (LOC), LOC = p_s{statement_Label{LABEL_ID}},
	PP = LOC.


% Branch - create a node, and follow both paths
dfs (N, p_s{S}, NAME),
	S = statement_Branch{B},
	branch (B, VAR, TRUE_LABEL, FALSE_LABEL),
	N1 = nbranch {VAR},
	+cfg(NAME)->cfg_edge (N, N1),
	% find targets and recurse
		% find the names of the labels for the branch targets
			lABEL_NAME (TRUE_LABEL, TRUE_LABEL_NAME), 
			lABEL_NAME (FALSE_LABEL, FALSE_LABEL_NAME), 
		% find their PPs
			label_name_loc (TRUE_LABEL_NAME, TRUE_PP),
			label_name_loc (FALSE_LABEL_NAME, FALSE_PP),
		% recurse
			+dfs (N1, TRUE_PP, NAME),
			+dfs (N1, FALSE_PP, NAME).

% Goto - dont create a node or an edge, just follow the path
dfs (N, p_s{S}, NAME),
	S = statement_Goto{G},
	goto (G, LABEL),
	% find target and recurse
		% find the names of the labels for the branch targets
			lABEL_NAME (LABEL, LABEL_NAME), 
			label_name_loc (LABEL_NAME, PP),
			+dfs (N, PP, NAME).