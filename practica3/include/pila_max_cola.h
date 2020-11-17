#include "pila_max.h"
#include "cola.h"

template <typename T>
class Pila_max{

	private:
	Cola<T> c1, c2;
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

#include "pila_max_cola.cpp"
