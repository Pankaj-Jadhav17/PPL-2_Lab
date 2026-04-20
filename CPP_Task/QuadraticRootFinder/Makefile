CXX = g++
CXXFLAGS = -Wall -std=c++17

all: quadratic

quadratic: main.cpp QuadraticRootFinder.cpp QuadraticRootFinder.h
	$(CXX) $(CXXFLAGS) main.cpp QuadraticRootFinder.cpp -o quadratic

clean:
	rm -f quadratic