/**
 * @author Mario Garcia Marquez y Daniel Alconchel Vazquez
 * @file pruebapunto.cpp
 */

#include "../include/Punto.h"
#include <iostream>

using namespace std;

int main(){
    Punto A;
    Punto B(31.2, 12);
    cout << "Test clase Punto" << endl;
    cout << "Constructores: " << endl;
    cout << A << "=" << "0 0" << endl;
    cout << B << "=" << "31.2 12 " << endl;
    cout << "Set/Get: " << endl;
    A.setLongitud(12);
    A.setLatitud(13);
    cout << A << "=" << "13 12" << endl;
    cout << A.GetLatitud() << "=" << "13" << endl;
    cout << A.GetLongitud() << "=" << "12" << endl;
    cout << "istream>>:" << endl;
    Punto C;
    cin >> C;
    cout << C << endl;
    cout << "Bool==:" << endl;
    cout << A.operator==(B) << "=" << "0" << endl;
    cout << "Bool<:" << endl;
    cout << B.operator<(B) << "=" << "0" << endl;
    return 0;
}