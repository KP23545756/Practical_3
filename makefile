CXX      := g++
CXXFLAGS := -std=c++11 -Wall -Wextra -Iinclude

TARGET   := eventflow

SRC      := $(wildcard src/*.cpp)
OBJ      := $(SRC:src/%.cpp=obj/%.o)

.PHONY: all clean valgrind directories

all: directories $(TARGET)

directories:
	@mkdir -p obj

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ)

obj/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

valgrind: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET)

clean:
	rm -rf $(TARGET) obj