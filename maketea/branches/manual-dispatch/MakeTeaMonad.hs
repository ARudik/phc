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

withClasses :: ([CppClass] -> MakeTeaMonad a) -> MakeTeaMonad a
withClasses f = get >>= f . fromJust . classes 

withContexts :: ([Context] -> MakeTeaMonad a) -> MakeTeaMonad a
withContexts f = get >>= f . fromJust . contexts

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

setClasses :: [CppClass] -> MakeTeaMonad ()
setClasses cs = do
	s <- get
	put (s { classes = Just cs })

initState :: Grammar -> MakeTeaState
initState gr = MTS {
	  grammar = gr
	, nextClassID = 1 
	, contexts = Nothing
	, classes = Nothing
	}
