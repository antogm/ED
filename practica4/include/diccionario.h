#ifndef _DICCIONARIO_H
#define _DICCIONARIO_H

#include <iostream>
#include <string>
#include <list>

using namespace std;

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
    list<data<T,U> > datos;

    void Copiar(const Diccionario<T,U>& Dicc);
    void Borrar();

  public:
    Diccionario();
    Diccionario(const Diccionario &Dicc);
    ~Diccionario();
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
     * @brief Añade nueva información asociada a una clave que está en el diccionario. Se inserta al final de la lista de información.
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

    /*************************************************************************/
    /****************************FUNCIONES EXTRA******************************/
    //Aniadir aqui


    /*Operator >>. El formato de la entrada es:
         numero de claves en la primera linea
         clave-iésima retorno de carro
         numero de informaciones asociadas en la siguiente linea
         y en cada linea obviamente la informacion asociada
     */
    template <typename sT,typename sU>
    friend istream & operator >>(istream & is,Diccionario<sT,sU> &Dicc);

    /*Operator<<. Obsérvese el uso de 2 tipos diferentes de iteradores. Uno sobre
      listas de listas y otro sobre listas
     */
    template <typename sT,typename sU>
    friend ostream & operator<<(ostream & os, const Diccionario<sT,sU> &Dicc);

    class Iterator {
      private:
      typename list<data<T,U>>::iterator it;

      public:
      Iterator(typename list<data<T,U>>::iterator copia);
      Iterator();

      Iterator& operator++();
      Iterator& operator--();
      bool operator!=(const Iterator &otro);
      Iterator& operator=(const Iterator &otro);
      data<T,U> operator*() const;
    };

    class ConstIterator {
      private:
      typename list<data<T,U>>::const_iterator it;
    
      public:
      ConstIterator();
      ConstIterator(typename list<data<T,U>>::const_iterator copia);
      bool operator!=(const ConstIterator it2);
			data<T,U> operator*() const;	
    };

    Iterator begin();
    Iterator end();
    ConstIterator begin()const;
    ConstIterator end()const;
};

#include "diccionario.cpp"

#endif
