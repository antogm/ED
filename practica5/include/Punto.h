#ifndef punto_h
#define punto_h

#include <string>
#include <iostream>
#include <cmath>
using namespace std;

class Punto{
	private:
	double x, y;
	string nombre;

	public:
	Punto();
	Punto(double _x, double _y);
	Punto(double _x, double _y, string _nombre);
	void setX(double _x);
	void setY(double _y);
	void setNombre(string _nombre);
	string getNombre();
	double GetLongitud() const;
	double GetLatitud() const;
	bool operator<(const Punto &otro);
	bool operator==(const Punto &otro) const;

	friend ostream & operator<<(ostream & os, const Punto &p);
	friend istream & operator>>(istream &is, Punto &p);
};

#endif
