#ifndef punto_h
#define punto_h

using namespace std;

class Punto{
	double x, y;
	string nombre;

	Punto(double _x, double _y, string _nombre){
		x = _x;
		y = _y;
		nombre = _nombre;
	}

	void setX(double _x){
		x = _x;
	}

	void setY(double _y){
		y = _y;
	}

	void setNombre(string _nombre){
		nombre = _nombre;
	}

	string getNombre(){
		return nombre;
	}

	double getX(){
		return x;
	}

	double getY(){
		return y;
	}

	bool operator<(const Punto &otro);

	bool operator==(const Punto &otro){
		return (x == otro.x) && (y == otro.y);
	};

	ostream & operator<<(ostream & os, const Punto &p){
		os << "(" << x << ", " << y << ")";
		return os;
	};

	istream & operator>>(istream &is, Punto &p){
		string linea;
		getline(is, linea, ')');

		linea.erase(0,1); // quita el primer paréntesis
		int pos_coma = linea.find(',');

		string sx = linea.substr(0, pos_coma);
		x = stoi(sx);

		linea.erase(0, pos_coma);
		y = stoi(linea);

		return is;
	}

};

#endif
