// Implementación del TDA Imagen

#include "imagen.h"
using namespace std;

// Constructor por defecto
Imagen::Imagen(){
	nf = 0;
	nc = 0;
	img = 0;
}

// Constructor de copia
Imagen::Imagen(const Imagen &J){
	nf = J.nf;
	nc = J.nc;

	// Reserva memoria
	img = new unsigned char* [nf];
	for (int i = 0; i < nf; i++)
		img[i] = new unsigned char[nc];

	// Copia los valores
	for (int i = 0; i < nf; i++)
		for (int j = 0; j < nc; j++)
			img[i][j] = J.img[i][j];
}

// Constructor por parámetros
Imagen::Imagen(int fils, int cols){
	nf = fils;
	nc = cols;

	// Reserva memoria
	img = new unsigned char* [nf];
	for (int i = 0; i < nf; i++)
		img[i] = new unsigned char[nc];
}

// Destructor
Imagen::~Imagen(){
	
	for (int i = 0; i < nf; i++)
		delete[] img[i];

	delete[] img;
}

// Consultor num_filas
int Imagen::num_filas() const{
	return nf;
}

// Consultor num_columnas
int Imagen::num_columnas() const{
	return nc;
}

// Asigna un valor a un punto de la matriz
void Imagen::asigna_pixel(int fila, int col, unsigned char valor){
	if (fila < nf && col < nc && valor >= 0 && valor <= 255)
		img[fila][col] = valor;
}

// Consulta el valor de un punto de la matriz
unsigned char Imagen::valor_pixel(int fila, int col) const{
	if (fila < nf && col < nc)
		return img[fila][col];
	else
		return 0;
}

// Operador de asignación
Imagen& Imagen::operator= (const Imagen& _imagen){
	nf = _imagen.nf;
	nc = _imagen.nc;

	// Reserva memoria
	img = new unsigned char* [nf];
	for (int i = 0; i < nf; i++)
		img[i] = new unsigned char[nc];

	// Copia los valores
	for (int i = 0; i < nf; i++)
		for (int j = 0; j < nc; j++)
			img[i][j] = _imagen.img[i][j];

	return *this;
};
