SRC = ./src
INC = ./include
OBJ = ./obj
DOC = ./doc
BIN = ./bin
CXX = g++
CPPFLAGS = -Wall -g -I$(INC) --std=c++11

# Primera semana -----> Prueba de la función "Rota()" del archivo <pruebarotacion.cpp>
all: $(BIN)/pruebarotacion $(BIN)/pruebapegado

$(BIN)/pruebarotacion: $(OBJ)/pruebarotacion.o $(OBJ)/imagen.o $(OBJ)/imagenES.o
	g++ $(CPPFLAGS) -o $(BIN)/pruebarotacion $(OBJ)/pruebarotacion.o $(OBJ)/imagen.o $(OBJ)/imagenES.o

$(BIN)/pruebapegado: $(OBJ)/pruebapegado.o $(OBJ)/imagen.o $(OBJ)/imagenES.o
	g++ $(CPPFLAGS) -o $(BIN)/pruebapegado $(OBJ)/pruebapegado.o $(OBJ)/imagen.o $(OBJ)/imagenES.o

$(OBJ)/pruebapegado.o: $(SRC)/pruebapegado.cpp 
	g++ $(CPPFLAGS) -c -o $(OBJ)/pruebapegado.o $(SRC)/pruebapegado.cpp

$(OBJ)/pruebarotacion.o: $(SRC)/pruebarotacion.cpp 
	g++ $(CPPFLAGS) -c -o $(OBJ)/pruebarotacion.o $(SRC)/pruebarotacion.cpp

$(OBJ)/imagen.o: $(SRC)/imagen.cpp $(INC)/imagen.h
	g++ $(CPPFLAGS) -c -o $(OBJ)/imagen.o $(SRC)/imagen.cpp

$(OBJ)/imagenES.o: $(SRC)/imagenES.cpp $(INC)/imagenES.h
	g++ $(CPPFLAGS) -c -o $(OBJ)/imagenES.o $(SRC)/imagenES.cpp


# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
