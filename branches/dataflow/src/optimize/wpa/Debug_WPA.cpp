#include "Debug_WPA.h"
#include "optimize/Abstract_value.h"

using namespace std;


Debug_WPA::Debug_WPA (Whole_program* wp)
: WPA (wp)
{
	DEBUG (__FUNCTION__);
}

string
cert_to_string (certainty cert)
{
	if (cert == DEFINITE)
		return "DEFINITE";
	else if (cert == POSSIBLE)
		return "POSSIBLE";

	phc_unreachable ();
}

void
Debug_WPA::forward_bind (Basic_block* caller, Entry_block* entry)
{
	string bb_name = "__none__";
	if (caller)
		bb_name = ST (caller);

	DEBUG ("forward bind " << bb_name << " to " << ST (entry));
}

void
Debug_WPA::backward_bind (Basic_block* caller, Exit_block* exit)
{
	DEBUG (__FUNCTION__);
}


void
Debug_WPA::create_reference (Basic_block* bb, Alias_name lhs,
									  Alias_name rhs, certainty cert)
{
	DEBUG (__FUNCTION__
			<< ": " << lhs.str ()
			<< ", " << rhs.str ()
			<< ", " << cert_to_string (cert));
}

void
Debug_WPA::assign_empty_array (Basic_block* bb, Alias_name lhs,
									string unique_name, certainty cert)
{
	DEBUG (__FUNCTION__
			<< ": " << lhs.str ()
			<< ", " << unique_name
			<< ", " << cert_to_string (cert));
}

void
Debug_WPA::assign_value (Basic_block* bb, Alias_name lhs,
								 Abstract_value* val, certainty cert)
{
	CHECK_DEBUG ();

	cdebug
	<< __FUNCTION__ << ": " << lhs.str () << ", ";

	val->dump();

	cdebug
	<< ", " << cert_to_string (cert)
	<< endl;
}

void
Debug_WPA::copy_value (Basic_block* bb, Alias_name lhs,
							  Alias_name rhs, certainty cert)
{
	DEBUG (__FUNCTION__
			<< ": " << lhs.str ()
			<< ", " << rhs.str ()
			<< ", " << cert_to_string (cert));
}


void
Debug_WPA::kill_value (Basic_block* bb, Alias_name lhs)
{
	DEBUG (__FUNCTION__
		<< ": " << lhs.str ());
}

void
Debug_WPA::kill_reference (Basic_block* bb, Alias_name lhs)
{
	DEBUG (__FUNCTION__
		<< ": " << lhs.str ());
}
	
void
Debug_WPA::record_use (Basic_block* bb, Alias_name use,
									 certainty cert)
{
	DEBUG (__FUNCTION__
		<< ": " << use.str ()
		<< ", " << cert_to_string (cert));
}


void
Debug_WPA::pull_init (Basic_block* bb)
{
	DEBUG (__FUNCTION__ << " " << bb->ID);
}

void
Debug_WPA::pull_first_pred (Basic_block* bb, Basic_block* pred)
{
	DEBUG (__FUNCTION__ << " from " << pred->ID);
}

void
Debug_WPA::pull_pred (Basic_block* bb, Basic_block* pred)
{
	DEBUG (__FUNCTION__ << " from " << pred->ID);
}

void
Debug_WPA::pull_finish (Basic_block* bb)
{
	DEBUG (__FUNCTION__);
}


void
Debug_WPA::aggregate_results (Basic_block* bb)
{
	DEBUG (__FUNCTION__);
}

bool
Debug_WPA::solution_changed (Basic_block* bb)
{
	DEBUG (__FUNCTION__);
	return false;
}

bool
Debug_WPA::equals (WPA* other)
{
	DEBUG (__FUNCTION__);
	return true;
}

void
Debug_WPA::dump (Basic_block* bb, string comment)
{
}
