#include "../include/cola_max.h"

using namespace std;

template<class T>
Cola_max<T>::Cola_max() {
    // Usa el de stack por defecto
}

template<class T>
void Cola_max<T>::copy(const Cola_max<T> &orig) {
    // Pendiente
}

template<class T>
Cola_max<T>::Cola_max<class T>(const Cola_max<T> &orig) {
    // Pendiente
}

template<class T>
Cola_max<T>::~Cola_max<T>() {
    while(!cola.empty()){
        cola.pop();
    }
}

