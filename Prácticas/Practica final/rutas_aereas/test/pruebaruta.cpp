/**
 * @author Mario Garcia Marquez y Daniel Alconchel Vazquez
 * @file pruebaruta.cpp
 */

#include "../include/Ruta.h"
#include <iostream>

using namespace std;

int main(){
    Ruta A;
    cout << "Probando clase Ruta: " << endl;
    cout << "Constructor: " << endl;
    cout << A << "=" << "0" << endl;
    cout << "Probando Sets/Gets:" << endl;
    A.nuevoNombre("Ruta1");
    cout << A.GetNombre() << "=Ruta1" << endl;
    Punto a(12,12);
    Punto b(0,0);
    A.nuevoPunto(b);
    A.nuevoPunto(a);
    A.nuevoInteres(a);
    cout << A << "= Ruta1 2 (0,0) (12,12)" << endl;
    cout << "Operator= y Constructor de copia" << endl;
    cout << "Operator= y Constructor de copia" << endl;
    Ruta B(A);
    Ruta C = A;
    cout << B << "=" << A << endl;
    cout << C << "=" << A << endl;
    cout << "Operatoe>>: " << endl;
    Ruta D;
    cin >> D;
    cout << D;

    return 0;
}