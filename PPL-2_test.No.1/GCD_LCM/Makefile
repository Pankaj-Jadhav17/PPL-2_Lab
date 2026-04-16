CXX = g++
CXXFLAGS = -Wall -std=c++11

TARGET = gcdlcm

all: $(TARGET)

$(TARGET): main.o GCDLCM.o
	$(CXX) $(CXXFLAGS) -o $(TARGET) main.o GCDLCM.o

main.o: main.cpp GCDLCM.h
	$(CXX) $(CXXFLAGS) -c main.cpp

GCDLCM.o: GCDLCM.cpp GCDLCM.h
	$(CXX) $(CXXFLAGS) -c GCDLCM.cpp

clean:
	rm -f *.o $(TARGET)