#include <iostream>
#include "pila_max.h"
using namespace std;

int main(){
	Pila_max<int> p;
	
	for (int i = 10; i >= 0; i--)
		p.poner(i);
	
	while (!p.vacia()){
		elemento<int> x = p.tope();
		cout << x.ele << endl;
		p.quitar();
	}
	
	return 0;
}
