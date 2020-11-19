/**
 *  @brief T.D.A. Pila_max
 *
 *
 * Una instancia @e p del tipo de dato abstracto Pila_max sobre un dominio @e T es
 * una sucesión finita de elementos del mismo con un funcionamiento @e LIFO
 * (Last In, First Out) que además almacena el valor máximo contenido en la pila. 
 * 
 * En una pila, las operaciones de inserción, borrado y consulta
 * tienen lugar en un extremo, denominado @e tope de la pila.
 * Una pila de longitud @e n la denotamos

 * - <a1,a2,a3,..,an<

 * En esta pila, tendremos acceso únicamente al elemento del @e Tope,
 * es decir, a @e an.
 *
 * Si n=0 diremos que la pila está vacía.
 *
 * El espacio requerido para el almacenamiento es O(n), donde n es el n�mero 
 * de elementos de la cola.
 *
 * @author Jose Alberto Rodríguez Godoy
 * @author Antonio González Maldonado
 * @date Noviembre 2020
*/

#ifndef pila_max_h
#define pila_max_h

#define CUAL_COMPILA 2
#if CUAL_COMPILA==1
#include "pila_max_vd.h"
#elif CUAL_COMPILA==2
#include "pila_max_cola.h"
#endif

#endif
