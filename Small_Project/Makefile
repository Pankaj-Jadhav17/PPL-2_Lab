CXX      = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude
SRCS     = main.cpp src/base_conversion.cpp src/float_format.cpp src/file_stats.cpp src/conic.cpp src/fraction.cpp
TARGET   = solution

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

clean:
	rm -f $(TARGET)
	