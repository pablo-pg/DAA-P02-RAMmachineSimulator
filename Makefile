
CXX		  := g++
CXX_FLAGS := -Wall -Wextra -std=c++17 -ggdb -Wno-return-type -Wswitch

BIN		:= bin
SRC		:= src
INCLUDE	:= include

LIBRARIES	:= lib
EXECUTABLE	:= simulador
ARGS  := test/ejemplosRAM/test1.ram test/cinta.in salida.out


all: $(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cc
	$(CXX) $(CXX_FLAGS) -I $(INCLUDE) $^ -o $@ -L $(LIBRARIES)

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE) $(ARGS)

clean:
	-rm $(BIN)/simulador

clear: clean