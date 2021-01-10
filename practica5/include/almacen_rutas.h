#include "Ruta.h"
#include <map>
#include <vector>

using namespace std;

class Almacen_Rutas{
	private:
	map<string,Ruta,less<string>> rutas;

	public:

	/**
	* @brief Inserta una ruta en el almacen de rutas.
	* @param ruta Ruta
	*/
	void InsertarRuta(const Ruta &r);
	/**
	* @brief Constructor con código de la ruta como parámetros.
	* @param code Código de la ruta
	* @return Ruta seleccionada
	*/
	Ruta GetRuta(string code);
	/**
	* @brief Busqueda de rutas que incorporen el punto actual en ellas.
	* @param p Punto como búsqueda.
	* @return Contenedor Almacen_Rutas con las rutas que contienen ese punto.
	*/
	Almacen_Rutas GetRutas_Con_Punto(Punto p);
	/**
	* @brief Iguala un contenedor de Almacen_rutas con otro pasado por parámetro.
	* @param otro Segundo contenedor Almacen_Rutas.
	* @return Almacen_Rutas actual
	*/
	Almacen_Rutas& operator=(const Almacen_Rutas &otro);
	/**
	* @brief Imprime las rutas que contiene el almacen de rutas.
	* @param os Flujo de salida
	* @param r Almacend de rutas.
	* @return Flujo de salida.
	*/
	friend ostream & operator<<(ostream & os, const Almacen_Rutas &r);
	/**
	* @brief Inserta rutas en el almacen de rutas leidas por fichero.
	* @param is Flujo de entrada
	* @param r Almacend de rutas.
	* @return Flujo de entrada.
	*/
	friend istream & operator>>(istream &is, Almacen_Rutas &r);

	class iterator{
		private:
		map<string,Ruta,less<string>>::iterator it;

		public:
		iterator(){}

	    iterator & operator ++(){
			++it;
			return *this;
	    }

	    iterator & operator --(){
			--it;
			return *this;
	    }

	    bool operator ==(const iterator  & otroit){
			return otroit.it == it;
	    }

	    bool operator !=(const iterator  & otroit){
			return otroit.it != it;
		}

		const Ruta & operator*() const{
			return (*it).second;
	    }

	    friend class Almacen_Rutas;
	    friend class const_iterator;
	};

	class const_iterator{
		private:
		map<string,Ruta,less<string>>::const_iterator it;

		public:
	    const_iterator(){}

	    const_iterator(const iterator & otroit){
	      it = otroit.it;
	    }

	    const_iterator & operator=(const iterator & otroit){
			it = otroit.it;
			return *this;
	    }

	    const_iterator & operator ++(){
			++it;
			return * this;
	    }
	    
	    const_iterator & operator --(){
			--it;
			return * this;
	    }

	    bool operator ==(const const_iterator  & otroit){
			return otroit.it == it;
	    }

	    bool operator !=(const const_iterator  & otroit){
			return otroit.it != it;
	    }

	    const Ruta &operator*()const {
		  return (*it).second;
	    }

	    friend class Almacen_Rutas;
	};

	iterator begin();
	iterator end();
	const_iterator cbegin() const;
	const_iterator cend() const;
};
