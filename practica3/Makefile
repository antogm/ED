INC = ./include
SRC = ./src
BIN = ./bin
OBJ = ./obj
DOC = ./doc
BINFLAGS = -Wall -g -I$(INC) -I$(SRC) --std=c++11
CPPFLAGS = -Wall -g -I$(INC) -I$(SRC) -c --std=c++11

#

all: $(BIN)/test

$(BIN)/test: $(OBJ)/test.o $(INC)/pila_max.h $(INC)/cola.h
	g++ $(BINFLAGS) -o $(BIN)/test $(OBJ)/test.o
	
$(OBJ)/test.o: $(SRC)/test.cpp $(SRC)/cola.cpp
	g++ $(CPPFLAGS) -o $(OBJ)/test.o $(SRC)/test.cpp

#

doxy :
	doxygen $(DOC)/Doxy-file

mrproper :
	-rm $(BIN)/*
	-rm $(OBJ)/*
