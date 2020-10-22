// Fichero: pruebaImagen.cpp
// Este programa implementa y ejecuta todos los ejercicios de la práctica

#include <iostream>
#include <math.h>
#include <vector>
#include "imagen.h"

using namespace std;

Imagen ej1_umbralizacion(const Imagen imagenE, const int T1, const int T2);
Imagen ej3_zoom(const Imagen imagenE);
Imagen ej4_icono(const Imagen original, const int nf, const int nc);
Imagen ej5_contraste(const Imagen imagenE, const int min, const int max);


int main (int argc, char* argv[]){
	
	Imagen vacas, llaves;
	vacas.LeerImagen((char *)"imagenes/vacas.pgm");
	llaves.LeerImagen((char *)"imagenes/llaves.pgm");

	Imagen imagen1 = ej1_umbralizacion(vacas, 50, 200);
	Imagen imagen3 = ej3_zoom(vacas);
	Imagen imagen4 = ej4_icono(vacas, 84, 125);
	Imagen imagen5 = ej5_contraste(llaves, 3, 250);

	imagen1.EscribirImagen((char *) "ej1.pgm");
	imagen3.EscribirImagen((char *) "ej3.pgm");
	imagen4.EscribirImagen((char *) "ej4.pgm");
	imagen5.EscribirImagen((char *) "ej5.pgm");

	return 0;
};


//
//	Implementación de los ejercicios
//

Imagen ej1_umbralizacion(const Imagen imagenE, const int T1, const int T2){
	if (T1 > T2){
		cerr << "Error: El parámetro T1 no puede ser mayor que T2" << endl;
		exit (1);
	};

	// Crea la imagen a devolver como copia de la recibida
	Imagen imagenS(imagenE);

	// Umbraliza la imagen
	for (int i = 0; i < imagenS.num_filas(); i++)
		for (int j = 0; j < imagenS.num_columnas(); j++)
			if ( imagenS.valor_pixel(i,j) <= T1 || imagenS.valor_pixel(i,j) >= T2 )
				imagenS.asigna_pixel(i, j, 255);
	
	return imagenS;
};

Imagen ej3_zoom(const Imagen imagenE){
	
	// Comprueba que la imagen sea apta
	const int N = imagenE.num_filas();

	if (N != imagenE.num_columnas()){
		cerr << "Error: Esta función solo permite hacer zoom a imágenes cuadradas" << endl;		// <-- lo pone en el enunciado del ejercicio
		exit (1);
	};

	// Crea una nueva imagen con las dimensiones que tendrá al hacerle zoom
	Imagen imagenS(2*N -1, 2*N -1);

	// Inserta la imagen original en las posiciones que le corresponden de la nueva imagen
	for (int i = 0; i < N; i ++)
		for (int j = 0; j < N; j ++)
			imagenS.asigna_pixel( 2*i, 2*j, imagenE.valor_pixel(i, j) );
	
	// Interpola las columnas vacías de la imagen resultado
	for (int i = 0; i < (2*N -1); i++)					// Recorre todas las filas
		for (int j = 1; j < (2*N -2); j += 2){			// Recorre las columnas impares (son las nuevas que estan vacías)
			
			// Si es una columna impar es una columna a interpolar
			int valor1 = imagenS.valor_pixel(i, j-1),
				valor2 = imagenS.valor_pixel(i, j+1),
				media = (valor1 + valor2) / 2;
				
			imagenS.asigna_pixel(i, j, media);
		}
	
	// Interpola las filas vacías de la imagen resultado
	for (int i = 1; i < (2*N -2); i += 2)				// Recorre las filas impares (son las nuevas que estan vacías)
		for (int j = 0; j < (2*N -1); j++){				// Recorre todas las columnas

			// Si es una columna impar es una columna a interpolar
				int valor1 = imagenS.valor_pixel(i-1, j),
					valor2 = imagenS.valor_pixel(i+1, j),
					media = (valor1 + valor2) / 2;

				imagenS.asigna_pixel(i, j, media);
		}

	return imagenS;
};


