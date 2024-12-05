# Compiler and flags
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra

# Targets and source files
TARGETS := 2a 2b
SRCS := 2a.cpp 2b.cpp

# Default target
all: $(TARGETS)

# Rule to compile each source file into an executable
2a: 2a.cpp
	$(CXX) $(CXXFLAGS) 2a.cpp -o 2a

2b: 2b.cpp
	$(CXX) $(CXXFLAGS) 2b.cpp -o 2b

# Clean up generated files
clean:
	rm -f $(TARGETS)

