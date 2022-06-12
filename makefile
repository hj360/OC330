all:
	g++ -Isrc/include -Lsrc/lib -o A330_SYSTEM *.cpp FMGC/*.cpp MCDU/*.cpp -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf