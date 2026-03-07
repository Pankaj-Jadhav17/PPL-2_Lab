CXX = g++
CXXFLAGS = -Wall

all: triangle

triangle: main.o Triangle.o
	$(CXX) main.o Triangle.o -o triangle

main.o: main.cpp Triangle.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Triangle.o: Triangle.cpp Triangle.h
	$(CXX) $(CXXFLAGS) -c Triangle.cpp

clean:
	rm -f *.o triangle