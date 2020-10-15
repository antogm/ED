// Fichero: pruebaImagen.cpp
// Este programa implementa y ejecuta todos los ejercicios de la práctica

#include <iostream>
#include "imagen.h"

using namespace std;

Imagen ej1_umbralizacion(char* fichE, char* fichS, const int T1, const int T2);
//Imagen ej3_zoom(char* fichE, char* fichS, int, int, int, int);

//Imagen ej4_icono(char* fich_orig, char* fich_rdo, const int nf, const int nc);
Imagen ej5_contrate(char* fichE, char* fichS, const int min, const int max);


int main (int argc, char* argv[]){
	
	Imagen imagen1 = ej1_umbralizacion((char *) "imagenes/vacas.pgm", (char *) "ej1.pgm", 50, 200);
	//Imagen imagen3 = ej3_zoom((char *) "imagenes/vacas.pgm", (char *) "ej3.pgm", 100, 100, 200, 200);

	//Imagen imagen4 = ej4_icono((char *) "imagenes/vacas.pgm", (char *) "ej4.pgm", 84, 125);
	Imagen imagen5 = ej5_contrate((char*) "imagenes/celulas.pgm", (char*) "ej5.pgm", 3, 250);

	return 0;
};




Imagen ej1_umbralizacion(char* fichE, char* fichS, const int T1, const int T2){
	if (T1 > T2){
		cerr << "Error: El parámetro T1 no puede ser mayor que T2" << endl;
		exit (1);
	};
	
	// Construye la imagen desde el fichero
	Imagen imagen;
	imagen.LeerImagen(fichE);

	// Umbraliza la imagen
	for (int i = 0; i < imagen.num_filas(); i++)
		for (int j = 0; j < imagen.num_columnas(); j++)
			if ( imagen.valor_pixel(i,j) <= T1 || imagen.valor_pixel(i,j) >= T2 )
				imagen.asigna_pixel(i, j, 255);

	// Guarda el resultado en un fichero
	imagen.EscribirImagen(fichS);
	return imagen;
};

/*
Imagen ej4_icono(char* fich_orig, char* fich_rdo, const int nf, const int nc){

	// Como precondición no se puede pasar la resolución de la imagen resultante que no sea
	// simplificación de la resolución de la imagen original (10/10 = 5/5 Bien, 10/10 != 5/4 Mal).

	
}
*/

Imagen ej5_contrate(char* fichE, char* fichS, const int min, const int max){
	// Fórmula a aplicar a cada píxel -> t(z) = z' = min + [((max-min) / (b-a)) * (z-a)];
	// min, max = Niveles límite de la nueva imagen de salida.
	// z = pixel actual.
	// Parte constante (calcular de forma independiente una única vez) = [(max-min) / (b-a)]

	// Construir una imagen desde fichero:
	Imagen imagen;
	imagen.LeerImagen(fichE);

	// Obtener los valores límite de la imagen de entrada (Podemos hacer una función independiente):
	int a = 256;
	int b = 0;
	for(int i=0; i<imagen.num_filas(); i++){
		for(int j=0; j<imagen.num_columnas(); i++){	// Necesario poner dos if ya que se pueden cumplir las dos condiciones.
			if(imagen.valor_pixel(i,j)<a){
				a = imagen.valor_pixel(i,j);
			}
			if(imagen.valor_pixel(i,j)>b){	
				b = imagen.valor_pixel(i,j);
			}
		}
	}

	// Definir la parte constante:
	int constante = ((max-min)/(b-a));

	// Contrastando la imagen:
	for(int i=0; i<imagen.num_filas(); i++){
		for(int j=0; j<imagen.num_columnas(); j++){
			imagen.asigna_pixel(i,j,(min+(constante*(imagen.valor_pixel(i,j)-a))));
		}
	}

	// Guardar el resultado en un fichero:
	imagen.EscribirImagen(fichS);
	return imagen;
}
