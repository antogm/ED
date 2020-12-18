#ifndef punto_h
#define punto_h

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
};

#endif
