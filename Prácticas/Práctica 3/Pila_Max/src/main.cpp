#include <iostream>
#include "../include/pila_max_vd.h"
#include <vector>
using namespace std;


int main(){
    Pila_max_VD<int> Pila;
    vector<int> pila;
    Elemento<int> a;
    int i;
    for(i=10; i>=0; i--) {
        a.Insertar(i,i);
        Pila.Insertar(a);
    }
    while(!Pila.vacia()){
        a.Insertar(Pila.Consultar().ConsultarDato(), Pila.Consultar().ConsultarMaximo());
        cout << a.ConsultarDato() << " " << a.ConsultarMaximo() << endl;
        Pila.Quitar();
    }
    return 0;
}