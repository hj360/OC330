all: compile link

compile:
	g++ -Isrc/include -IMCDU -IFMGC -IGUI -ICONFIG -ISIMDATA -ISENSORS -IADIRS -c *.cpp FMGC/*.cpp MCDU/*.cpp GUI/*.cpp SIMDATA/*.cpp SENSORS/*.cpp ADIRS/*.cpp
link:
	g++ *.o -o main -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system -lopengl32 -lwinmm -lgdi32