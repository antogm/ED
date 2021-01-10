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
	 * @param p Punto a comprobar.
	 * @return true si el punto forma parte de la ruta, false en otro caso
	 */
	bool operator!=(const Ruta &otro);

	friend ostream & operator<<(ostream & os, const Ruta &r);
	friend istream & operator>>(istream &is, Ruta &r);

	class iterator{
		private:
		vector<Punto>::iterator it;

		public:
		iterator();
	    iterator & operator ++();
	    iterator & operator --();
	    bool operator ==(const iterator  & otroit);
	    bool operator !=(const iterator  & otroit);
		const Punto & operator*() const;
		iterator & operator=(const iterator & otroit);

	    friend class Ruta;
	    friend class const_iterator;
	};

	class const_iterator{
		private:
		vector<Punto>::const_iterator it;

		public:
		const_iterator();
	    const_iterator(const iterator & otroit);
	    const_iterator & operator=(const iterator & otroit);
	    const_iterator & operator ++();
	    const_iterator & operator --();
	    bool operator ==(const const_iterator  & otroit);
	    bool operator !=(const const_iterator  & otroit);
	    const Punto &operator*()const;
		
	    friend class Ruta;
	};

	iterator begin();
	iterator end();
	const_iterator cbegin() const;
	const_iterator cend() const;
};

#endif
