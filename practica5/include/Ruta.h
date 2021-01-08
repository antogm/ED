// Fichero cabecera del módulo Ruta

#ifndef ruta_h
#define ruta_h

#include <vector>
#include <assert.h>
#include "punto.h"
using namespace std;

class Ruta{
	private:
	string codigo;
	int num_puntos;
	vector<Punto> puntos;

	public:
	/**
	 * @brief Constructor por defecto
	 */
	Ruta();

	/**
	 * @brief Constructor con el código de la ruta como parámetro
	 */
	Ruta(string codigo);

	/**
	 * @brief Inserta un nuevo Punto al final de la ruta
	 */
	void insertarPunto(Punto p);

	/**
	 * @brief Borra el último Punto añadido a la ruta
	 */
	void borrarPunto();

	/**
	 * @brief Cambia el código de la ruta
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
	 * @brief Consultor para los puntos de la ruta
	 * @return punto correspondiente a la posición i
	 */
	Punto getPunto(int i) const;

	/**
	 * @brief Comprueba si el punto pasado como parámetor forma parte de la ruta
	 * @return true si el punto forma parte de la ruta, false en otro caso
	 */
	bool existePunto(Punto p);

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
