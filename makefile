all: compile link

compile:
	g++ -Isrc/include -c *.cpp FMGC/*.cpp MCDU/*.cpp src/include/imgui/*.cpp
link:
	g++ *.o -o main -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system -lopengl32 -lwinmm -lgdi32