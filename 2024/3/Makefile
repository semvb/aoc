# Compiler and flags
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra

# Targets and source files
TARGETS := 3a 3b
SRCS := 3a.cpp 3b.cpp

# Default target
all: $(TARGETS)

# Rule to compile each source file into an executable
3a: 3a.cpp
	$(CXX) $(CXXFLAGS) 3a.cpp -o 3a

3b: 3b.cpp
	$(CXX) $(CXXFLAGS) 3b.cpp -o 3b

# Clean up generated files
clean:
	rm -f $(TARGETS)

