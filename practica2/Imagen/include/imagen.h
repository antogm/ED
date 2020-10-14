#ifndef IMAGEN_H
#define IMAGEN_H

#include <iostream>
#include "imagenES.h"

typedef unsigned char byte;

/**
  *  @brief T.D.A. Racional
  *
  * Una instancia @e i del tipo de datos abstracto @c Imagen es un objeto
  * que representa la matriz bidimensional de puntos de una imagen digital
  * de niveles de gris.
  * 
  *
  * Un ejemplo de su uso:
  * @include ej_marco.cpp
  *
  * @author Jose Alberto Rodríguez Godoy
  * @author Antonio González Maldonado
  * @date 14/10/2020
  */

class Imagen {

	private:
	/**
	 * @page repConjunto Rep del TDA Imagen
	 *
	 * @section invConjunto Invariante de la representacion
	 * Un objeto valido @e r del TDA Imagen debe cumplir
	 * - @c (filas>=0)&&(columnas>=0)
	 *
	 * @section faConjunto Funcion de abstraccion
	 * Un objeto valido @e r del TDA Imagen representa en una matriz
	 * los bytes que indican la luminosidad de cada punto.
	 *
	 */

	int nf, nc, npixeles;
	byte *img;	// 0-minima luminosidad 255-maxima luminosidad


	public:
	/**
  	 * @brief Constructor por defecto de la clase.
	 * @return Crea un objeto imagen vacío
  	 */
	Imagen();

	/**
  	 * @brief Constructor de copia.
	 * @param J Objeto a copiar
	 * @return Crea el objeto imagen con las mismas dimensiones y valores que el objeto a copiar
  	 */
	Imagen(const Imagen &J);

	/**
  	 * @brief Constructor con parámetros. Reserva memoria para la imagen
	 * @pre filas > 0 y columnas > 0
	 * @param fils Número de filas de la imagen
	 * @param cols Número de columnas de la imagen
	 * @post La imagen creada contiene fils filas y cols columnas
	 * y no está inicializada
	 * @return Crea una imagen con las dimensiones recibidas como parámetros
  	 */
	Imagen(int fils, int cols);

	/**
  	 * @brief Destructor por defecto de la clase. Libera la memoria ocupada
	 * @post La imagen destruida no puede volver a usarse salvo que se vuelva a construir
  	 */
	~Imagen();

	/**
  	 * @brief Consultor para el atributo nf
	 * @return Número de filas de la imagen
	 * @post Tiene que devolver un valor mayor que 0 y no
	 * modificar la imagen.
  	 */
	int num_filas() const;

	/**
  	 * @brief Consultor para el atributo nc
	 * @return Número de columnas de la imagen
	 * @post Tiene que devolver un valor mayor que 0 y
	 * no modificar la imagen.
  	 */
	int num_columnas() const;

	/**
	 * @brief Asigna el valor recibido a un punto de la imagen
	 * @param fila Fila donde se ubica el punto a cambiar
	 * @param col Columna donde se ubica el punto a cambiar
	 * @param valor Valor a establecer en la ubicación recibida
	 * @pre  0 <= fila < num_filas()
	 * 		 0 <= col < num_columnas()
	 *       0 <= valor <= 255
	 * @post La imagen modifica (fila,col) por valor
	 */
	void asigna_pixel (int fila, int col, unsigned char valor);

	/**
	 * @brief Consulta el valor de luminosidad de un punto de la imagen 
	 * @param fila Fila donde se ubica el punto a consultar
	 * @param col Columna donde se ubica el punto a consultar
	 * @return byte que representa la luminosidad de una casilla
	 * @pre 0 <= fila < num_filas() y 0 <= col < num_columnas()
	 * @post La imagen no se modifica y el valor a devolver está entre 0 y 255
	 */
	unsigned char valor_pixel (int fila, int col) const;

	/**
	 * @brief Operador de asignación
	 * @param i Imagen a asignar en el objeto implícito
	 */
	Imagen& operator= (const Imagen& i);

	/**
  	 * @brief Salida de una imagen a un fichero
  	 * @param fichero ruta al fichero en el que escribir la imagen
	 */
	void EscribirImagen (char* ruta);

	/**
	 * @brief Entrada de una imagen desde un fichero
	 * @param fichero ruta al fichero desde el que leer la imagen
	 * @post Sobreescribe la instancia de Imagen actual
	 */
	void LeerImagen (char* ruta);
};

#endif