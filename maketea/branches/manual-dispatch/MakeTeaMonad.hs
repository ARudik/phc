module MakeTeaMonad where

import Control.Monad.State
import Data.Maybe
import Data.List

import DataStructures

withGrammar :: (Grammar -> MakeTeaMonad a) -> MakeTeaMonad a
withGrammar f = get >>= f . grammar 

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

concatMapM :: Monad m => (a -> m [b]) -> [a] -> m [b]
concatMapM f [] = return []
concatMapM f (a:as) = do
	bs1 <- f a
	bs2 <- concatMapM f as
	return (bs1 ++ bs2)
