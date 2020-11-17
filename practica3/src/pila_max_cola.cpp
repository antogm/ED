#include "cola.h"

template<class T>
Pila_max<T>::Pila_max(){
	num_elem = 0;
};

// Inserta un elemento como nuevo tope de la pila
template<class T>
void Pila_max<T>::poner(T ele){
	if (num_elem == 0)
		maximo = ele;
	else if (ele > maximo)
		maximo = ele;


	if (c1.vacia()){
		c1.poner(ele);
		
	// Si la cola1 contenía elementos:
	}else{
		
		// Vuelca todo su contenido en cola2
		while(!c1.vacia()){
			T x = c1.frente();
			c2.poner(x);
			c1.quitar();
		}

		// Inserta el valor en cola1
		c1.poner(ele);
			
		// Vuelva el contenido de cola2 en cola1
		while(!c2.vacia()){
			T x = c2.frente();
			c1.poner(x);
			c2.quitar();
		}
	}
};

// Quita el elemento del tope de la pila
template<class T>
void Pila_max<T>::quitar(){
	if (num_elem > 0)
		c1.quitar();
};

// Devuelve el elemento del tope de la pila
template<class T>
elemento<T> Pila_max<T>::tope(){
	elemento<T> e;
	e.ele = c1.frente();
	e.maximo = maximo;

	return e;
};

// Devuelve true si la pila no tiene elementos
template<class T>
bool Pila_max<T>::vacia(){
	return num_elem == 0;
};
