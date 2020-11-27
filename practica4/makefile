INC = ./include
SRC = ./src
BIN = ./bin
OBJ = ./obj
DOC = ./doc
FLAGS = -Wall -g -I$(INC) -I$(SRC) --std=c++11

#

all: $(BIN)/test clean

$(BIN)/usoguia: $(SRC)/usoguia.cpp
	g++ $(FLAGS) -o $(BIN)/usoguia $(SRC)/usoguia.cpp

$(BIN)/test: $(OBJ)/test.o $(INC)/diccionario.h
	g++ $(FLAGS) -o $(BIN)/test $(OBJ)/test.o
	
$(OBJ)/test.o: $(SRC)/test.cpp
	g++ $(FLAGS) -c -o $(OBJ)/test.o $(SRC)/test.cpp

#

doxy :
	doxygen $(DOC)/Doxy-file

clean :
	-rm $(OBJ)/*

mrproper :
	-rm $(BIN)/*
