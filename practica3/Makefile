INC = ./include
SRC = ./src
BIN = ./bin
OBJ = ./obj
CPPFLAGS = -Wall -g  -I$(INC) -c --std=c++11

#
#

$(BIN)/test: $(OBJ)/test.o $(OBJ)/pila_max.o
	g++ -o $(BIN)/test $(OBJ)/test.o $(OBJ)/pila_max.o

$(OBJ)/test.o: $(SRC)/test.cpp $(INC)/pila_max.h $(INC)/pila_max_vd.h $(SRC)/pila_max_vd.cpp
	g++ $(CPPFLAGS) -o $(OBJ)/test.o $(SRC)/test.cpp

$(OBJ)/pila_max.o: $(INC)/pila_max.h $(INC)/pila_max_vd.h $(SRC)/pila_max_vd.cpp
	g++ $(CPPFLAGS) -o $(OBJ)/pila_max.o $(INC)/pila_max.h

#
#

doxy :
	doxygen $(DOC)/Doxy-file

clean :
	-rm $(OBJ)/*

mrproper : clean
	-rm $(BIN)/*
