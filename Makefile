
CXX		  := g++
CXX_FLAGS := -Wall -Wextra -std=c++17 -ggdb -Wno-return-type -Wswitch

BIN		:= bin
SRC		:= src
INCLUDE	:= include

LIBRARIES	:= lib
EXECUTABLE	:= simulador
ARGS  := test/cinta.in test/salida.out


all: $(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cc
	$(CXX) $(CXX_FLAGS) -I $(INCLUDE) $^ -o $@ -L $(LIBRARIES)

one: clean all
	clear
	./$(BIN)/$(EXECUTABLE) test/ejemplosRAM/test1.ram $(ARGS)

two: clean all
	clear
	./$(BIN)/$(EXECUTABLE) test/ejemplosRAM/test2.ram $(ARGS)

three: clean all
	clear
	./$(BIN)/$(EXECUTABLE) test/ejemplosRAM/test3.ram $(ARGS)

four: clean all
	clear
	./$(BIN)/$(EXECUTABLE) test/ejemplosRAM/test4.ram $(ARGS)

five: clean all
	clear
	./$(BIN)/$(EXECUTABLE) test/ejemplosRAM/test5.ram $(ARGS)

six: clean all
	clear
	./$(BIN)/$(EXECUTABLE) test/ejemplosRAM/test6.ram $(ARGS)

seven: clean all
	clear
	./$(BIN)/$(EXECUTABLE) test/ejemplosRAM/test7.ram $(ARGS)

clean:
	-rm $(BIN)/simulador

clear: clean