{-
 	phc -- the open source PHP compiler
	See license/README.license for licensing information

	Some library definitions
-}

module MakeTeaLib where

-- Add a prefix and a postfix to every element of the list, and that concat
-- them all together, inserting an infix in between every two elements
ppifix :: String -> String -> String -> [String] -> String
ppifix _ _ _ [] = ""
ppifix prefix postfix ifix list = foldr1 g (map f list)
	where
		-- Add the prefix and postfix
		f :: String -> String
		f x = prefix ++ x ++ postfix
		-- Concat with infix in between
		g :: String -> String -> String
		g x y = x ++ ifix ++ y

-- Like ppifix, but map show across the list first
ppifix_ms :: Show a => String -> String -> String -> [a] -> String  
ppifix_ms prefix postfix ifix list = ppifix prefix postfix ifix (map show list) 

-- Comma separated list
comma_sep_list :: [String] -> String
comma_sep_list = ppifix "" "" ", "

-- Convert a character based on an assocative list of chars
tr :: [(Char,Char)] -> Char -> Char
tr dict a = case (lookup a dict) of
	Nothing -> a
	(Just b) -> b

-- Convert a string to lowercase
tolower :: String -> String
tolower = map (tr (zip ['A'..'Z'] ['a'..'z'])) 

-- Check whether a list is a "subset" of another list (O(N^2))
sublist :: Eq a => [a] -> [a] -> Bool 
sublist [] ys = True
sublist (x:xs) ys = (elem x ys) && (sublist xs ys)

-- Subtract the second list from the first
list_diff :: Eq a => [a] -> [a] -> [a]
list_diff [] ys = []
list_diff (x:xs) ys 
	| elem x ys = list_diff xs ys 
	| otherwise	= x:(list_diff xs ys)

-- Intersection between two lists (maintaining list order). O(n^2)
list_intersection :: Eq a => [a] -> [a] -> [a]
list_intersection [] _ = []
list_intersection (x:xs) ys 
	| elem x ys = x:(list_intersection xs ys)
	| otherwise	= list_intersection xs ys

-- Generalised trimming 
gtrim :: (a -> Bool) -> [a] -> [a]
gtrim f list = (trim_tail . trim_head) list
	where
		trim_head [] = []
		trim_head (x:xs) = 
			if 
				f x	
			then
				trim_head xs
			else
				x:xs
		trim_tail = reverse . trim_head . reverse 

-- Trim whitespace from a string
trim :: String -> String
trim str = gtrim ws str
	where
		ws x = x == ' ' || x == '\t' || x == '\n' || x == '\r'

-- Split a list at the first occurance of the given symbol
-- i.e. split 3 [1,2,3,4,5] yields ([1,2,3],[4,5])
split :: Eq a => a -> [a] -> ([a],[a])
split h [] = ([],[])
split h (x:xs) 
	| h == x = ([h],xs)
	| otherwise = let (a,b) = split h xs in (x:a,b)
