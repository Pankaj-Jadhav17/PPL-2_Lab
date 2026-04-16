CXX = g++
CXXFLAGS = -Wall -std=c++11

TARGET = angle

all: $(TARGET)

$(TARGET): main.o Angle.o
	$(CXX) $(CXXFLAGS) -o $(TARGET) main.o Angle.o

main.o: main.cpp Angle.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Angle.o: Angle.cpp Angle.h
	$(CXX) $(CXXFLAGS) -c Angle.cpp

clean:
	rm -f *.o $(TARGET)