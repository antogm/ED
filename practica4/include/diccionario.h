/**
  * @file diccionario.h
  * @brief Fichero cabecera del TDA Diccionario
  *
  * Un objeto del TDA Diccionario permite almacenar palabras con sus correspondientes significados.
  */

#ifndef _DICCIONARIO_H
#define _DICCIONARIO_H

#include <iostream>
#include <string>
#include <list>

using namespace std;

/**
 *  @brief T.D.A. Diccionario
 *
 * Una instancia @e d del tipo de dato abstracto Diccionario sobre los dominios @e T y @e U es
 * una sucesión finita de elementos del tipo struct data.
 * 
 * Cada elemento del tipo struct data almacena una palabra con sus correspondientes significados.
 * 
 * Las operaciones de inserción deben realizarse de forma que la lista de elementos
 * esté siempre ordenada por orden alfabético según su clave.
 *
 * @author Antonio González Maldonado
 * @date Diciembre 2020
*/

template <typename T,typename U>
struct data{
  T clave;
  list<U> info_asoci;
};

template <typename T, typename U>
bool operator< (const data<T,U> &d1,const data <T,U>&d2){
	if (d1.clave<d2.clave)
	  return true;
    
	return false;
}

template <typename T,typename U>
class Diccionario{
  private:
    list<data<T,U>> datos;

    /**
     * @brief Método privado para copiar un diccionario pasado como parámetro
     * @param Dicc Diccionario del que se quieren copiar los datos
     */
    void Copiar(const Diccionario<T,U>& Dicc);

    /**
     * @brief Método privado para borrar el contenido de un diccionario 
     */
    void Borrar();

  public:
    /**
     * @brief Constructor por defecto
     */
    Diccionario();

    /**
     * @brief Constructor de copia
     * @param Dicc objeto Diccionario a copiar 
     */
    Diccionario(const Diccionario &Dicc);

    /**
     * @brief Destructor por defecto
     */
    ~Diccionario();

    /**
     * @brief Sobrecarga del operador de asignación
     * @param Dicc objeto diccionario a asignar
     */
    Diccionario<T,U>& operator=(const Diccionario<T,U> &Dicc);

    /**
     * @brief Método que busca la clave p en el diccionario. Si está, devuelve un iterador hacia su posición.
     * @param p clave a buscar
     * @param it_out iterador devuelto en caso de que la clave esté en el diccionario
     * @return true si la clave está en el diccionario
     */
    bool Esta_Clave(const T &p, typename list<data<T,U>>::iterator &it_out);

    /**
     * @brief Método para insertar un nuevo registro en el diccionario.
     * @param clave del registro a insertar
     * @param info información asociada a la clave a introducir
     */
    void Insertar(const T& clave,const list<U> &info);

    /**
     * @brief Añade nueva información asociada a una clave que está en el diccionario. Se inserta en la posición que le corresponde por orden alfabético.
     * @param p clave del elemento a buscar
     * @param s información a añadir
     */
    void AddSignificado_Palabra(const T &p, const U & s);

    /**
     * @brief Método que devuelve la información asociada a una clave p.
     * @param p Clave del elemento a consultar
     * @return lista que contiene la información de ese elemento
     */
    list<U> getInfo_Asoc(const T & p);
    
    /**
     * @brief Método para consultar el tamaño del diccionario
     * @return número de elementos en el diccionario
     * @post size >= 0
     */
    inline int size() const;
    
    /**
     * @brief Sobrecarga del operador >> (entrada)
     * @param is flujo de entrada
     * @param Dicc Instancia de Diccionario a escribir
     * @note Formato: nº claves en la primera línea, clave-iésima retorno de carro, nº informaciones asociadas en la siguiente línea, y en cada línea su información asociada.
     */
    template <typename sT,typename sU>
    friend istream & operator >>(istream & is,Diccionario<sT,sU> &Dicc);

    /**
     * @brief Sobrecarga del operador << (salida)
     * @param os flujo de salida
     * @param Dicc Instancia de Diccionario a leer
     */
    template <typename sT,typename sU>
    friend ostream & operator<<(ostream & os, const Diccionario<sT,sU> &Dicc);

    class Iterator {
      private:
      typename list<data<T,U>>::iterator it;

      public:
      Iterator();
      Iterator(typename list<data<T,U>>::iterator otroit);
      Iterator& operator++();
      Iterator& operator--();
      bool operator!=(const Iterator &otro);
      bool operator==(const Iterator &otro);
      Iterator& operator=(const Iterator &otro);
      data<T,U> operator*() const;
    };

    class ConstIterator {
      private:
      typename list<data<T,U>>::const_iterator it;
    
      public:
      ConstIterator();
      ConstIterator(typename list<data<T,U>>::const_iterator otroit);
      ConstIterator& operator++();
      bool operator!=(const ConstIterator it2);
      bool operator==(const ConstIterator &otro);
			data<T,U> operator*() const;	
    };

    /**
     * @brief Devuelve un iterador apuntando al principio del diccionario
     * @return objeto Iterator apuntando a datos.begin()
     */
    Iterator begin();

    /**
     * @brief Devuelve un iterador apuntando al final del diccionario
     * @return objeto Iterator apuntando a datos.end()
     */
    Iterator end();
    
    /**
     * @brief Devuelve un iterador constante apuntando al principio del diccionario
     * @return objeto ConstIterator apuntando a datos.cbegin()
     */
    ConstIterator cbegin()const;
    
    /**
     * @brief Devuelve un iterador constante apuntando al final del diccionario
     * @return objeto ConstIterator apuntando a datos.cend() 
     */
    ConstIterator cend()const;

    /*************************************************************************/
    /****************************FUNCIONES EXTRA******************************/
    /**
     * @brief Borra la entrada del diccionario que coincida con la clave pasada como parámetro
     * @param clave Identificador de la entrada a eliminar
     * @return true si tiene éxito
     */
    bool BorrarPalabra(const T &c);

    /**
     * @brief Imprime por pantalla (cout) todos los significados de una palabra
     * @param it Iterador apuntando a la posición de la palabra que se quiere consultar
     */
    void EscribirSignificados(Iterator it);

    /**
     * @brief Devuelve el número de significados que tiene una palabra
     * @param c clave del elemento a consultar
     * @return (int) número de significados diferentes que tiene esa palabra 
     * @note Si la clave no está presente en el diccionario, no hace nada
     */
    int numSignificados(const T &c);

    /*************************FIN FUNCIONES EXTRA*****************************/
    /*************************************************************************/
};

#include "diccionario.cpp"

#endif
