module MakeTea where

import Control.Monad.State
import DataStructures
import ContextResolution
import MakeTeaMonad
import BasicClasses
import Cpp
import TransformAPI

maketea :: String -> Grammar -> IO ()
maketea prefix grammar = do
	let (classes, transform) = flip evalState (initState (prefix ++ "_") grammar) $ do
		contextResolution
		createBasicClasses
		classes <- withClasses return
		transform <- transformClass
		return (classes, transform)
	let commonHeader = unlines [
		  "#include <list>"
		, "using namespace std;"
		, ""
		]
	writeFile (prefix ++ ".h") $
		commonHeader ++
		unlines (map (\c -> "class " ++ c ++ ";") (map name classes)) ++
		unlines (map showClassHeader classes) 
	writeFile (prefix ++ ".cpp") $
		"#include \"" ++ prefix ++ ".h\"\n\n" ++ 
		unlines (map showClassImplementation classes)
	writeFile (prefix ++ "_transform.h") $
		commonHeader ++
		"#include \"" ++ prefix ++ ".h\"\n\n" ++ 
		showClassHeader transform
	writeFile (prefix ++ "_transform.cpp") $
		"#include \"" ++ prefix ++ "_transform.h\"\n\n" ++ 
		showClassImplementation transform
