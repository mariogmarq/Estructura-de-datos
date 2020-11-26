#include "../include/diccionario.h"

using namespace std;

template <class T, class U>
Diccionario<T, U>::Diccionario(){};

template <class T, class U>
void Diccionario<T, U>::Borrar() {
  this->datos.clear();
}

template <class T, class U>
void Diccionario<T, U>::Copiar(const Diccionario<T, U> &D) {
  this->Borrar();
  for(auto i = D.cbegin(); i != D.cend(); ++i){
      this->datos.push_back(*i);
  }
}

template <class T, class U>
Diccionario<T, U>::Diccionario(const Diccionario<T, U> &D) {
  this->Copiar(D);
}

template <class T, class U>
Diccionario<T, U>::~Diccionario() {}

template <class T, class U>
bool Diccionario<T,U>::Esta_Clave(const T &p, typename std::list<data<T, U>>::iterator &it_out) {

    for(auto it = this->datos.begin(); it != this->datos.end(); ++it){
        if ((*it).clave == p) {
            it_out = it;
            return true;
        } else if (p < (*it).clave) {
            it_out = it;
            return false;
        }
    }

    return false;
}

template<class T, class U>
Diccionario<T, U> &Diccionario<T, U>::operator=(const Diccionario<T, U> &D) {
    this->Copiar(D);
}

template<class T, class U>
typename Diccionario<T,U>::iterator Diccionario<T, U>::begin() {
    return Diccionario<T,U>::iterator(datos.begin());
}

template<class T, class U>
typename Diccionario<T,U>::iterator Diccionario<T, U>::end() {
    return Diccionario<T,U>::iterator(datos.end());
}

template<class T, class U>
void Diccionario<T, U>::Insertar(const T &clave, const list<U> &info) {
    auto it = datos.begin();
    if(!this->Esta_Clave(clave, it)){
        data<T,U> dato;
        dato.clave = clave;
        dato.info_asoci = info;
        datos.insert(it, dato);
    }
}

template<class T, class U>
list<U> Diccionario<T, U>::getInfo_Asoc(const T &p) {
    auto it = datos.begin();
    if(this->Esta_Clave(p, it)){
        return (*it).info_asoci;
    }
    return list<U>();
}

template<class T, class U>
void Diccionario<T, U>::AddSignificado_Palabra(const U &s, const T &p) {
    auto it = datos.begin();
    if(this->Esta_Clave(p, it)){
        (*it).info_asoci.push_back(s);
    } else {
        list<U> l;
        l.push_back(s);
        this->Insertar(p, l);
    }
}

template<class T, class U>
int Diccionario<T, U>::size() const {
    return datos.size();
}

template<class T, class U>
void Diccionario<T, U>::borrarEntrada(const T &p) {
    auto it = datos.begin();
    if(this->Esta_Clave(p, it)){
        datos.erase(it);
    }
}

template<class T, class U>
void Diccionario<T, U>::Merge(const Diccionario<T, U> &D) {
    typename list<data<T,U>>::iterator aux;
    for(auto it = D.cbegin(); it != D.cend(); ++it){

        if(this->Esta_Clave((*it).clave, aux)){
            //Insertamos la informacion asociada que no esté en nuestro primer diccionario
            for(auto it2 = (*it).info_asoci.cbegin(); it2 != (*it).info_asoci.cend(); ++it2){
                bool esta = false;
                for(auto it3 = (*aux).info_asoci.begin(); it3 != (*aux).info_asoci.end(); ++it3){
                    if((*it3)==(*it2))
                        esta = true;
                    if(esta)
                        break;
                }
                if(!esta)
                    (*aux).info_asoci.push_back((*it2));
            }
        } else {
            this->Insertar((*it).clave, (*it).info_asoci);
        }
    }
}

template<class T, class U>
void Diccionario<T, U>::Diferencia(const Diccionario<T, U> &D) {
    Diccionario<T,U>::iterator aux;
    for(auto it = D.cbegin(); it != D.cend(); ++it){
        borrarEntrada((*it).clave);
    }
}

template<class T, class U>
list<data<T, U>> Diccionario<T, U>::Rango(const T &t1, const T &t2) const {
    Diccionario<T,U>::iterator begin, end;
    Esta_Clave(t1, begin);
    Esta_Clave(t2, end);
    return list<data<T,U>>(begin, end);

}

template<class T, class U>
typename Diccionario<T, U>::const_iterator Diccionario<T, U>::cbegin() const{
    return Diccionario<T,U>::const_iterator(datos.cbegin());
}

template<class T, class U>
typename Diccionario<T, U>::const_iterator Diccionario<T, U>::cend() const{
    return Diccionario<T,U>::const_iterator(datos.cend());
}


template<class T, class U>
Diccionario<T, U>::iterator::iterator(typename std::list<data<T, U>>::iterator it) {
    this->it = it;
}

template<class T, class U>
Diccionario<T, U>::iterator::iterator() {}

template<class T, class U>
Diccionario<T, U>::iterator::iterator(const Diccionario::iterator &it) {
    this->it = it.it;
}

template<class T, class U>
typename Diccionario<T, U>::iterator &Diccionario<T, U>::iterator::operator=(const Diccionario::iterator &it) {
    this->it = it.it;
    return *this;
}

template<class T, class U>
typename Diccionario<T, U>::iterator &Diccionario<T, U>::iterator::operator++() {
    ++(this->it);
    return *this;
}

template<class T, class U>
typename Diccionario<T, U>::iterator &Diccionario<T, U>::iterator::operator--() {
    --this->it;
   return *this;
}

template<class T, class U>
data<T, U> &Diccionario<T, U>::iterator::operator*() {
    return *it;
}

template<class T, class U>
bool Diccionario<T, U>::iterator::operator!=(const Diccionario::iterator &it) const {
    return this->it != it.it;
}

template<class T, class U>
bool Diccionario<T, U>::iterator::operator==(const Diccionario::iterator &it) const {
    return this->it == it.it;
}


template<class T, class U>
Diccionario<T, U>::const_iterator::const_iterator(typename std::list<data<T, U>>::const_iterator it) {
    this->it = it;
}

template<class T, class U>
Diccionario<T, U>::const_iterator::const_iterator() {}

template<class T, class U>
Diccionario<T, U>::const_iterator::const_iterator(const Diccionario::const_iterator &it) {
    this->it = it.it;
}

template<class T, class U>
typename Diccionario<T, U>::const_iterator &Diccionario<T, U>::const_iterator::operator=(const Diccionario::const_iterator &it) {
    this->it = it.it;
    return *this;
}

template<class T, class U>
typename Diccionario<T, U>::const_iterator &Diccionario<T, U>::const_iterator::operator++() {
    ++(this->it);
    return *this;
}

template<class T, class U>
typename Diccionario<T, U>::const_iterator &Diccionario<T, U>::const_iterator::operator--() {
    --this->it;
    return *this;
}

template<class T, class U>
data<T, U> Diccionario<T, U>::const_iterator::operator*() const{
    return *it;
}

template<class T, class U>
bool Diccionario<T, U>::const_iterator::operator!=(const Diccionario::const_iterator &it) const {
    return this->it != it.it;
}

template<class T, class U>
bool Diccionario<T, U>::const_iterator::operator==(const Diccionario::const_iterator &it) const {
    return this->it == it.it;
}
