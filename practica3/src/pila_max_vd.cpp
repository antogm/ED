// Implementación del módulo vd del TDA Pila_max

template<class T>
Pila_max<T>::Pila_max(){
	v.resize(N);
	num_elem = 0;
};

template<class T>
void Pila_max<T>::poner(T ele){
	if (num_elem == 0)				// Si es la primera inserción, se convierte en el máximo
		maximo = ele;
		
	if (num_elem >= v.size())		// Si no hay hueco en el vector hace resize
		v.resize(num_elem + N);

	v[num_elem] = ele;				// Lo inserta

	if (v[num_elem] > maximo)		// Comprueba si es un nuevo máximo
		maximo = v[num_elem];

	num_elem++;
};

template<class T>
void Pila_max<T>::quitar(){
	assert(num_elem > 0);			// Si la pila no tiene elementos, abortar
	num_elem--;						
	v.erase(v.begin()+num_elem);   
};

template<class T>
elemento<T> Pila_max<T>::tope(){
	elemento<T> r;
	r.ele = v[num_elem-1];
	r.maximo = maximo;

	return r;
};

template<class T>
bool Pila_max<T>::vacia(){
	return num_elem == 0;
};
