/**
* @file pila_max_cola.h
* @brief Fichero de cabecera del TDA Pila_max_cola
* 
* Gestiona el almacenamiento de una serie de elementos en una pila y 
* siendo implementado a través de una cola.
*/

#include "cola.h"

/**
 * @brief T.D.A Pila_max_Cola
 * 
 * Módulo que implementa una pila (con máximo) basándose en una cola con templates que se suministra.
 * 
 * @author Antonio González Maldonado y José Alberto Rodríguez Godoy
 * @date Noviembre 2020
*/

using namespace std;

template <typename T>
struct elemento{
	T ele;
	T maximo;	
};

template <typename T>
class Pila_max{

	private:
	Cola<T> c1, c2;
	T maximo;
	unsigned num_elem;		//<- Cantidad de elementos de la pila.

	public:

	/**
	 * @brief Constructor por defecto de la pila basada en una cola.
	*/
	Pila_max();

	/**
	 * @brief Método que inserta elemento como nuevo tope en la pila (TOP SETTER).
	 * @param ele Elemento que se pretende insertar
	*/
	void poner(T ele);

	/**
	 * @brief Método que elimina el elemento tope de la pila.
	*/
	void quitar();

	/**
	 * @brief Metodo por el que se obtiene el elemento tope de la pila (TOP GETTER).
	 * @return El elemento tope actual de la pila.
	*/
	elemento<T> tope();

	/**
	 * @brief Comprobar si la pila no tiene elementos.
	 * @return true -> vacia | fasle -> llena
	*/
	bool vacia();
};

#include "pila_max_cola.cpp"
