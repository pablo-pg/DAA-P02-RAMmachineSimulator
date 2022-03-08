
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

build: clean all

one:
	./$(BIN)/$(EXECUTABLE) test/ejemplosRAM/test1.ram $(ARGS)

two:
	./$(BIN)/$(EXECUTABLE) test/ejemplosRAM/test2.ram $(ARGS)

three:
	./$(BIN)/$(EXECUTABLE) test/ejemplosRAM/test3.ram $(ARGS)

four:
	./$(BIN)/$(EXECUTABLE) test/ejemplosRAM/test4.ram $(ARGS)

five:
	./$(BIN)/$(EXECUTABLE) test/ejemplosRAM/test5.ram $(ARGS)

six:
	./$(BIN)/$(EXECUTABLE) test/ejemplosRAM/test6.ram $(ARGS)

seven:
	./$(BIN)/$(EXECUTABLE) test/ejemplosRAM/test7.ram $(ARGS)

clean:
	-rm $(BIN)/simulador

clear: clean