all: maketea

maketea: Makefile *.hs
	ghc -fglasgow-exts --make Main.hs -o maketea

clean:
	rm -f *.hi *.o 
	rm -f *.h *.cpp
	rm -f README.TreeTransform

cpp:
	gcc -I../../lib -DNO_GC -c ast.cpp
	gcc -I../../lib -DNO_GC -c Tree_transform.cpp
	gcc -I../../lib -DNO_GC -c Tree_visitor.cpp
