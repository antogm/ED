#include "Ruta.h"
#include <map>
#include <vector>

using namespace std;

class Almacen_Rutas{
	private:
	map<string,Ruta,less<string>> rutas;

	public:
	void InsertarRuta(const Ruta &r);
	Ruta GetRuta(string code);
	Almacen_Rutas GetRutas_Con_Punto(Punto p);
	Almacen_Rutas& operator=(const Almacen_Rutas &otro);

	friend ostream & operator<<(ostream & os, const Almacen_Rutas &r);
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