Imagen ej4_icono(const Imagen original, const int nf, const int nc){

	int f_reducida = nf;
	int c_reducida = nc;

	// Crea la nueva imagen con el tamaño indicado a partir de la original:
	Imagen reducida(f_reducida, c_reducida);
	Imagen ajustadoAnchura(original.num_filas(), c_reducida);

	// Creación de arrays de filas y columnas auxiliares:
	unsigned char array_filas[f_reducida];
	unsigned char array_columnas[c_reducida];

	for(int i=0; i<f_reducida; i++){	array_filas[i] = 0;	}
	for(int i=0; i<c_reducida; i++){	array_columnas[i] = 0;	}

	// Reparto de píxeles original->reducida (filas):
	int posicion;
	for(int i=0; i<original.num_filas(); i++){
		posicion = i%f_reducida;
		array_filas[posicion] += 1;
	}
	// Reparto de píxeles original->reducida (columnas):
	for(int i=0; i<original.num_columnas(); i++){
		posicion = i%c_reducida;
		array_columnas[posicion] += 1;
	}

	// Reducción en anchura:
	int checkpoint = 0;
	int sumatoria = 0;
	int AVG = 0;

	for(int subconjunto=0; subconjunto<c_reducida; subconjunto++){
		for(int fila=0; fila<original.num_filas(); fila++){
			for(int columna=checkpoint; columna < array_columnas[subconjunto]+checkpoint; columna++){
				sumatoria += original.valor_pixel(fila, columna);
			}
			AVG = sumatoria / array_columnas[subconjunto]; 
			ajustadoAnchura.asigna_pixel(fila, subconjunto, AVG);
			AVG = 0;
			sumatoria = 0;
		}
		checkpoint+=array_columnas[subconjunto];
	}
	
	checkpoint = 0;
	sumatoria = 0;
	AVG = 0;

	for(int subconjunto=0; subconjunto<f_reducida; subconjunto++){
		for(int columna=0; columna<c_reducida; columna++){
			for(int fila=checkpoint; fila < array_filas[subconjunto]+checkpoint; fila++){
				sumatoria += ajustadoAnchura.valor_pixel(fila, columna);
			}
			AVG = sumatoria / array_filas[subconjunto]; 
			reducida.asigna_pixel(subconjunto, columna, AVG);
			AVG = 0;
			sumatoria = 0;
		}
		checkpoint+=array_filas[subconjunto];
	}

	return reducida;
}


Imagen ej5_contraste(const Imagen imagen, const int min, const int max){
	// Fórmula a aplicar a cada píxel -> t(z) = z' = min + [((max-min) / (b-a)) * (z-a)];

	// Crea una nueva imagen a partir de las dimensiones de la imagen recibida
	Imagen contrastada(imagen.num_filas(), imagen.num_columnas());

	// Obtener los valores límite de la imagen de entrada (Podemos hacer una función independiente):
	float a,b;

	for(int i=0; i<imagen.num_filas(); i++){
		for(int j=0; j<imagen.num_columnas(); j++){
			if(i == 0 && j == 0){
				b = imagen.valor_pixel(i,j);
				a = imagen.valor_pixel(i,j);
			}else{
				if(imagen.valor_pixel(i,j) > b){	b = imagen.valor_pixel(i,j);	}
				if(imagen.valor_pixel(i,j) < a){	a = imagen.valor_pixel(i,j);	}
			}
		}
	}

	// Definir la parte constante:
	float constante = ((max-min)/(b-a));

	// Contrastando la imagen:
	for(int i=0; i<imagen.num_filas(); i++){
		for(int j=0; j<imagen.num_columnas(); j++){
			float valor_float = min+(constante*(imagen.valor_pixel(i,j)-a));
			int valor_redondeado = round(valor_float);
			unsigned char valor_casted = (int)valor_redondeado;
			contrastada.asigna_pixel(i,j, valor_casted);
		}
	}

	return contrastada;
}
