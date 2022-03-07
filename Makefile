
CXX		  := g++
CXX_FLAGS := -Wall -Wextra -std=c++17 -ggdb -Wno-return-type

BIN		:= bin
SRC		:= src
INCLUDE	:= include

LIBRARIES	:= lib
EXECUTABLE	:= simulador


all: $(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cc
	$(CXX) $(CXX_FLAGS) -I $(INCLUDE) $^ -o $@ -L $(LIBRARIES)

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

clean:
	-rm $(BIN)/simulador

clear: clean