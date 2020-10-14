SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c --std=c++11
all:$(BIN)/ejercicio2 $(BIN)/ejercicio1 $(BIN)/ej_marco $(BIN)/negativo

# ************

$(BIN)/ejercicio2: $(OBJ)/ejercicio2.o $(OBJ)/imagen.o $(OBJ)/imagenES.o
	$(CXX) -o $(BIN)/ejercicio2 $(OBJ)/ejercicio2.o $(OBJ)/imagen.o $(OBJ)/imagenES.o

$(BIN)/ejercicio1: $(OBJ)/ejercicio1.o $(OBJ)/imagen.o $(OBJ)/imagenES.o
	$(CXX) -o $(BIN)/ejercicio1 $(OBJ)/ejercicio1.o $(OBJ)/imagen.o $(OBJ)/imagenES.o

$(BIN)/ej_marco: $(OBJ)/ej_marco.o $(OBJ)/imagen.o 
	$(CXX) -o $(BIN)/ej_marco $(OBJ)/ej_marco.o $(OBJ)/imagen.o

$(BIN)/negativo: $(OBJ)/negativo.o $(OBJ)/imagenES.o
	g++ -g -o $(BIN)/negativo $(OBJ)/negativo.o $(OBJ)/imagenES.o

$(OBJ)/ejercicio1.o: $(SRC)/ejercicio1.cpp $(INC)/imagen.h $(INC)/imagenES.h
	$(CXX) $(CPPFLAGS)  $(SRC)/ejercicio1.cpp -o  $(OBJ)/ejercicio1.o 

$(OBJ)/ejercicio2.o: $(SRC)/ejercicio2.cpp $(INC)/imagen.h $(INC)/imagenES.h
	$(CXX) $(CPPFLAGS)  $(SRC)/ejercicio2.cpp -o  $(OBJ)/ejercicio2.o 

$(OBJ)/ej_marco.o: $(SRC)/ej_marco.cpp $(INC)/imagen.h
	$(CXX) $(CPPFLAGS)  $(SRC)/ej_marco.cpp -o  $(OBJ)/ej_marco.o 

$(OBJ)/imagen.o: src/imagen.cpp include/imagen.h
	g++ -g -c -o $(OBJ)/imagen.o -Iinclude $(SRC)/imagen.cpp

$(OBJ)/imagenES.o: $(SRC)/imagenES.cpp $(INC)/imagenES.h
	g++ -g -c -o $(OBJ)/imagenES.o -Iinclude $(SRC)/imagenES.cpp

$(OBJ)/negativo.o : $(SRC)/negativo.cpp
	g++ -g -c -o $(OBJ)/negativo.o -Iinclude $(SRC)/negativo.cpp



clean :
	-rm $(OBJ)/*

mrproper : clean
	-rm $(BIN)/* $(OBJ)/*