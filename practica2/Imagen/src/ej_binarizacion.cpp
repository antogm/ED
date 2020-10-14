#include "imagen.h"
using namespace std;

int main(){

	int f,c;
	Imagen I(20,20);
	int t = 100;	// Valor umbral

	// Binarizacion de la imagen i
	for (f = 0; f < I.num_filas(); f++ )
		for (c = 0; c < I.num_columnas(); c++)
			if (I.valor_pixel(f,c) <= t)
				I.asigna_pixel(f,c,0);
			else
				I.asigna_pixel(f,c,255);

	return 0;
}