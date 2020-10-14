SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c --std=c++11
all:$(BIN)/pruebaImagen

# ************

$(BIN)/pruebaImagen: $(OBJ)/pruebaImagen.o $(OBJ)/imagen.o
	$(CXX) -o $(BIN)/pruebaImagen $(OBJ)/pruebaImagen.o $(OBJ)/imagen.o

$(OBJ)/pruebaImagen.o: $(SRC)/pruebaImagen.cpp $(INC)/imagen.h
	$(CXX) $(CPPFLAGS)  $(SRC)/pruebaImagen.cpp -o  $(OBJ)/pruebaImagen.o 

$(OBJ)/imagen.o: $(SRC)/imagen.cpp $(INC)/imagen.h $(INC)/imagenES.h 
	g++ -g -c -o $(OBJ)/imagen.o -Iinclude $(SRC)/imagen.cpp

$(OBJ)/imagenES.o: $(SRC)/imagenES.cpp $(INC)/imagenES.h
	g++ -g -c -o $(OBJ)/imagenES.o -Iinclude $(SRC)/imagenES.cpp


clean :
	-rm $(OBJ)/*

mrproper : clean
	-rm $(BIN)/* $(OBJ)/*
