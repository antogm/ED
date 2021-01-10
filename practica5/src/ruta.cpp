// Implementación del módulo Ruta

#include "Ruta.h"

Ruta::Ruta(){
	codigo = "";
	num_puntos = 0;
};

Ruta::Ruta(string codigo){
	this->codigo = codigo;
	num_puntos = 0;
};

void Ruta::insertarPunto(Punto p){
	num_puntos++;
	puntos.push_back(p);
};

void Ruta::borrarPunto(){
	num_puntos--;
	puntos.pop_back();
};

void Ruta::setCodigo(string c){
	codigo = c;
};

string Ruta::getCodigo() const{
	return codigo;
};

int Ruta::getNumPuntos() const{
	return num_puntos;
};

Punto Ruta::getPunto(int i) const{
	assert(i >= 0 && i < (int) puntos.size());
	return puntos[i];
};

bool Ruta::existePunto(Punto p){
	for (vector<Punto>::const_iterator it = puntos.cbegin(); it != puntos.cend(); ++it){
		if (*it == p)
			return true;
	}

	return false;
};

bool Ruta::operator!=(const Ruta &otro){
	return codigo != otro.codigo;
};

ostream & operator<<(ostream & os, const Ruta &r){
	os << r.codigo << " " << r.num_puntos << " ";
	
	for (Ruta::const_iterator it = r.cbegin(); it != r.cend(); ++it)
		os << *it << " ";

	os << endl;

	return os;
};

istream & operator>>(istream &is, Ruta &r){
	string codigo;
	int num_puntos;
	is >> codigo >> num_puntos;

	Ruta temp(codigo);

	for (int i = 0; i < num_puntos; i++){
		Punto p;
		is >> p;
		temp.insertarPunto(p);
	}

	r = temp;

	return is;
};



// Métodos de la subclase iterator

Ruta::iterator::iterator(){};

Ruta::iterator & Ruta::iterator::operator++(){
	++it;
	return *this;
}

Ruta::iterator & Ruta::iterator::operator--(){
	--it;
	return *this;
}

bool Ruta::iterator::operator==(const iterator &otroit){
	return otroit.it == it;
}

bool Ruta::iterator::operator!=(const iterator &otroit){
	return otroit.it != it;
}

const Punto & Ruta::iterator::operator*()const{
	return *it;
}

Ruta::iterator & Ruta::iterator::operator=(const iterator & otroit){
	it = otroit.it;
	return *this;
}



// Métodos de la subclase const_iterator

Ruta::const_iterator::const_iterator(){}

Ruta::const_iterator::const_iterator(const iterator & otroit){
	it = otroit.it;
}

Ruta::const_iterator & Ruta::const_iterator::operator=(const iterator & otroit){
	it = otroit.it;
	return *this;
}

Ruta::const_iterator & Ruta::const_iterator::operator++(){
	++it;
	return * this;
}

Ruta::const_iterator & Ruta::const_iterator::operator--(){
	--it;
	return * this;
}

bool Ruta::const_iterator::operator==(const const_iterator  & otroit){
	return it == otroit.it;
}

bool Ruta::const_iterator::operator!=(const const_iterator  & otroit){
	return it != otroit.it;
}

const Punto & Ruta::const_iterator::operator*()const {
	return *it;
}



// Métodos de Ruta para iterar sobre ella

Ruta::iterator Ruta::begin(){
	iterator it;
	it.it = puntos.begin();
	return it;
};

Ruta::iterator Ruta::end(){
	iterator it;
	it.it = puntos.end();
	return it;
};

Ruta::const_iterator Ruta::cbegin() const{
	const_iterator it;
	it.it = puntos.cbegin();
	return it;
};

Ruta::const_iterator Ruta::cend() const{
	const_iterator it;
	it.it = puntos.cend();
	return it;
};
