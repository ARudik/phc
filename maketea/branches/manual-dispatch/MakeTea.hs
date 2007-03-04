module MakeTea where

import Control.Monad.State
import DataStructures
import ContextResolution
import MakeTeaMonad
import BasicClasses
import Cpp
import TransformAPI

maketea :: Grammar -> IO ()
maketea grammar = do
	let (classes, transform) = flip evalState (initState grammar) $ do
		contextResolution
		createBasicClasses
		classes <- withClasses return
		transform <- transformClass
		return (classes, transform)
	forM_ classes print 
	print transform
