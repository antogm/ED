SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c

	
all:  $(BIN)/pruebarotacion $(BIN)/pruebapegado $(BIN)/rutas_aereas

$(BIN)/rutas_aereas: $(OBJ)/rutas_aereas.o $(OBJ)/imagenES.o 	$(OBJ)/imagen.o
	$(CXX) -o $(BIN)/rutas_aereas $(OBJ)/rutas_aereas.o $(OBJ)/imagenES.o 	$(OBJ)/imagen.o

$(OBJ)/rutas_aereas.o: $(SRC)/rutas_aereas.cpp $(INC)/Punto.h $(INC)/Pais.h $(INC)/Paises.h $(INC)/imagen.h $(INC)/almacen_rutas.h
	$(CXX) $(CPPFLAGS) $(SRC)/rutas_aereas.cpp -o $(OBJ)/rutas_aereas.o

$(BIN)/pruebapegado:$(OBJ)/pruebapegado.o $(OBJ)/imagen.o $(OBJ)/imagenES.o
	$(CXX) -o $(BIN)/pruebapegado $(OBJ)/pruebapegado.o $(OBJ)/imagen.o $(OBJ)/imagenES.o

$(OBJ)/pruebapegado.o: $(SRC)/pruebapegado.cpp $(INC)/imagen.h
	$(CXX) $(CPPFLAGS) $(SRC)/pruebapegado.cpp -o $(OBJ)/pruebapegado.o

$(BIN)/pruebarotacion:$(OBJ)/pruebarotacion.o $(OBJ)/imagen.o $(OBJ)/imagenES.o
	$(CXX) -o $(BIN)/pruebarotacion $(OBJ)/pruebarotacion.o $(OBJ)/imagen.o $(OBJ)/imagenES.o

$(OBJ)/pruebarotacion.o: $(SRC)/pruebarotacion.cpp $(INC)/imagen.h
	$(CXX) $(CPPFLAGS) $(SRC)/pruebarotacion.cpp -o $(OBJ)/pruebarotacion.o

$(OBJ)/imagen.o: $(SRC)/imagen.cpp $(INC)/imagen.h
	$(CXX) $(CPPFLAGS) $(SRC)/imagen.cpp -o $(OBJ)/imagen.o

$(OBJ)/imagenES.o: $(SRC)/imagenES.cpp $(INC)/imagenES.h
	$(CXX) $(CPPFLAGS) $(SRC)/imagenES.cpp -o $(OBJ)/imagenES.o



# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ $(BIN)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
