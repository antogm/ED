// Fichero: ejercicio2.cpp
// Umbraliza una imagen de forma automática
// Formato:
//    ejercicio2 <FichE> <FichS>
//    donde:
//   <FichE> es la imagen PGM que se va a umbralizar. No se modifica.
//   <FichS> es la imagen PGM resultado de umbralizar la imagen de <FichE>.
//

#include <iostream>
#include <cstdlib>
#include <cstring>
#include "imagen.h"
#include "imagenEs.h"

using namespace std;

int CalcularNivelGrisMedio ( const Imagen I );

int main (int argc, char* argv[]){
	
	char *fichE, *fichS;
	unsigned char* img;
	int nf, nc;
	
	// Procesa los parámetros recibidos 
	if (argc != 3){
		cerr << "Error: Numero incorrecto de parametros.\n";
		cerr << "Uso: negativo <FichImagenOriginal> <FichImagenDestino>\n";
		exit (1);
	};

	fichE = argv[1],
	fichS = argv[2];

	cout << endl;
	cout << "Fichero origen: " << fichE << endl;
	cout << "Fichero resultado: " << fichS << endl;
	

	// Lee la imagen del fichero de entrada
	TipoImagen tipo = LeerTipoImagen(fichE);
	switch( tipo ){
		case IMG_PGM:
			img = LeerImagenPGM(fichE, nf, nc);
			break;

		case IMG_PPM:
			img = LeerImagenPPM(fichE, nf, nc);
			break;

		default:
			cerr << "Error: Formato del fichero de entrada incorrecto";
			exit(1);
	}

	if (!img){
		cerr << "Error: No pudo leerse la imagen." << endl;
		cerr << "Terminando la ejecucion del programa." << endl;
		exit (1);
	}

	// Mostrar los parametros calculados al leer la imagen
	cout << endl;
	cout << "Dimensiones de " << fichE << ":" << endl;
	
	cout << "   Imagen   = " << nf  << " filas x " << nc << " columnas " << endl;

	// Introducir los datos en un objeto del TDA Imagen
	Imagen origen(nf,nc);

	for (int i = 0; i < nf; i++)
		for (int j = 0; j < nc; j++)
			origen.asigna_pixel(i, j, img[i*nc +j]);
	
	delete[] img;

	// Determina el umbral T automáticamente
	int k, T = 0;

	while ( k > 0 ){
		T = CalcularNivelGrisMedio(origen);

		// Determina 2 subimágenes I_1, I_2 y calcula sus medias de nivel de gris
		k = -1;
	};

	/* DEBUG */ cout << endl << "Umbral medio en k=0 : " << T << endl;




	/*
	// Umbraliza la imagen
	Imagen resultado(origen);

	for(int i = 0; i < nf; i++)
		for (int j = 0; j < nc; j++)
			if ( resultado.valor_pixel(i,j) <= T )
				resultado.asigna_pixel(i, j, 255);
	*/

	return 0;
};

int CalcularNivelGrisMedio ( const Imagen I ){
	int sum = 0;

	for (int i = 0; i < I.num_filas(); i++)
		for (int j = 0; j < I.num_columnas(); j++)
			sum += I.valor_pixel(i, j);

	return (sum / (I.num_filas() * I.num_columnas() ));
};


