module TransformAPI where

import DataStructures
import Cpp

transformClass :: MakeTeaMonad CppClass
transformClass = return (emptyClass "Tree_transform")
