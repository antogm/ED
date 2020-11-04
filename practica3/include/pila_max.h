#ifndef _pila_max_h
#define _pila_max_h

#include <iostream>
using namespace std;

// Struct elemento que se usará en los módulos del TDA
template <typename T>
struct elemento{
	T ele;
	T maximo;
};

// Sobrecarga del operador << para el struct elemento
template <class T>
ostream& operator<< (ostream& os , const elemento<T> &r ){
	os << r.ele;
	return os;
};

#define CUAL_COMPILA 1
#if CUAL_COMPILA==1
#include "pila_max_vd.h"
#elif CUAL_COMPILA==2
//#include "pila_max_cola.h"
#endif

#endif
