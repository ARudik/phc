module Main where

import Text.ParserCombinators.Parsec
import System

import DataStructures
import Parser
import MakeTea

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
			maketea prefix grammar includes mixin
