module MakeTea where

import Control.Monad.State
import DataStructures
import ContextResolution
import MakeTeaMonad
import BasicClasses
import Cpp

maketea :: Grammar -> IO ()
maketea grammar = do
	let (classes) = flip evalState (initState grammar) $ do
		contextResolution
		createBasicClasses
		classes <- withClasses return 
		return classes
	forM_ classes $ \cl -> do
		print cl
		putStrLn ""
