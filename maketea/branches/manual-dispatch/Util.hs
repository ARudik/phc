module Util where

{-
 - Existentials
 -}

data Some :: (* -> *) -> * where
	Exists :: forall a. t a -> Some t 

elim :: (forall a. t a -> b) -> Some t -> b
elim f (Exists t) = f t

elim2 :: (forall a b. t a -> t b -> c) -> Some t -> Some t -> c
elim2 f (Exists t) (Exists t') = f t t'

{-
 - Various
 -}

implies :: (a -> Bool) -> (a -> Bool) -> a -> Bool
f `implies` g = \a -> not (f a) || g a

{-
 - Monadic operators
 -}

concatMapM :: Monad m => (a -> m [b]) -> [a] -> m [b]
concatMapM f [] = return []
concatMapM f (a:as) = do
	bs1 <- f a
	bs2 <- concatMapM f as
	return (bs1 ++ bs2)
