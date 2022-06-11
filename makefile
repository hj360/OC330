all:
	g++ -Isrc/include -Lsrc/lib -o MCDU *.cpp -lmingw32 -lSDL2main -lSDL2