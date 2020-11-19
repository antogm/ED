/**
  * @file pila_max_vd.h
  * @brief Fichero cabecera del módulo Pila_max_vd del TDA Pila_max 
  *
  * Gestiona una secuencia de elementos con facilidades para la inserción y borrado de elementos en el mismo extremo
  */

#include <cassert>
#include <vector>
using namespace std;

#define N 10	// Será el número de celdas del vector que se reserven en cada resize
				// Está hecho así para no tener que hacer resize en cada inserción

template <typename T>
struct elemento{
	T ele;
	T maximo;
};

template<typename T>
class Pila_max{

	private:
	vector<T> v;			// Contenedor en el que se almacenarán los elementos
	T maximo;				// Valor máximo que se ha introducido en la pila
	unsigned num_elem;		// Número de elementos contenidos en la pila

	public:
	/**
     * @brief Constructor por defecto
     */
	Pila_max();

	/**
     * @brief Añade un elemento al tope de la pila
     * @param elem Elemento que se va a añadir
     */
	void poner(T ele);

	/**
     * @brief Quita el elemento del tope de la cola
     */
	void quitar();

	/**
     * @brief Devuelve el elemento del tope de la cola
     */
	elemento<T> tope();

	/**
     * @brief Comprueba si la pila está vacía
	 * @return true si la pila no contiene elementos
     */
	bool vacia();
};

#include "pila_max_vd.cpp"
