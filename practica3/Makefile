INC = ./include
SRC = ./src
BIN = ./bin
FLAGS = -I$(INC) -I$(SRC) --std=c++11

#

$(BIN)/test: $(SRC)/test.cpp $(INC)/pila_max.h
	g++ $(FLAGS) -o $(BIN)/test $(SRC)/test.cpp $(INC)/pila_max.h

#

doxy :
	doxygen $(DOC)/Doxy-file

mrproper :
	-rm $(BIN)/*
