#include <cassert>
#include <vector>
#include "pila_max.h"

#define N 10	// Será el número de celdas del vector que se reserven en cada resize
				// Está hecho así para no tener que hacer resize en cada inserción

template<typename T>
class Pila_max{

	private:
	vector<T> v;
	T maximo;
	unsigned num_elem;

	public:
	Pila_max();

	// Inserta un elemento como nuevo tope de la pila
	void poner(T ele);

	// Quita el elemento del tope de la pila
	void quitar();

	// Devuelve el elemento del tope de la pila
	elemento<T> tope();

	// Devuelve true si la pila no tiene elementos
	bool vacia();
};

#include "pila_max_vd.cpp"
