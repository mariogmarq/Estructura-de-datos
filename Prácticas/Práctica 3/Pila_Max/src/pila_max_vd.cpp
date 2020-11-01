#include "../include/pila_max_vd.h"
#include <vector>

template<class T>
Pila_max_VD<T>::Pila_max_VD() {
    pila.clear();
}

template<class T>
void Pila_max_VD<T>::copy(const Pila_max_VD<T> &orig) {
    pila.clear();
    for (int i=0; i<orig.pila.size(); i++)
        pila[i] = orig.pila[i];
}

template<class T>
Pila_max_VD<T>::Pila_max_VD(const Pila_max_VD<T> &p) {
    if(this != &p)
        copy(p);
}

template<class T>
Pila_max_VD<T>::~Pila_max_VD() {
    pila.clear();
}

template<class T>
Pila_max_VD<T> & Pila_max_VD<T>::operator=(const Pila_max_VD<T> &p) {
    if(this != &p)
        copy(p);
    return *this;
}

template<class T>
void Pila_max_VD<T>::Insertar(const Elemento<T> &t) {
    T max;
    Elemento<T> aux;

    if(t.ConsultarMaximo()>pila[pila.size()-1])
        aux.Insertar(t.ConsultarDato(),t.ConsultarMaximo());
    else
        aux.Insertar(t.ConsultarDato(), pila[pila.size()-1].ConsultarMaximo());
    pila.push_back(aux);
}

template<class T>
void Pila_max_VD<T>::Quitar() {
    pila.pop_back();
}

template<class T>
bool Pila_max_VD<T>::vacia() {
    if(pila.size()==0)
        return true;
    else
        return false;
}

template<class T>
Elemento<T> Pila_max_VD<T>::Consultar() const {
    return pila[pila.size()-1];
}

template<class T>
T Elemento<T>::ConsultarDato() const {return a.dato;}

template<class T>
T Elemento<T>::ConsultarMaximo() const {return a.maximo;}

template<class T>
void Elemento<T>::Insertar(T c, T b) {
    a.maximo = b;
    a.dato = c;
}
