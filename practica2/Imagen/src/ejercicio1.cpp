// Fichero: ejercicio1.cpp
// Umbraliza una imagen usando una escala de grises
// Formato:
//    ejercicio1 <FichE> <FichS> <T1> <T2>
//    donde:
//   <FichE> es la imagen PGM que se va a umbralizar. No se modifica.
//   <FichS> es la imagen PGM resultado de umbralizar la imagen de <FichE>.
//	 T1, T2 los valores del intervalo de la umbralización (T_1 < T_2)
//

#include <iostream>
#include <cstdlib>
#include <cstring>
#include "imagen.h"
#include "imagenEs.h"

using namespace std;

Imagen Umbralizar ( const Imagen I, const int T1, const int T2 );

int main (int argc, char* argv[]){
	
	char *fichE, *fichS;
	unsigned char* img;
	int nf, nc;
	
	// Procesa los parámetros recibidos 
	if (argc != 5){
		cerr << "Error: Numero incorrecto de parametros.\n";
		cerr << "Uso: ejercicio1 <FichImagenOriginal> <FichImagenDestino> <T1> <T2>\n";
		exit (1);
	};

	fichE = argv[1],
	fichS = argv[2];
	const int 	T1 = atoi(argv[3]),
				T2 = atoi(argv[4]);

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

	if (T1 > T2){
		cerr << "Error: El parámetro T1 no puede ser mayor que T2" << endl;
		exit (1);
	}

	// Introducir los datos en un objeto del TDA Imagen
	Imagen origen(nf,nc);

	for (int i = 0; i < nf; i++)
		for (int j = 0; j < nc; j++)
			origen.asigna_pixel(i, j, img[i*nc +j]);
		
	// Umbraliza la imagen
	Imagen resultado = Umbralizar(origen, T1, T2);

	// Introduce los datos del TDA Imagen en una matriz para E/S
	for (int i = 0; i < nf; i++)
		for (int j = 0; j < nc; j++)
			img[i*nc +j] = resultado.valor_pixel(i, j);

	// Guardar la imagen resultado en el fichero
  	if (EscribirImagenPGM (fichS, img, nf, nc))
    	cout  << "La imagen se guardo en " << fichS << endl;
  	else{
    	cerr << "Error: No pudo guardarse la imagen." << endl;
    	cerr << "Terminando la ejecucion del programa." << endl;
    	exit (2);
  	}

	return 0;
};

Imagen Umbralizar ( const Imagen I, const int T1, const int T2 ){
	Imagen resultado(I);

	for (int i = 0; i < resultado.num_filas(); i++)
		for (int j = 0; j < resultado.num_columnas(); j++)
			if ( resultado.valor_pixel(i,j) <= T1 || resultado.valor_pixel(i,j) >= T2 )
				resultado.asigna_pixel(i, j, 255);

	return resultado;
};
