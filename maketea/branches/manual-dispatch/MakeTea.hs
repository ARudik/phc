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
	putStrLn "#include <list>"
	putStrLn "using namespace std;"
	forM_ (map name classes) $ \c -> putStrLn ("class " ++ c ++ ";")
	forM_ classes print 
	print transform
