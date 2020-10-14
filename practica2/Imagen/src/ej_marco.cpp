#include "imagen.h"
using namespace std;

void enmarca_imagen (Imagen &I);

int main(){
	
	// Construir la imagen de "nf" filas y "nc" columnas
	Imagen I(20, 20);

	// Crear una imagen plana con valor 255 (blanco)
	for (int i = 0; i < I.num_filas(); i++)
		for (int j = 0; j < I.num_columnas(); j++)
			I.asigna_pixel(i, j, 255);

	// Crea el marco que delimita la imagen
	enmarca_imagen(I);

	return 0;
}

void enmarca_imagen (Imagen &I){
	int f,
	nf = I.num_filas(),
	nc = I.num_columnas();

	for (f = 0; f < nf; f++)		// lado izq
		I.asigna_pixel(f,0,0);

	for (f = 0; f < nf; f++)		// lado dcho
		I.asigna_pixel(f, nc-1, 0);

	for (f = 0; f < nc; f++)	// lado superior
		I.asigna_pixel(0,f,0);

	for (f = 0; f < nc; f++)	// lado inferior
		I.asigna_pixel(nf-1, f, 0);
}
