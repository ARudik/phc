module Util where

{-
 - Existentials
 -}

data Exists :: (* -> *) -> * where
	Exists :: forall a. t a -> Exists t 

elim :: (forall a. t a -> b) -> Exists t -> b
elim f (Exists t) = f t

{-
 - Monadic operators
 -}

concatMapM :: Monad m => (a -> m [b]) -> [a] -> m [b]
concatMapM f [] = return []
concatMapM f (a:as) = do
	bs1 <- f a
	bs2 <- concatMapM f as
	return (bs1 ++ bs2)
