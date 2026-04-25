CXX = g++
CXXFLAGS = -Wall -std=c++11

TARGET = prime

all: $(TARGET)

$(TARGET): main.o Prime.o
	$(CXX) $(CXXFLAGS) -o $(TARGET) main.o Prime.o

main.o: main.cpp Prime.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Prime.o: Prime.cpp Prime.h
	$(CXX) $(CXXFLAGS) -c Prime.cpp

clean:
	rm -f *.o $(TARGET)