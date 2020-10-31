SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
MO = morphing
CPPFLAGS = -Wall -g  -I$(INC) -c --std=c++11
all:$(BIN)/pruebaImagen

# ************

$(BIN)/pruebaImagen: $(OBJ)/pruebaImagen.o $(OBJ)/imagen.o $(OBJ)/imagenES.o
	$(CXX) -o $(BIN)/pruebaImagen $(OBJ)/pruebaImagen.o $(OBJ)/imagen.o $(OBJ)/imagenES.o

$(OBJ)/pruebaImagen.o: $(SRC)/pruebaImagen.cpp $(INC)/imagen.h
	$(CXX) $(CPPFLAGS) $(SRC)/pruebaImagen.cpp -o $(OBJ)/pruebaImagen.o 

$(OBJ)/imagen.o: $(SRC)/imagen.cpp $(INC)/imagen.h $(INC)/imagenES.h
	$(CXX) $(CPPFLAGS) $(SRC)/imagen.cpp -o $(OBJ)/imagen.o

$(OBJ)/imagenES.o: $(SRC)/imagenES.cpp $(INC)/imagenES.h
	$(CXX) $(CPPFLAGS) $(SRC)/imagenES.cpp -o $(OBJ)/imagenES.o

# ************

clean :
	-rm $(OBJ)/*
	-rm $(MO)/*.pgm
	-rm $(MO)/*.gif

mrproper : clean
	-rm $(BIN)/*

execute:
	./$(BIN)/pruebaImagen
	@echo
	@echo
	@echo "Convirtiendo .PGM -> .GIF"
	@echo "Espere unos segundos ..."
	convert -delay 1 -loop 0 $(MO)/*.pgm $(MO)/morphed.gif
