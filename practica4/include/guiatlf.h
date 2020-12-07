/**
 * @file guiatlf.h
 * @brief Fichero cabecera del TDA Guia_Tlf
 * 
 * Un objeto del TDA Guia_Tlf permite almacenar un nombre y su número teléfono asociado, los mantiene ordenados alfabéticamente 
 * y permite acceder a un elemento sabiendo su clave (nombre).
 */

#ifndef _GUIATLF_H
#define _GUIATLF_H
#include <map>
#include <iostream>
#include <string>
using namespace std;

/**
 *  @brief T.D.A. Guia_Tlf
 *
 * Una instancia @e g del tipo de dato abstracto Guia_Tlf es
 * una sucesión finita de pares de dos strings (nombre y teléfono).
 *
 * @author Antonio González Maldonado
 * @date Diciembre 2020
*/

inline istream & operator>>(istream &is, pair<string,string> &d){
	getline(is, d.first, '\t');
	getline(is, d.second);
	return is;
}

inline ostream & operator<<(ostream &os, const pair<string,string> &d){
	os << d.first << "\t" << d.second << endl;
	return os;
}

class Guia_Tlf{
	private:
	map<string,string> datos;
					     
	public:
	/**
	 * @brief Constructor por defecto
	 */
	Guia_Tlf();

	/**
	 * @brief Constructor de copia
	 */
	Guia_Tlf(const Guia_Tlf & gt);

	/**
	 * @brief Destructor
	 */
	~Guia_Tlf();

	/**
	 * @brief Sobrecarga del operador de asignación
	 */
	Guia_Tlf& operator=(const Guia_Tlf &gt);

	/**
	 @brief Acceso a un elemento
	 @param nombre: nombre del elemento  elemento acceder
	 @return devuelve el valor (teléfono) asociado a ese nombre
	 */
	string & operator[](const string &nombre);

	/**
	 @brief Devuelve el teléfono asociado al nombre pasado como parámetro
	 @param nombre nombre del elemento a acceder
	 @return devuelve el valor asociado a ese nombre
	 */
	string  gettelefono(const string & nombre);
    
	/**
	 @brief Insert un nuevo telefono 
	 @param nombre: nombre clave del nuevo telefono
	 @param tlf: numero de telefono
	 @return : un pair donde first apunta al nuevo elemento insertado y bool es true si se ha insertado el nuevo tlf o false en caso contrario
	 */
	pair<map<string,string>::iterator,bool> insert(string nombre, string tlf);

	/**
	 @brief Insert un nuevo telefono 
	 @param p: pair con el nombre y el telefono asociado
	 @return : un pair donde first apunta al nuevo elemento insertado y bool es true si se ha insertado el nuevo tlf o false en caso contrario
	 */
	pair<map<string,string>::iterator,bool> insert(pair<string,string> p);

	/**
	 @brief Borrar un telefono
	 @param nombre: nombre que se quiere borrar
	 @note: en caso de que fuese un multimap borraria todos con ese nombre
	 */
	void borrar(const string &nombre);

	/**
	 @brief Borrar un telefono
	 @param nombre: nombre que se quiere borrar
	 @param tlf: teléfono que se quiere borrar
	 @note: esta funcion nos permite borrar solamente aquel que coincida en nombre y tlf
	 */
	void borrar(const string &nombre,const string &tlf);

	/**
	  @brief  Numero de telefonos 
	  @return el numero de telefonos distintos presentes en la guía
	 */
	int size()const;

	/**
	  @brief Contabiliza cuantos telefonos tenemos asociados a un nombre
	  @param nombre: nombre sobre el que queremos consultar
	  @return numero de telefonos asociados a un nombre
	 */
	unsigned int contabiliza(const string &nombre);
   
	/**
	 @brief Limpia la guia
	 */
	void clear();

	/**
	 @brief Union de guias de telefonos
	 @param g: guia que se une
	 @return: una nueva guia resultado de unir el objeto al que apunta this y g
	 */
	Guia_Tlf operator+(const Guia_Tlf & g);
	      
	/**
	 @brief Diferencia de guias de telefonos
	 @param g: guia que se une
	 @return: una nueva guia resultado de la diferencia del objeto al que apunta this y g
	 */
	Guia_Tlf operator-(const Guia_Tlf & g);

	/**
	  @brief Escritura de la guia de telefonos
	  @param os: flujo de salida. Es MODIFICADO
	  @param g: guia de telefonos que se escribe
	  @return el flujo de salida
	 */ 
	friend ostream & operator<<(ostream & os, Guia_Tlf & g);

	/**
	 @brief Lectura de  la guia de telefonos
	 @param is: flujo de entrada. ES MODIFICADO
	 @param g: guia de telefonos. ES MODIFICADO
	 @return el flujo de entrada
	 */
	friend istream& operator>>(istream &is, Guia_Tlf &g);

	// Funciones extra:

	/**
	 * @brief Actualiza el número de teléfono asociado a un nombre
	 * @param nombre del contacto a actualizar
	 * @param nuevo_numero nuevo número que se quiere asociar a ese nombre
	 * @note El número antiguo desaparece de la guía
	 * @return true si tiene éxito
	 */
	bool actualizarNumero(string nombre, string nuevo_numero);

	/**
	 * @brief Método para saber si la guía está vacía o contiene elementos
	 * @return true si esta vacía
	 */
	bool vacia();

	/**
	 * @brief Dado un número pasado como parámetro, busca en la guía a quién pertenece
	 * @param numero del que se quiere conocer la información
	 * @return nombre del propietario o "no encontrado" si no está en la guía
	 */
	string propietario(string numero);

	class Iterator{
		private:
		map<string,string>::iterator it;

		public:
		Iterator();
		Iterator(const map<string,string>::iterator &it2);
		pair<string,string> operator*() const;
		Iterator& operator++();
      	Iterator& operator--();
		bool operator!=(const Iterator &otro);
      	bool operator==(const Iterator &otro);
		Iterator& operator=(const Iterator &otro);
	};

	class ConstIterator{
		private:
		map<string,string>::const_iterator it;

		public:
		ConstIterator();
		ConstIterator(const map<string,string>::const_iterator &it2);
		ConstIterator& operator++();
      	bool operator!=(const ConstIterator &it2);
      	bool operator==(const ConstIterator &otro);
		pair<string,string> operator*() const;
		ConstIterator& operator=(const ConstIterator &otro);
	};

	Iterator begin();
	Iterator end();
	ConstIterator cbegin();
	ConstIterator cend();
};

#endif
