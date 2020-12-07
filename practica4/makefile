INC = ./include
SRC = ./src
BIN = ./bin
OBJ = ./obj
DOC = ./doc
FLAGS = -Wall -g -I$(INC) -I$(SRC) --std=c++11

#

all: $(BIN)/testdiccionario $(BIN)/testguia clean

# Guia_Tlf:

$(BIN)/testguia: $(OBJ)/testguia.o $(OBJ)/guiatlf.o
	g++ $(FLAGS) -o $(BIN)/testguia $(OBJ)/testguia.o $(OBJ)/guiatlf.o

$(OBJ)/testguia.o: $(SRC)/testguia.cpp
	g++ $(FLAGS) -c -o $(OBJ)/testguia.o $(SRC)/testguia.cpp

$(OBJ)/guiatlf.o: $(SRC)/guiatlf.cpp $(INC)/guiatlf.h
	g++ $(FLAGS) -c -o $(OBJ)/guiatlf.o $(SRC)/guiatlf.cpp

# Diccionario:

$(BIN)/testdiccionario: $(OBJ)/testdiccionario.o $(INC)/diccionario.h
	g++ $(FLAGS) -o $(BIN)/testdiccionario $(OBJ)/testdiccionario.o
	
$(OBJ)/testdiccionario.o: $(SRC)/testdiccionario.cpp
	g++ $(FLAGS) -c -o $(OBJ)/testdiccionario.o $(SRC)/testdiccionario.cpp

#

doxy :
	doxygen $(DOC)/Doxy-file

clean :
	-rm $(OBJ)/*

mrproper :
	-rm $(BIN)/*
