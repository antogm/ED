#include "Punto.h"

Punto::Punto(){}

Punto::Punto(double _x, double _y){
	x = _x;
	y = _y;
	nombre = "";
}

Punto::Punto(double _x, double _y, string _nombre){
	x = _x;
	y = _y;
	nombre = _nombre;
}

void Punto::setX(double _x){
	x = _x;
}

void Punto::setY(double _y){
	y = _y;
}

void Punto::setNombre(string _nombre){
	nombre = _nombre;
}

string Punto::getNombre(){
	return nombre;
}

double Punto::GetLongitud() const{
	return x;
}

double Punto::GetLatitud() const{
	return y;
}

bool Punto::operator<(const Punto &otro){
	if (x != otro.x)
		return x < otro.x;
	else
		return y < otro.y;
};

bool Punto::operator==(const Punto &otro) const{
	return (abs(x-otro.x) <= 1e-5 && abs(y-otro.y) <= 1e-5);
};

ostream & operator<<(ostream & os, const Punto &p){
	os << "(" << p.x << "," << p.y << ")";
	return os;
};

istream & operator>>(istream &is, Punto &p){
	string linea;
	getline(is, linea, ')');
	linea.erase(1,1); 							// quita el primer paréntesis

	int pos_coma = linea.find(',');

	double x, y;
	x = stod( linea.substr(0, pos_coma-1) );	// extrae la primera coordenada
	linea.erase(0, pos_coma+1);					// borra del string la primera coordenada y la coma
	y = stod(linea);							// extrae la segunda coordenada

	p = Punto(x,y,"");

	return is;
};
