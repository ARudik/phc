{-
 - maketea -- generate C++ AST infrastructure
 - (C) 2006-2007 Edsko de Vries and John Gilbert
 -}

module Main where

import Text.ParserCombinators.Parsec
import Control.Monad.State
import System

import Parser
import DataStructures
import ContextResolution
import MakeTeaMonad
import BasicClasses
import Cpp
import TransformAPI
import PrettyPrinter

main :: IO ()
main = do
	args <- getArgs
	let [prefix, filename] = 
		if length args == 2 
			then args 
			else error "usage: maketea prefix filename"
	parseResult <- parseFromFile maketeaP filename
	case parseResult of 
		Left parseError -> do
			print parseError
		Right (grammar, includes, mixin) -> 
			runMakeTea prefix grammar includes mixin

runMakeTea :: String -> Grammar -> [Include] -> [Class] -> IO ()
runMakeTea prefix grammar includes mixin = do 
	--  
	let 
		maketea = do
			contextResolution
			createBasicClasses
			withClasses $ setClasses . orderClasses
			-- Extract relevant components
			contexts <- withContexts return
			classes <- withClasses return
			transform <- transformClass
			return (contexts, classes, transform)
		init = initState (prefix ++ "_") grammar
		runMaketea = evalState maketea init
		(contexts, classes, transform) = runMaketea
		commonHeader = unlines [
			  "#include <list>"
			, "using namespace std;"
			, ""
			]
	-- And create output
	writeFile (prefix ++ "-contexts") $ unlines (map show contexts)
	writeFile (prefix ++ ".h") $
		commonHeader ++
		unlines (map (\c -> "class " ++ c ++ ";") (map name classes)) ++
		"\n" ++
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

