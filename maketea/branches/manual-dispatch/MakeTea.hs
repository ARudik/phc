module MakeTea where

import Control.Monad.State
import DataStructures
import ContextResolution
import MakeTeaMonad
import BasicClasses
import Cpp

maketea :: Grammar -> IO ()
maketea grammar = do
	let result = flip evalState (initState grammar) $ do
		contextResolution
		createBasicClasses
	print result
