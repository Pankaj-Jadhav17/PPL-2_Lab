CXX = g++
CXXFLAGS = -Wall -std=c++11

TARGET = palindrome

all: $(TARGET)

$(TARGET): main.o Palindrome.o
	$(CXX) $(CXXFLAGS) -o $(TARGET) main.o Palindrome.o

main.o: main.cpp Palindrome.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Palindrome.o: Palindrome.cpp Palindrome.h
	$(CXX) $(CXXFLAGS) -c Palindrome.cpp

clean:
	rm -f *.o $(TARGET)