# Compiler and flags
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra

# Targets and source files
TARGETS := 4a 4b
SRCS := 4a.cpp 4b.cpp

# Default target
all: $(TARGETS)

# Rule to compile each source file into an executable
4a: 4a.cpp
	$(CXX) $(CXXFLAGS) 4a.cpp -o 4a

4b: 4b.cpp
	$(CXX) $(CXXFLAGS) 4b.cpp -o 4b

# Clean up generated files
clean:
	rm -f $(TARGETS)

