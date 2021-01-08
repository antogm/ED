SRC = ./src
INC = ./include
OBJ = ./obj
DOC = ./doc
BIN = ./bin
CXX = g++
CPPFLAGS = -Wall -g -I$(INC) --std=c++11

all: $(BIN)/pruebarotacion $(BIN)/pruebapegado $(BIN)/rutas_aereas

$(BIN)/rutas_aereas: $(OBJ)/rutas_aereas.o $(OBJ)/imagen.o $(OBJ)/imagenES.o $(INC)/Paises.h $(INC)/Pais.h $(OBJ)/ruta.o $(OBJ)/punto.o $(OBJ)/almacen_rutas.o
	g++ $(CPPFLAGS) -o $(BIN)/rutas_aereas $(OBJ)/rutas_aereas.o $(OBJ)/imagen.o $(OBJ)/imagenES.o $(INC)/Pais.h $(INC)/Paises.h $(OBJ)/ruta.o $(OBJ)/punto.o $(OBJ)/almacen_rutas.o

$(BIN)/pruebarotacion: $(OBJ)/pruebarotacion.o $(OBJ)/imagen.o $(OBJ)/imagenES.o
	g++ $(CPPFLAGS) -o $(BIN)/pruebarotacion $(OBJ)/pruebarotacion.o $(OBJ)/imagen.o $(OBJ)/imagenES.o

$(BIN)/pruebapegado: $(OBJ)/pruebapegado.o $(OBJ)/imagen.o $(OBJ)/imagenES.o
	g++ $(CPPFLAGS) -o $(BIN)/pruebapegado $(OBJ)/pruebapegado.o $(OBJ)/imagen.o $(OBJ)/imagenES.o

$(OBJ)/rutas_aereas.o: $(SRC)/rutas_aereas.cpp
	g++ $(CPPFLAGS) -c -o $(OBJ)/rutas_aereas.o $(SRC)/rutas_aereas.cpp

$(OBJ)/pruebapegado.o: $(SRC)/pruebapegado.cpp 
	g++ $(CPPFLAGS) -c -o $(OBJ)/pruebapegado.o $(SRC)/pruebapegado.cpp

$(OBJ)/pruebarotacion.o: $(SRC)/pruebarotacion.cpp 
	g++ $(CPPFLAGS) -c -o $(OBJ)/pruebarotacion.o $(SRC)/pruebarotacion.cpp

$(OBJ)/ruta.o: $(INC)/ruta.h $(SRC)/ruta.cpp
	g++ $(CPPFLAGS) -c -o $(OBJ)/ruta.o $(SRC)/ruta.cpp

$(OBJ)/almacen_rutas.o: $(INC)/almacen_rutas.h $(SRC)/almacen_rutas.cpp
	g++ $(CPPFLAGS) -c -o $(OBJ)/almacen_rutas.o $(SRC)/almacen_rutas.cpp

$(OBJ)/punto.o: $(INC)/Punto.h $(SRC)/punto.cpp
	g++ $(CPPFLAGS) -c -o $(OBJ)/punto.o $(SRC)/punto.cpp

$(OBJ)/imagen.o: $(SRC)/imagen.cpp $(INC)/imagen.h
	g++ $(CPPFLAGS) -c -o $(OBJ)/imagen.o $(SRC)/imagen.cpp

$(OBJ)/imagenES.o: $(SRC)/imagenES.cpp $(INC)/imagenES.h
	g++ $(CPPFLAGS) -c -o $(OBJ)/imagenES.o $(SRC)/imagenES.cpp


# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Limpieza ************
clean :
	-rm $(OBJ)/*

mrproper : clean
	-rm $(BIN)/* doc/html/*
