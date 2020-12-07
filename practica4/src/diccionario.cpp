/**
* @file diccionario.cpp
* @brief Implementación del TDA Diccionario
*/

template <typename T,typename U>
void Diccionario<T,U>::Copiar(const Diccionario<T,U>& Dicc){
    datos.assign(Dicc.datos.begin(),Dicc.datos.end());
}

template <typename T,typename U>
void Diccionario<T,U>::Borrar(){
    datos.erase(datos.begin(),datos.end());
}

// Constructor por defecto
template <typename T,typename U>
Diccionario<T,U>::Diccionario():datos(list<data<T,U> >()){}

// Constructor de copia
template <typename T,typename U>
Diccionario<T,U>::Diccionario(const Diccionario &Dicc){
    Copiar(Dicc);
}

// Destructor
template <typename T,typename U>
Diccionario<T,U>::~Diccionario(){
    Borrar();
}

// Operador de asignación
template <typename T,typename U>
Diccionario<T,U>& Diccionario<T,U>::operator=(const Diccionario<T,U> &Dicc){
    if (this!=&Dicc){
        Borrar();
        Copiar(Dicc);
    }
    
    return *this;
}

template <typename T,typename U>
bool Diccionario<T,U>::Esta_Clave(const T &p, typename list<data<T,U>>::iterator &it_out){
    if (datos.size()>0){
        for (typename list<data<T,U>>::iterator it = datos.begin(); it != datos.end(); ++it){
            // Si encuentra la clave
            if ((*it).clave == p){
                it_out = it;   
                return true;
            }
        }

        // Si no ha encontrado la clave
        it_out = datos.end();
        return false;
        
    }else{
        it_out=datos.end();
        return false;
    }
}

template <typename T,typename U>
void Diccionario<T,U>::Insertar(const T& clave,const list<U> &info){
    typename list<data<T,U> >::iterator it, it2;
    if (!Esta_Clave(clave,it)){
        data<T,U> p;
        p.clave = clave;
        p.info_asoci=info;

        // Busca la posición correspondiente para respetar el orden alfabético
        for (it2 = datos.begin(); it2 != datos.end(); ++it2){
            if( clave < (*it2).clave){
                it = it2;
            }
        }

        datos.insert(it,p);
    }
}

template <typename T,typename U>
void Diccionario<T,U>::AddSignificado_Palabra(const T &p, const U & s){
    // Recorre todo el diccionario
    for(typename list<data<T,U>>::iterator it = datos.begin(); it != datos.end(); ++it){
        // Si encuentra la clave
        if ( (*it).clave == p ){
            // Le añade el significado a ese elemento
            (*it).info_asoci.push_back(s);
        }
    }
};

template <typename T,typename U>
list<U> Diccionario<T,U>::getInfo_Asoc(const T & p){
    typename list<data<T,U> >::iterator it;

    if (!Esta_Clave(p,it)){
        return list<U>();
    }else{
        return (*it).info_asoci;
    }
}

template <typename T,typename U>
inline int Diccionario<T,U>::size() const{
    return datos.size();
}

// Operador de entrada
template <typename T,typename U>
istream & operator>>(istream &is, Diccionario<T,U> &D) {
  int np;
  is >> np;
  is.ignore(); // quitamos \n
  
  Diccionario<T,U> Daux;

  for (int i = 0; i < np; i++){
    T clave;
    getline(is, clave);
    int ns;
    is >> ns;
    is.ignore(); // quitamos \n
    
    list<U> laux;
    
    for (int j = 0; j < ns; j++) {
      U s;
      getline(is, s);
      laux.push_back(s);
    }

    Daux.Insertar(clave, laux);
  }

  D = Daux;
  return is;
}

// Operador de salida
template <typename T,typename U>
ostream & operator<<(ostream & os, const Diccionario<T,U> &Dicc){
    for (typename Diccionario<T, U>::ConstIterator i = Dicc.cbegin(); i != Dicc.cend(); ++i){
        os << (*i).clave << ":\n";

        list<U> l = (*i).info_asoci;
        for (typename list<U>::const_iterator j = l.begin(); j != l.end(); ++j)
            os << '\t' << *j << '\n';

        os << endl;
    }

    return os;
};



