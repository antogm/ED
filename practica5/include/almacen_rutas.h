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
	void InsertarRuta(const Ruta &r){
		rutas.emplace( r.getCodigo(), r);
	};

	/**
	* @brief Constructor con código de la ruta como parámetros.
	* @param code Código de la ruta
	* @return Ruta seleccionada
	*/
	Ruta GetRuta(string code){
		return rutas.at(code);
	};

	/**
	* @brief Busqueda de rutas que incorporen el punto actual en ellas.
	* @param p Punto como búsqueda.
	* @return Contenedor Almacen_Rutas con las rutas que contienen ese punto.
	*/
	Almacen_Rutas GetRutas_Con_Punto(Punto p){
		Almacen_Rutas rutas_con_p;

		for (map<string,Ruta,less<string>>::iterator it = rutas.begin(); it != rutas.end(); ++it){
			if ( (*it).second.existePunto(p))
				rutas_con_p.InsertarRuta( (*it).second );
		}

		return rutas_con_p;
	};

	/**
	* @brief Iguala un contenedor de Almacen_rutas con otro pasado por parámetro.
	* @param otro Segundo contenedor Almacen_Rutas.
	* @return Almacen_Rutas actual
	*/
	Almacen_Rutas& operator=(const Almacen_Rutas &otro){
		rutas = otro.rutas;
		return *this;
	};

	/**
	* @brief Imprime las rutas que contiene el almacen de rutas.
	* @param os Flujo de salida
	* @param r Almacend de rutas.
	* @return Flujo de salida.
	*/
	friend ostream & operator<<(ostream & os, const Almacen_Rutas &r){
		for (map<string,Ruta,less<string>>::const_iterator it = r.rutas.cbegin(); it != r.rutas.cend(); ++it)
			os << (*it).second << endl;

		return os;
	};

	/**
	* @brief Inserta rutas en el almacen de rutas leidas por fichero.
	* @param is Flujo de entrada
	* @param r Almacend de rutas.
	* @return Flujo de entrada.
	*/
	friend istream & operator>>(istream &is, Almacen_Rutas &r){
		Almacen_Rutas rlocal;
	
		//leemos el comentario
		if (is.peek() == '#'){
			string a;
			getline(is,a);
		}	
		
		Ruta ruta;
			
		while (is >> ruta){
			rlocal.InsertarRuta(ruta);
			ruta = Ruta();
		}

		r = rlocal;
		
		return is;
	};

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

	iterator begin(){
		iterator it;
		it.it = rutas.begin();
		return it;
	};

	iterator end(){
		iterator it;
		it.it = rutas.end();
		return it;
	};

	const_iterator cbegin() const{
		const_iterator it;
		it.it = rutas.cbegin();
		return it;
	};

	const_iterator cend() const{
		const_iterator it;
		it.it = rutas.cend();
		return it;
	};
};
