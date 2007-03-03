module Main where

import DataStructures
import Parser
import Text.ParserCombinators.Parsec
import System

main :: IO ()
main = do
	args <- getArgs
	parseResult <- case args of
		[] -> do
			src <- getContents
			return (parse grammar "" src)
		file:_ ->
			parseFromFile grammar file
	case parseResult of 
		Left parseError -> do
			print parseError
		Right grammar ->
			print grammar
		