// Métodos de la clase Diccionario<T,U>::Iterator:

template <typename T,typename U>
Diccionario<T,U>::Iterator::Iterator(){};

template <typename T,typename U>
Diccionario<T,U>::Iterator::Iterator(typename list<data<T,U>>::iterator otroit){
    it = otroit;
}

template <typename T,typename U>
typename Diccionario<T,U>::Iterator& Diccionario<T,U>::Iterator::operator++(){
    ++it;
    return *this;
};

template <typename T,typename U>
typename Diccionario<T,U>::Iterator& Diccionario<T,U>::Iterator::operator--(){
    it--;
    return *this;
};

template <typename T,typename U>
bool Diccionario<T,U>::Iterator::operator!=(const Diccionario<T,U>::Iterator &otro){
    return it != otro.it;
};

template <typename T,typename U>
bool Diccionario<T,U>::Iterator::operator==(const Diccionario<T,U>::Iterator &otro){
    return it == otro.it;
};

template <typename T,typename U>
typename Diccionario<T,U>::Iterator& Diccionario<T,U>::Iterator::operator=(const Diccionario<T,U>::Iterator &otro){
    it = otro.it;
    return *this;
};

template <typename T,typename U>
data<T,U> Diccionario<T,U>::Iterator::operator*() const{
    return (*it);
};



// Métodos de la clase ConstIterator:

template <typename T,typename U>
Diccionario<T,U>::ConstIterator::ConstIterator(){};

template <typename T,typename U>
Diccionario<T,U>::ConstIterator::ConstIterator(typename list<data<T,U>>::const_iterator otroit){
    it = otroit;
}

template <typename T,typename U>
typename Diccionario<T,U>::ConstIterator& Diccionario<T,U>::ConstIterator::operator++(){
    ++it;
    return *this;
};

template <typename T,typename U>
bool Diccionario<T,U>::ConstIterator::operator!=(const Diccionario<T,U>::ConstIterator otro){
    return it != otro.it;
};

template <typename T,typename U>
bool Diccionario<T,U>::ConstIterator::operator==(const ConstIterator &otro){
    return it == otro.it;
};

template <typename T,typename U>
data<T,U> Diccionario<T,U>::ConstIterator::operator*() const{
    return (*it);
};


    
// Métodos para iterar sobre la clase Diccionario:

template <typename T,typename U>
typename Diccionario<T,U>::Iterator Diccionario<T,U>::begin(){
    return Iterator(datos.begin());
}

template <typename T,typename U>
typename Diccionario<T,U>::Iterator Diccionario<T,U>::end(){
    return Iterator(datos.end());
}

template <typename T,typename U>
typename Diccionario<T,U>::ConstIterator Diccionario<T,U>::cbegin() const{
    return ConstIterator(datos.cbegin());
}

template <typename T,typename U>
typename Diccionario<T,U>::ConstIterator Diccionario<T,U>::cend() const {
    return ConstIterator(datos.cend());
}

// Función extra 1
template <typename T,typename U>
bool Diccionario<T,U>::BorrarPalabra(const T &c){
    typename list<data<T,U> >::iterator it;

    if (Esta_Clave(c, it)){
        datos.erase(it);
        return true;        
    }else{
        return false;
    }
};

// Función extra 2
template <typename T,typename U>
void Diccionario<T,U>::EscribirSignificados(Diccionario<T,U>::Iterator it){
    list<U> l = (*it).info_asoci;
    for(typename list<U>::iterator it2 = l.begin(); it2 != l.end(); ++it2){
        cout << "\t" << *it2 << endl;
    }
};

// Función extra 3
template <typename T,typename U>
int Diccionario<T,U>::numSignificados(const T &c){
    list<U> l = getInfo_Asoc(c);
    int num = 0;

    for (typename list<U>::iterator it = l.begin(); it != l.end(); ++it){
        num++;
    }

    return num;
};