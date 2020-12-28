/**
 * @author Mario Garcia Marquez y Daniel Alconchel Vazquez
 * @file pruebaunto.cpp
 */

#include <iostream>
#include "../include/Pais.h"

using namespace std;

int main(){
    Punto aux(12,12);
    Pais A;
    Pais B(aux, "España", "españa.pgm");
    cout << "Probando Clase País" << endl;
    cout << "Probando constructores: " << endl;
    cout << A << "=" << "0 0 - - " << endl;
    cout << B << "=" << "12 12 España españa.pgm" << endl;
    cout << "Probando Gets/Sets:" << endl;
    Punto aux2(9,9);
    A.setLocalizacion(aux2);
    A.setNombre("Italia");
    A.setBandera("italia.pgm");
    cout << A.Localizacion() << "=" << "9 9" << endl;
    cout << A.GetPais() << "=" << "Italia" << endl;
    cout << A.GetBandera() << "=" << "italia.pgm" << endl;
    cout << "Operator==:" << endl;
    cout << A.operator==(B) << "=" << "0" << endl;
    cout << A.operator==(A) << "=" << "1" << endl;
    cout << "Operator>>" << endl;
    cin >> A;
    cout << A << endl;
    return 0;
}