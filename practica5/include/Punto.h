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
using namespace std;

class Punto{
	private:
		double x, y;
		string nombre;

	public:
		/**
		* @brief Constructor sin parámetros de la clase Punto vacío.	
		*/
		Punto();

		/**
		* @brief Constructor de la clase Punto con parámetros que inicializa los datos x (eje X), y (eje Y) mediante parámetros.
		* @param _x eje_x
		* @param _y eje_y
		*/
		Punto(double _x, double _y);

		/**
		* @brief Constructor de la clase Punto con parámetros que inicializa los datos x (latitud), (longitud) y nombre mediante parámetros.
		* @param _x eje_x
		* @param _y eje_y
		* @param nombre Nombre
		*/
		Punto(double _x, double _y, string _nombre);

		/**
		* @brief Setter modificador para la corrdenada X (latitud).
		*/
		void setX(double _x);

		/**
		* @brief Setter modificador para la corrdenada Y (longitud).
		*/
		void setY(double _y);

		/**
		* @brief Setter modificador para el nombre.
		*/
		void setNombre(string _nombre);

		/**
		* @brief Getter para el nombre actual.
		* @return Nombre actual del punto.
		*/
		string getNombre();

		/**
		* @brief Getter para la coordenada Y (longitud).
		* @return Longitud del punto.
		*/
		double GetLongitud() const;

		/**
		* @brief Getter para la coordenada X (latitud).
		* @return Latitud del punto.
		*/
		double GetLatitud() const;

		/**
		* @brief Compara dos puntos por sus latitudes y longitudes.
		* @param Punto Otro punto a comparar.
		* @return Compara sus latitudes (x) y si tienen la misma compara por sus longitudes (y).
		*/
		bool operator<(const Punto &otro);

		/**
		* @brief Compara si dos puntos son iguales.
		* @param Punto Otro punto a comparar.
		* @return True si lo son, False si no.
		*/
		bool operator==(const Punto &otro) const;

		/**
		* @brief Imprime las coordenadas de un punto.
		* @param Punto Punto a imprimir
		* @param os Salida
		* @return Salida por pantalla
		*/
		friend ostream & operator<<(ostream & os, const Punto &p);

		/**
		* @brief Extrae nombre y coordenadas de un fichero de texto y transforma en Punto definido.
		* @param Punto Punto a modificar.
		* @param is Entrada de flujo de datos.
		* @return Entrada de flujo de datos.
		*/
		friend istream & operator>>(istream &is, Punto &p);
};

#endif
