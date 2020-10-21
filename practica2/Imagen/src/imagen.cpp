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
	img = new byte* [nf];
	for (int i = 0; i < nf; i++)
		img[i] = new byte[nc];

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
	img = new byte* [nf];
	for (int i = 0; i < nf; i++)
		img[i] = new byte[nc];
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
void Imagen::asigna_pixel(int fila, int col, byte valor){
	if (fila < nf && fila > 0 && col < nc && col > 0 && valor >= 0 && valor <= 255)
		img[fila][col] = valor;
}

// Consulta el valor de un punto de la matriz
byte Imagen::valor_pixel(int fila, int col) const{
	if (fila < nf && fila > 0 && col < nc && col > 0)
		return img[fila][col];
	else
		return 0;
}

// Operador de asignación
Imagen& Imagen::operator= (const Imagen& _imagen){
	nf = _imagen.nf;
	nc = _imagen.nc;

	// Reserva memoria
	img = new byte* [nf];
	for (int i = 0; i < nf; i++)
		img[i] = new byte[nc];

	// Copia los valores
	for (int i = 0; i < nf; i++)
		for (int j = 0; j < nc; j++)
			img[i][j] = _imagen.img[i][j];

	return *this;
};

// Funciones auxiliares para E/S
template <typename T>
T** ArrayToMatriz (const T* array, int nf, int nc){

	T** matriz;

	// Reserva memoria
	matriz = new T* [nf];
	for (int i = 0; i < nf; i++)
		matriz[i] = new T[nc];

	// Asigna los valores del array en la matriz
	for (int i = 0; i < nf; i++)
		for (int j = 0; j < nc; j++)
			matriz[i][j] = array[i*nc +j];

	return matriz;
}

template<typename T>
T* MatrizToArray (T **matriz, int nf, int nc){

	T *array;

	// Reserva memoria
	array = new T [nf * nc];

	// Asigna los valores de la matriz en el array
	for (int i = 0; i < nf; i++)
		for (int j = 0; j < nc; j++)
			array[i*nc +j] = matriz[i][j];

	return array;
}

// Escribe la imagen en un fichero
void Imagen::EscribirImagen (char* ruta){
	
	byte* img_array;
	img_array = MatrizToArray(img, nf, nc);

	if ( !EscribirImagenPGM(ruta, img_array, nf, nc) ){
		// No se ha podido escribir la imagen
		cerr << "Error: No pudo escribirse la imagen." << endl;
    	cerr << "Terminando la ejecucion del programa." << endl;
    	exit (2);
	};
}

// Lee la imagen desde un fichero
void Imagen::LeerImagen (char* ruta){

	TipoImagen tipo = LeerTipoImagen(ruta);
	byte* img_array;
	switch( tipo ){
		case IMG_PGM:
			img_array = LeerImagenPGM(ruta, nf, nc);
			break;

		case IMG_PPM:
			img_array = LeerImagenPPM(ruta, nf, nc);
			break;
		
		case IMG_DESCONOCIDO:
			cerr << "Error: Formato de imagen no soportado." << endl;
			cerr << "Terminando la ejecucion del programa." << endl;
			exit (2);
	};

	if (!img_array){
		// No se ha podido leer la imagen
		cerr << "Error: No pudo leerse la imagen." << endl;
    	cerr << "Terminando la ejecucion del programa." << endl;
    	exit (2);
	};

	img = ArrayToMatriz(img_array, nf, nc);
}
