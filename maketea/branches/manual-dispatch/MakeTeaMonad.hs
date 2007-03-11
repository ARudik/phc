module MakeTeaMonad where

import Control.Monad.State
import Data.Maybe
import Data.List

import DataStructures
import Util

withGrammar :: (Grammar -> MakeTeaMonad a) -> MakeTeaMonad a
withGrammar f = get >>= f . grammar 

withConj :: ([Rule Conj] -> MakeTeaMonad a) -> MakeTeaMonad a
withConj f = withGrammar $ f . catMaybes . map (elim conj) 
	where
		conj :: Rule a -> Maybe (Rule Conj)
		conj r@(Conj _ _) = Just r
		conj (Disj _ _) = Nothing

withDisj :: ([Rule Disj] -> MakeTeaMonad a) -> MakeTeaMonad a
withDisj f = withGrammar $ f . catMaybes . map (elim disj)
	where
		disj :: Rule a -> Maybe (Rule Disj)
		disj (Conj _ _) = Nothing
		disj r@(Disj _ _) = Just r

{-
withTokens :: ([Symbol] -> MakeTeaMonad a) -> MakeTeaMonad a
withTokens f = withGrammar $ \rules -> 
	do
		let tokens = concatMap (elim g) rules
		f (nub tokens)
	where
		g :: Rule a -> [Symbol]
		g (Disj _ body) = [t | t@(Terminal _ _) <- body]
		g (Conj _ body) = [t | Term _ t@(Terminal _ _) _ <- body]
-}

withNonMarkers :: ([Term NonMarker] -> MakeTeaMonad a) -> MakeTeaMonad a
withNonMarkers f = withConj $ f . allNonMarkers

withClasses :: ([Class] -> MakeTeaMonad a) -> MakeTeaMonad a
withClasses f = get >>= f . fromJust . classes 

withContexts :: ([Context] -> MakeTeaMonad a) -> MakeTeaMonad a
withContexts f = get >>= f . fromJust . contexts

withPrefix :: (String -> MakeTeaMonad a) -> MakeTeaMonad a
withPrefix f = get >>= f . prefix

getNextClassID :: MakeTeaMonad Integer
getNextClassID = do
	s <- get
	let cid = nextClassID s
	put (s { nextClassID = cid + 1 })
	return cid

setContexts :: [Context] -> MakeTeaMonad ()
setContexts cxs = do
	s <- get
	put (s { contexts = Just cxs })

setClasses :: [Class] -> MakeTeaMonad ()
setClasses cs = do
	s <- get
	put (s { classes = Just cs })

initState :: String -> Grammar -> MakeTeaState
initState pr gr = MTS {
	  prefix = pr
	, grammar = gr
	, nextClassID = 1 
	, contexts = Nothing
	, classes = Nothing
	}

fromJustM :: Monad m => String -> Maybe a -> m a
fromJustM err (Just a) = return a
fromJustM err Nothing = fail err

{-
 - Filtering
 -}

allTerms :: [Rule Conj] -> [Some Term]
allTerms =  concatMap conjBody 

allNonMarkers :: [Rule Conj] -> [Term NonMarker]
allNonMarkers = nonMarkers . allTerms

conjBody :: Rule Conj -> [Some Term]
conjBody (Conj _ body) = body

nonMarkers :: [Some Term] -> [Term NonMarker]
nonMarkers = catMaybes . map (elim f) 
	where
		f :: Term a -> Maybe (Term NonMarker)
		f t@(Term _ _ _) = Just t
		f _ = Nothing
