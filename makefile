CXX := g++
CXXFLAGS := -std=c++11 -Wall -Iinclude
TARGET := eventflow

SRC := main.cpp $(wildcard src/*.cpp)
OBJ := $(SRC:.cpp=.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJ)
