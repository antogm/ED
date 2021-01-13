/**
* @file Punto.h
* @Author Antonio Gonzalez Maldonado / José Alberto Rodríguez Godoy
* @date 3/1/2021
* @brief Prototipo de funciones de la clase Punto (Extendido en el archivo Punto.cpp).
*/

#ifndef punto_h
#define punto_h

#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

class Punto{
	private:
		double x, y;

	public:
		/**
		* @brief Constructor sin parámetros de la clase Punto vacío.	
		*/
		Punto(){
			x = 0;
			y = 0;
		};

		/**
		* @brief Constructor de la clase Punto con parámetros que inicializa los datos x (eje X), y (eje Y) mediante parámetros.
		* @param _x eje_x
		* @param _y eje_y
		*/
		Punto(double _x, double _y){
			x = _x;
			y = _y;
		};

		/**
		* @brief Setter modificador para la coordenada X (latitud).
		*/
		void setX(double _x){
			x = _x;
		};

		/**
		* @brief Setter modificador para la coordenada Y (longitud).
		*/
		void setY(double _y){
			y = _y;
		};

		/**
		* @brief Getter para la coordenada X (latitud).
		* @return Latitud del punto.
		*/
		double GetLatitud() const{
			return x;
		};

		/**
		* @brief Getter para la coordenada Y (longitud).
		* @return Longitud del punto.
		*/
		double GetLongitud() const{
			return y;
		};

		/**
		* @brief Compara dos puntos por sus latitudes y longitudes.
		* @param Punto Otro punto a comparar.
		* @return Compara sus latitudes (x) y si tienen la misma compara por sus longitudes (y).
		*/
		bool operator<(const Punto &otro) const{
			if (!(x == otro.x))
				return x < otro.x;
			else
				return y < otro.y;
		};

		/**
		* @brief Compara si dos puntos son iguales.
		* @param Punto Otro punto a comparar.
		* @return True si lo son, False si no.
		*/
		bool operator==(const Punto &otro) const{
			return (abs(x-otro.x) <= 0.0001 && abs(y-otro.y) <= 0.0001);
		};

		/**
		* @brief Imprime las coordenadas de un punto.
		* @param Punto Punto a imprimir
		* @param os Salida
		* @return Salida por pantalla
		*/
		friend ostream & operator<<(ostream & os, const Punto &p){
			os << "(" << p.x << "," << p.y << ")";
			return os;
		};

		/**
		* @brief Extrae nombre y coordenadas de un fichero de texto y transforma en Punto definido.
		* @param Punto Punto a modificar.
		* @param is Entrada de flujo de datos.
		* @return Entrada de flujo de datos.
		*/
		friend istream & operator>>(istream &is, Punto &p){
			string linea;
			getline(is, linea, ')');

			int pos_coma = linea.find(',');

			string sx, sy;
			sx = linea.substr(0, pos_coma-1);
			linea.erase(0, pos_coma+1);				// se queda solo con lo que hay después de la coma
			sy = linea;

			// quita los posibles caracteres no deseados de los strings
			sx.erase(remove(sx.begin(), sx.end(), ' '), sx.end());
			sy.erase(remove(sy.begin(), sy.end(), ' '), sy.end());
			sx.erase(remove(sx.begin(), sx.end(), '\t'), sx.end());
			sy.erase(remove(sy.begin(), sy.end(), '\t'), sy.end());
			sx.erase(remove(sx.begin(), sx.end(), '\n'), sx.end());
			sy.erase(remove(sy.begin(), sy.end(), '\n'), sy.end());
			sx.erase(remove(sx.begin(), sx.end(), '('), sx.end());
			sy.erase(remove(sy.begin(), sy.end(), '('), sy.end());

			double 	x = stod(sx),
					y = stod(sy);

			p = Punto(x,y);

			return is;
		};
};

#endif
