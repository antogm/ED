INC = ./include
SRC = ./src
BIN = ./bin
OBJ = ./obj
DOC = ./doc
FLAGS = -Wall -g -I$(INC) -I$(SRC) --std=c++11

#

all: $(BIN)/test

$(BIN)/test: $(OBJ)/test.o $(INC)/pila_max.h $(INC)/cola.h
	g++ $(FLAGS) -o $(BIN)/test $(OBJ)/test.o
	
$(OBJ)/test.o: $(SRC)/test.cpp $(SRC)/cola.cpp
	g++ $(FLAGS) -c -o $(OBJ)/test.o $(SRC)/test.cpp

#

doxy :
	doxygen $(DOC)/Doxy-file

mrproper :
	-rm $(BIN)/*
	-rm $(OBJ)/*
