CXX = g++
CXXFLAGS = -std=c++11 

all: factor

factor: main.o Factor.o
	$(CXX) $(CXXFLAGS) main.o Factor.o -o factor

main.o: main.cpp Factor.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Factor.o: Factor.cpp Factor.h
	$(CXX) $(CXXFLAGS) -c Factor.cpp	

clean:
	rm -f *.o factor