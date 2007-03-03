{-
 	phc -- the open source PHP compiler
	See license/README.license for licensing information

	This program converts the grammar into the various required C++ classes
	and the Tree Transform API (hence, "make Terminal")
-}

module Main where

import MakeTea
import MakeTeaParser 
import Text.ParserCombinators.Parsec
import System

-- Main method (used by ghc)
main :: IO ()
main = do
	args <- getArgs
	progName <- getProgName
	case (args) of
		[] -> putStr ("Usage: " ++ progName ++ " filename [-covariant]\n");
		file:otherargs -> do
			result <- parseFromFile grammar file
			case (result) of
				Left err -> do
					putStr "Parse error at " 
					print err
				Right result -> do
					let (grammar, includes, partial_classes) = result
					process_grammar otherargs grammar includes partial_classes

-- Useful for running from within Hugs
run :: String -> [String] -> IO ()
run file otherargs =
	do
		result <- parseFromFile grammar file
		case (result) of
			Left err -> do
				putStr "Parse error at " 
				print err
			Right result -> do
				let (grammar, includes, partial_classes) = result
				process_grammar otherargs grammar includes partial_classes
