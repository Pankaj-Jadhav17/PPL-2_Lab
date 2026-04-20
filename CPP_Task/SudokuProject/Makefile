CXX=g++
CXXFLAGS=-Wall

all: sudoku

sudoku: main.o Sudoku.o
	$(CXX) main.o Sudoku.o -o sudoku

main.o: main.cpp Sudoku.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Sudoku.o: Sudoku.cpp Sudoku.h
	$(CXX) $(CXXFLAGS) -c Sudoku.cpp

clean:
	rm -f *.o sudoku