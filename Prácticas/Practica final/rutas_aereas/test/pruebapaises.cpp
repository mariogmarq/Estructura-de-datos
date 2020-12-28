/**
 * @author Mario Garcia Marquez y Daniel Alconchel Vazquez
 * @file pruebapaises.cpp
 */

#include <iostream>
#include "../include/Paises.h"

using namespace std;

int main(){
    Paises A;
    cout << "Probando clase paises: " << endl;
    cout << "Constructores:" << endl;
    cout << A << "=" << "0 0" << endl;
    cout << "Insertar: " << endl;
    Punto aux1(10, 10);
    Punto aux2(12, 10);
    Pais P1(aux1, "Pais1", "pais1.pgm");
    Pais P2(aux2, "Pais2", "pais2.pgm");
    A.Insertar(P1);
    A.Insertar(P2);
    cout << "Salida: " << endl;
    cout << A;
    cout << "Resultado válido" << endl;
    cout << P1 << P2 << endl;
    cout << "operator>>" << endl;
    cin >> A;
    cout << A << endl;
    return 0;
}