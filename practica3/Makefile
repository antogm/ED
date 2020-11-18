INC = ./include
SRC = ./src
BIN = ./bin
OBJ = ./obj
BINFLAGS = -Wall -g -I$(INC) --std=c++11
CPPFLAGS = -Wall -g -I$(INC) -c --std=c++11

#

all: mrproper $(BIN)/test

$(BIN)/test: $(OBJ)/test.o $(OBJ)/pila_max_vd.o $(OBJ)/pila_max_cola.o
	g++ $(BINFLAGS) -o $(BIN)/test $(OBJ)/test.o $(OBJ)/pila_max_cola.o $(OBJ)/pila_max_vd.o

$(OBJ)/test.o: $(SRC)/test.cpp
	g++ $(CPPFLAGS) -o $(OBJ)/test.o $(SRC)/test.cpp

$(OBJ)/pila_max_vd.o: $(SRC)/pila_max_vd.cpp
	g++ $(CPPFLAGS) -o ./obj/pila_max_vd.o ./src/pila_max_vd.cpp

$(OBJ)/pila_max_cola.o: $(SRC)/pila_max_cola.cpp
	g++ $(CPPFLAGS) -o $(OBJ)/pila_max_cola.o $(SRC)/pila_max_cola.cpp

#

doxy :
	doxygen $(DOC)/Doxy-file

mrproper :
	-rm $(BIN)/*
	-rm $(OBJ)/*
