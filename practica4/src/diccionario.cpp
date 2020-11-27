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

template <typename T,typename U>
Diccionario<T,U>::Diccionario():datos(list<data<T,U> >()){}

template <typename T,typename U>
Diccionario<T,U>::Diccionario(const Diccionario &Dicc){
    Copiar(Dicc);
}

template <typename T,typename U>
Diccionario<T,U>::~Diccionario(){}

template <typename T,typename U>
Diccionario<T,U>& Diccionario<T,U>::operator=(const Diccionario<T,U> &Dicc){
    if (this!=&Dicc){
        Borrar();
        Copiar(Dicc);
    }
    
    return *this;
}

template <typename T,typename U>
bool Diccionario<T,U>::Esta_Clave(const T &p, typename  list<data<T,U> >::iterator &it_out){
    if (datos.size()>0){
        //Completar. Hay que iterar para localizar la clave...puede que no este...
    }else{
        it_out=datos.end();
        return false;
    }
}

template <typename T,typename U>
void Diccionario<T,U>::Insertar(const T& clave,const list<U> &info){
    typename list<data<T,U> >::iterator it;
    if (!Esta_Clave(clave,it)){
        data<T,U> p;
        p.clave = clave;
        p.info_asoci=info;
        datos.insert(it,p);
    }
}

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



// Métodos de la clase Diccionario<T,U>::Iterator:

template <typename T,typename U>
Diccionario<T,U>::Iterator::Iterator(typename list<data<T,U>>::iterator copia){
    it = copia;
};

template <typename T,typename U>
Diccionario<T,U>::Iterator::Iterator(){};

template <typename T,typename U>
typename Diccionario<T,U>::Iterator& Diccionario<T,U>::Iterator::operator++(){
    ++it;
    return *this;
};

template <typename T,typename U>
typename Diccionario<T,U>::Iterator& Diccionario<T,U>::Iterator::operator--(){
    --it;
    return *this;
};

template <typename T,typename U>
bool Diccionario<T,U>::Iterator::operator!=(const Diccionario<T,U>::Iterator &otro){
    return (*it).clave != (*otro).clave;
};

template <typename T,typename U>
typename Diccionario<T,U>::Iterator& Diccionario<T,U>::Iterator::operator=(const Iterator &otro){
    if(it != otro)
        it = otro;

    return *this;
};

template <typename T,typename U>
data<T,U> Diccionario<T,U>::Iterator::operator*() const{
    return *it;
};



// Métodos de la clase ConstIterator:

template <typename T,typename U>
Diccionario<T,U>::ConstIterator::ConstIterator(){};

template <typename T,typename U>
Diccionario<T,U>::ConstIterator::ConstIterator(typename list<data<T,U>>::const_iterator copia){
    it = copia;
};

template <typename T,typename U>
bool Diccionario<T,U>::ConstIterator::operator!=(const Diccionario<T,U>::ConstIterator otro){
    return (*it).clave != (*otro).clave;
};

template <typename T,typename U>
data<T,U> Diccionario<T,U>::ConstIterator::operator*() const{
    return *it;
};


    
// Métodos de la clase Diccionario para iterar sobre ella:

template <typename T,typename U>
typename Diccionario<T,U>::Iterator Diccionario<T,U>::begin(){
    return Iterator( datos.begin() );
}

template <typename T,typename U>
typename Diccionario<T,U>::Iterator Diccionario<T,U>::end(){
    return Iterator( datos.end() );
}

template <typename T,typename U>
typename Diccionario<T,U>::ConstIterator Diccionario<T,U>::begin()const{
    return ConstIterator( datos.cbegin() );
}

template <typename T,typename U>
typename Diccionario<T,U>::ConstIterator Diccionario<T,U>::end()const {
    return ConstIterator( datos.cend() );
}

