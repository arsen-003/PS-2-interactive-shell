# Compiler and flags
CXX = g++
CXXFLAGS = -Wall

# Targets
TARGET = interactive-shell
SRC = interactive_shell.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(TARGET)
