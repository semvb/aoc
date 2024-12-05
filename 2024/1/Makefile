# Compiler and flags
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra

# Targets and source files
TARGETS := 1a 1b
SRCS := 1a.cpp 1b.cpp

# Default target
all: $(TARGETS)

# Rule to compile each source file into an executable
1a: 1a.cpp
	$(CXX) $(CXXFLAGS) 1a.cpp -o 1a

1b: 1b.cpp
	$(CXX) $(CXXFLAGS) 1b.cpp -o 1b

# Clean up generated files
clean:
	rm -f $(TARGETS)

