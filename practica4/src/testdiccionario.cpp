#include "diccionario.h"
#include <cassert>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(){
  
  // Lectura del fichero f
  fstream fichero("datos/data.txt"); 

  /*************************************************/
  // Sección 1: Operadores de entrada y salida
  Diccionario<string, string> dicc;
  fichero >> dicc;

  cout << "--------------------------------------------" << endl;
  cout << "Prueba Sección 1: op. salida " << endl;
  cout << "--------------------------------------------" << endl;
  cout << dicc;
  cout << "Total de palabras en el diccionario: " << dicc.size() << endl << endl << endl;

  /*************************************************/
  // Sección 2: Probando funciones Insertar y AddSignificado_Palabra
  string nueva_palabra = "Ruido";
  list<string> nueva_def;
  nueva_def.push_back("Sonido inarticulado, por lo general desagradable.");
  nueva_def.push_back("Apariencia grande en las cosas que no tienen gran importancia.");
  dicc.Insertar(nueva_palabra, nueva_def);
  dicc.AddSignificado_Palabra(nueva_palabra, "Otro significado extra...");

  /*************************************************/
  // Sección 3: Obtener información de una clave
  cout << "----------------------------------------------------" << endl;
  cout << "Prueba Sección 3: getInfo_Asoc " << endl;
  cout << "----------------------------------------------------" << endl;
  string clave_a_buscar = "Compilador";
  list<string> l = dicc.getInfo_Asoc(clave_a_buscar);

  // EscribeSignificado()
  cout << clave_a_buscar << ":" << endl;
  for (list<string>::iterator it = l.begin(); it != l.end(); ++it){
    cout << "\t" << *it << endl;
  }
  cout << endl << endl;

  /*************************************************/
  // Sección 4: Comprueba el iterador de Diccionario
  cout << "----------------------------------------------------------" << endl;
  cout << "Prueba Sección 4: Diccionario<T,U>::Iterator y funciones extra " << endl;
  cout << "----------------------------------------------------------" << endl;

  for (Diccionario<string,string>::Iterator it = dicc.begin(); it != dicc.end(); ++it){
    cout << (*it).clave << ":" << endl;
    dicc.EscribirSignificados(it);
  }

  cout << endl;

  list<data<string,string>>::iterator it5;
  dicc.BorrarPalabra("Sentencia");
  assert(!dicc.Esta_Clave("Sentencia", it5));
  
  assert(dicc.numSignificados("Compilador") == 1);
  assert(dicc.numSignificados("Programa") == 3);

  return 0;
}
