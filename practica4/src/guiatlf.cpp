/**
 * @file guiatlf.cpp
 * @brief Implementación del TDA Guia_Tlf
 */

#include "guiatlf.h"

// Métodos de la clase Guia_Tlf
Guia_Tlf::Guia_Tlf():datos(map<string,string>()){};

Guia_Tlf::Guia_Tlf(const Guia_Tlf & gt){
	for (map<string,string>::const_iterator it = gt.datos.begin(); it != gt.datos.end(); ++it){
		datos.insert(*it);
	}
};

Guia_Tlf::~Guia_Tlf(){
	datos.erase(datos.begin(), datos.end());
};

Guia_Tlf& Guia_Tlf::operator=(const Guia_Tlf &gt){
	if (this != &gt){
		// Borra el contenido actual
		datos.erase(datos.begin(), datos.end());

		// Copia el contenido de gt
		for (map<string,string>::const_iterator it = gt.datos.begin(); it != gt.datos.end(); ++it){
			datos.insert(*it);
		}
	}
	
	return *this;
};

string & Guia_Tlf::operator[](const string &nombre){
	return datos[nombre];
}

string Guia_Tlf::gettelefono(const string & nombre){
	map<string,string>::iterator it = datos.find(nombre);
	if (it == datos.end()) 
		return string("");
	else
		return it->second;
}

pair<map<string,string>::iterator,bool> Guia_Tlf::insert(string nombre, string tlf){
	pair<string,string> p (nombre,tlf);
	pair<map<string,string>::iterator,bool> ret;
	ret = datos.insert(p);
	return ret;     
}

pair<map<string,string>::iterator,bool> Guia_Tlf::insert(pair<string,string> p){    
	pair<map<string,string>::iterator,bool> ret;
	ret = datos.insert(p); 
	return ret;     				
}

void Guia_Tlf::borrar(const string &nombre){
	map<string,string>::iterator itlow = datos.lower_bound(nombre);		//el primero que tiene dicho nombre
	map<string,string>::iterator itupper = datos.upper_bound(nombre);	//el primero que ya no tiene dicho nombre
	datos.erase(itlow,itupper);		//borramos todos aquellos que tiene dicho nombre
}

void Guia_Tlf::borrar(const string &nombre,const string &tlf){
	map<string,string>::iterator itlow = datos.lower_bound(nombre);//el primero que tiene dicho nombre
	map<string,string>::iterator itupper = datos.upper_bound(nombre);//el primero que ya no tiene dicho nombre
	map<string,string>::iterator it;
	bool salir =false;
	for (it=itlow; it!=itupper && !salir;++it){
		if (it->second==tlf){
			datos.erase(it);
			salir =true;
		}
	} 
}

int Guia_Tlf::size()const{
    return datos.size();
}

unsigned int Guia_Tlf::contabiliza(const string &nombre){
    return datos.count(nombre);
}

void Guia_Tlf::clear(){
	datos.clear();
}

Guia_Tlf Guia_Tlf::operator+(const Guia_Tlf & g){
	Guia_Tlf aux(*this);
	map<string,string>::const_iterator it;
	for (it=g.datos.begin();it!=g.datos.end();++it)
		aux.insert(it->first,it->second);

	return aux;
}	

Guia_Tlf Guia_Tlf::operator-(const Guia_Tlf & g){
	Guia_Tlf aux(*this);
	map<string,string>::const_iterator it;
	for (it=g.datos.begin();it!=g.datos.end();++it){
		aux.borrar(it->first,it->second);
	}	  
	return aux;
}

ostream & operator<<(ostream & os, Guia_Tlf & g){
	map<string,string>::iterator it;
	for (it=g.datos.begin(); it!=g.datos.end();++it){
		os<<it->first<<"\t"<<it->second<<endl;
	}

	return os;
}

istream& operator>>(istream &is, Guia_Tlf &g){
	pair<string,string> p;
	Guia_Tlf aux;

	while (is>>p){
		aux.insert(p);
	}
	g=aux;
	
	return is;
}



// Funciones extra
bool Guia_Tlf::actualizarNumero(string nombre, string nuevo_numero){
	map<string,string>::iterator it = datos.find(nombre);

	if (it == datos.end())
		return false;
	else{
		borrar(nombre);
		insert(nombre, nuevo_numero);
		return true;
	}
};

bool Guia_Tlf::vacia(){
	return datos.empty();
}

string Guia_Tlf::propietario(string numero){
	for (Iterator it = begin(); it != end(); ++it){
		if ( (*it).second == numero ){
			return (*it).first;
		}
	}

	return "no encontrado";
};



// Métodos de la clase Guia_Tlf::Iterator
Guia_Tlf::Iterator::Iterator(){};

Guia_Tlf::Iterator::Iterator(const map<string,string>::iterator &it2){
	it = it2;
};

pair<string,string> Guia_Tlf::Iterator::operator*() const{
	return (*it);
};

Guia_Tlf::Iterator& Guia_Tlf::Iterator::operator++(){
	++it;
	return *this;
};

Guia_Tlf::Iterator& Guia_Tlf::Iterator::operator--(){
	--it;
	return *this;
};

bool Guia_Tlf::Iterator::operator!=(const Iterator &otro){
	return it != otro.it;
};

bool Guia_Tlf::Iterator::operator==(const Iterator &otro){
	return it == otro.it;
};

Guia_Tlf::Iterator& Guia_Tlf::Iterator::operator=(const Guia_Tlf::Iterator &otro){
	it = otro.it;
	return *this;
};



// Métodos de la clase Guia_Tlf::ConstIterator
Guia_Tlf::ConstIterator::ConstIterator(){};

Guia_Tlf::ConstIterator::ConstIterator(const map<string,string>::const_iterator &it2){
	it = it2;
};

Guia_Tlf::ConstIterator& Guia_Tlf::ConstIterator::operator++(){
	++it;
	return *this;
};

bool Guia_Tlf::ConstIterator::operator!=(const Guia_Tlf::ConstIterator &it2){
	return it != it2.it;
};

bool Guia_Tlf::ConstIterator::operator==(const Guia_Tlf::ConstIterator &otro){
	return it == otro.it;
};

pair<string,string> Guia_Tlf::ConstIterator::operator*() const{
	return (*it);
};

Guia_Tlf::ConstIterator& Guia_Tlf::ConstIterator::operator=(const Guia_Tlf::ConstIterator &otro){
	it = otro.it;
	return *this;
};



// Métodos para iterar sobre la clase Guia_Tlf:
Guia_Tlf::Iterator Guia_Tlf::begin(){
	return Iterator(datos.begin());
};

Guia_Tlf::Iterator Guia_Tlf::end(){
	return Iterator(datos.end());
};

Guia_Tlf::ConstIterator Guia_Tlf::cbegin(){
	return ConstIterator(datos.cbegin());
};

Guia_Tlf::ConstIterator Guia_Tlf::cend(){
	return ConstIterator(datos.cend());
};


