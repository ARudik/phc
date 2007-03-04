module Main where

import Text.ParserCombinators.Parsec
import System

import DataStructures
import Parser
import MakeTea

main :: IO ()
main = do
	args <- getArgs
	parseResult <- case args of
		[] -> do
			src <- getContents
			return (parse maketeaInput "" src)
		file:_ ->
			parseFromFile maketeaInput file
	case parseResult of 
		Left parseError -> do
			print parseError
		Right grammar ->
			maketea grammar
