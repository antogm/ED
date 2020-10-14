// Implementación del TDA Imagen

#include "imagen.h"
using namespace std;

// Constructor por defecto
Imagen::Imagen(){
	nf = 0;
	nc = 0;
	npixeles = 0;
	img = 0;
}

// Constructor de copia
Imagen::Imagen(const Imagen &J){
	nf = J.nf;
	nc = J.nc;
	npixeles = J.npixeles;

	// Reserva memoria
	img = new unsigned char [nf * nc];

	// Copia los valores
	for (int i = 0; i < npixeles; i++)
		img[i] = J.img[i];
}

// Constructor por parámetros
Imagen::Imagen(int fils, int cols){
	nf = fils;
	nc = cols;
	npixeles = nf * nc;

	// Reserva memoria
	img = new unsigned char [nf * nc];
}

// Destructor
Imagen::~Imagen(){
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
		img[fila*nc + col] = valor;
}

// Consulta el valor de un punto de la matriz
unsigned char Imagen::valor_pixel(int fila, int col) const{
	if (fila < nf && col < nc)
		return img[fila*nc +col];
	else
		return 0;
}

// Operador de asignación
Imagen& Imagen::operator= (const Imagen& _imagen){
	nf = _imagen.nf;
	nc = _imagen.nc;
	npixeles = _imagen.npixeles;

	// Reserva memoria
	img = new unsigned char [nf * nc];

	// Copia los valores
	for (int i = 0; i < npixeles; i++)
		img[i] = _imagen.img[i];

	return *this;
};

// Escribe la imagen en un fichero
void Imagen::EscribirImagen (char* ruta){
	
	if ( !EscribirImagenPGM(ruta, img, nf, nc) ){
		// No se ha podido escribir la imagen
		cerr << "Error: No pudo escribirse la imagen." << endl;
    	cerr << "Terminando la ejecucion del programa." << endl;
    	exit (2);
	};
}

// Lee la imagen desde un fichero
void Imagen::LeerImagen (char* ruta){

	TipoImagen tipo = LeerTipoImagen(ruta);
	switch( tipo ){
		case IMG_PGM:
			img = LeerImagenPGM(ruta, nf, nc);
			break;

		case IMG_PPM:
			img = LeerImagenPPM(ruta, nf, nc);
			break;
	};

	if (!img){
		// No se ha podido leer la imagen
		cerr << "Error: No pudo leerse la imagen." << endl;
    	cerr << "Terminando la ejecucion del programa." << endl;
    	exit (2);
	};

	npixeles = nf * nc;
}
