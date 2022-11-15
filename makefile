sandpile:  main.o cell.o grid.o sandpile.o colormapper.o
	g++ main.o cell.o grid.o sandpile.o colormapper.o -o sandpile

main.o: main.cpp
	g++ -w -c main.cpp

cell.o: Cell.cpp
	g++ -w -c Cell.cpp

grid.o: Grid.cpp
	g++ -w -c Grid.cpp

sandpile.o: Sandpile.cpp
	g++ -w -c Sandpile.cpp

colormapper.o: ColorMapper.cpp
	g++ -w -c ColorMapper.cpp