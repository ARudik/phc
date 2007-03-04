module MakeTea where

import Control.Monad.State
import DataStructures
import ContextResolution

maketea :: Grammar -> IO ()
maketea grammar = do
	let result = evalState contexts grammar
	print result 
