#include "guiatlf.h"
#include <iostream>
#include <cassert>
#include <fstream>
using namespace std;

int main(){
	// Lectura del fichero f
	fstream fichero1("./datos/guia.txt"), fichero2("./datos/guia2.txt");

	/**************************************************/
	// Sección 1: Operadores de entrada y salida
	Guia_Tlf g;
	fichero1 >> g;
	cout << g;
	cout << endl;

	/**************************************************/
	// Sección 2: Obtener teléfono dado un nombre
	string nombre_a_consultar = "Luis Sanlucas Tris";
	string telefono_consultado = g.gettelefono(nombre_a_consultar);
	if (telefono_consultado != " "){
		cout << "El teléfono de " << nombre_a_consultar << " es " << telefono_consultado << endl;
	}else{
		cout << "Error en sección 2: No se ha encontrado el teléfono de " << nombre_a_consultar << endl;
	}
	cout << endl;

	/**************************************************/
	// Sección 3: Operaciones de insertado y borrado
	string nuevo_nombre = "Peter Parker Martin";
	string nuevo_tlf = "694361735";
	g.insert(nuevo_nombre, nuevo_tlf);

	string nombre_a_borrar = "Carlos Fardon Rue";
	g.borrar(nombre_a_borrar);

	cout << "Guía tras las inserciones:" << endl << g;
	cout << endl;

	/**************************************************/
	// Sección 4: Comprueba el iterador de la guía
	cout << "Listando la guía con iteradores:" << endl;
		
	for (Guia_Tlf::ConstIterator it = g.cbegin(); it != g.cend(); ++it){
		cout << (*it);
	}
	cout << endl;

	/**************************************************/
	// Sección 5: Unión y diferencia de guías
	Guia_Tlf otraguia;
	fichero2 >> otraguia;

	Guia_Tlf un = g + otraguia;
	Guia_Tlf dif = g - otraguia;
	cout << "La unión de las dos guías:\n" << un << endl;
	cout << "La diferencia de las dos guías:\n" << dif << endl;

	/**************************************************/
	// Sección 6: Funciones extra
	g.actualizarNumero("Susana Arriba Bailon", "656767878");
	assert(!g.vacia());
	assert(g.propietario("656767878") == "Susana Arriba Bailon");

	return 0;
};
