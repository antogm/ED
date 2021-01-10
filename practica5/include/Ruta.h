// Fichero cabecera del módulo Ruta

#ifndef ruta_h
#define ruta_h

#include <vector>
#include <assert.h>
#include "Punto.h"
using namespace std;

class Ruta{
	private:
	string codigo;
	int num_puntos;
	vector<Punto> puntos;

	public:
	/**
	* @brief Constructor de la clase Ruta por defecto.
	*/
	Ruta();

	/**
	* @brief Constructor con código de la ruta como parámetros.
	* @param codigo Cadena de código de entrada.
	*/
	Ruta(string codigo);

	/**
	* @brief Inserta un nuevo punto al final de la ruta.
	* @param p Punto a insertar.
	*/
	void insertarPunto(Punto p);

	/**
	* @brief Borra el último punto añadido a la ruta.
	*/
	void borrarPunto();

	/**
	* @brief Cambia el código de la ruta.
	* @param c Cadena con el nuevo código.
	*/
	void setCodigo(string c);

	/**
	 * @brief Consultor para el código
	 * @return Código de la ruta (string)
	 */
	string getCodigo() const;

	/**
	 * @brief Consultor para el número de puntos que tiene la ruta
	 * @return Número de puntos que tiene la lista (int)
	 */
	int getNumPuntos() const;

	/**
	 * @brief Consultor para los puntos de la ruta.
	 * @param i Posición de búsqueda.
	 * @return punto correspondiente a la posición i
	 */
	Punto getPunto(int i) const;

	/**
	 * @brief Comprueba si el punto pasado como parámetro forma parte de la ruta
	 * @param p Punto a comprobar.
	 * @return true si el punto forma parte de la ruta, false en otro caso
	 */
	bool existePunto(Punto p);

	/**
	 * @brief Comprueba si una ruta no es igual que otra pasada por parámetro.
	 * @param otro Otra ruta.
	 * @return True si no son la misma ruta, false si lo son.
	 */
	bool operator!=(const Ruta &otro);

	/**
	 * @brief Imprime por pantalla la ruta especificada.
	 * @param os Salida por pantalla
	 * @param r Ruta
	 * @return Salida estandar
	 */
	friend ostream & operator<<(ostream & os, const Ruta &r);

	/**
	 * @brief Lee de fichero la información de puntos y rutas y crea una nueva ruta con ellos.
	 * @param is Entrada de flujo de datos (fichero)
	 * @param r Ruta
	 * @return Entrada de flujo de datos
	 */
	friend istream & operator>>(istream &is, Ruta &r);

	class iterator{
		private:
		vector<Punto>::iterator it;

		public:
		/**
		 * @brief Constructor por defecto de la subclase iterator.
		 */
		iterator();
		/**
		 * @brief Operador de incremento de posición del iterador.
		 * @return Iterador al siguiente elemento
		 */
	    iterator & operator ++();
		/**
		 * @brief Operador de decremento de posición del iterador.
		 * @return Iterador al anterior elemento
		 */
	    iterator & operator --();
		/**
		 * @brief Comprueba si dos iteradores son iguales
		 * @param otrit Otro iterador para comparar.
		 * @return True -> Lo son, False -> No lo son.
		 */
	    bool operator ==(const iterator  & otroit);
		/**
		 * @brief Comprueba si dos iteradores son distintos
		 * @param otrit Otro iterador para comparar.
		 * @return False -> Lo son, True -> No lo son.
		 */
	    bool operator !=(const iterator  & otroit);
		/**
		 * @brief Desreferencia un iterador
		 * @return Valor al que hace referencia el iterador actual.
		 */
		const Punto & operator*() const;
		/**
		 * @brief Iguala dos iteradores
		 * @param otrit Otro iterador para igualar.
		 * @return Iterador actual
		 */
		iterator & operator=(const iterator & otroit);

	    friend class Ruta;
	    friend class const_iterator;
	};

	class const_iterator{
		private:
		vector<Punto>::const_iterator it;

		public:
		/**
		 * @brief Constructor por defecto de la subclase const_iterator.
		 */
		const_iterator();
		/**
		 * @brief Constructor por parámetros de copia.
		 */
	    const_iterator(const iterator & otroit);
		/**
		 * @brief Comprueba si dos iteradores son iguales
		 * @param otrit Otro iterador para comparar.
		 * @return True -> Lo son, False -> No lo son.
		 */
	    const_iterator & operator=(const iterator & otroit);
		/**
		 * @brief Operador de incremento de posición del iterador.
		 * @return Iterador al siguiente elemento
		 */
	    const_iterator & operator ++();
		/**
		 * @brief Operador de decremento de posición del iterador.
		 * @return Iterador al anterior elemento
		 */
	    const_iterator & operator --();
		/**
		 * @brief Comprueba si dos iteradores son iguales
		 * @param otrit Otro iterador para comparar.
		 * @return True -> Lo son, False -> No lo son.
		 */
	    bool operator ==(const const_iterator  & otroit);
		/**
		 * @brief Comprueba si dos iteradores son distintos
		 * @param otrit Otro iterador para comparar.
		 * @return False -> Lo son, True -> No lo son.
		 */
	    bool operator !=(const const_iterator  & otroit);
		/**
		 * @brief Desreferencia un iterador
		 * @return Valor al que hace referencia el iterador actual.
		 */
	    const Punto &operator*()const;
		
	    friend class Ruta;
	};

	/**
	 * @brief Iterador al inicio de la ruta.
	 * @return Iterador al primero punto de la ruta.
	 */
	iterator begin();
	/**
	 * @brief Iterador al final de la ruta.
	 * @return Iterador al punto final de la ruta.
	 */
	iterator end();
	/**
	 * @brief Iterador constante al inicio de la ruta.
	 * @return Iterador constante al primero punto de la ruta.
	 */
	const_iterator cbegin() const;
	/**
	 * @brief Iterador constante al final de la ruta.
	 * @return Iterador constante al punto final de la ruta.
	 */
	const_iterator cend() const;
};

#endif
