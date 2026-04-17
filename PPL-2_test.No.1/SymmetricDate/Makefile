CXX = g++
CXXFLAGS = -Wall -std=c++11

TARGET = symmetric

all: $(TARGET)

$(TARGET): main.o SymmetricDate.o
	$(CXX) $(CXXFLAGS) -o $(TARGET) main.o SymmetricDate.o

main.o: main.cpp SymmetricDate.h
	$(CXX) $(CXXFLAGS) -c main.cpp

SymmetricDate.o: SymmetricDate.cpp SymmetricDate.h
	$(CXX) $(CXXFLAGS) -c SymmetricDate.cpp

clean:
	rm -f *.o $(TARGET)