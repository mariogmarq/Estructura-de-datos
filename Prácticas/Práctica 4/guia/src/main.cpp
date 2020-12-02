#include <iostream>
#include <sstream>

#include "../include/guia.h"
using namespace std;

int main() {
    Guia_Tlf guia1, guia2;
    guia1.insert("Mario", "123456789");
    guia2 = guia1;
    guia1.insert("Joaquin", "987654321");
    cout << "Guia 1" << endl << guia1 << "Guia 2" << endl << guia2;
    auto guia3 = guia1 - guia2;
    auto guia4 = guia2 - guia1;
    cout << "Guia1 - guia2" << endl << guia3;
    cout << "Guia2 - guia1" << endl << guia4;
    cout << "Salida por iteradores\n";
    for (auto it = guia1.begin(); it != guia1.end(); ++it) {
        cout << (*it).first << "\t" << (*it).second << endl;
    }

    // probamos >>
    cout << "Probamos >>";
    stringstream ss;
    ss << guia1;
    cout << "\nContenido de String stream\n" << ss.str() << endl;
    Guia_Tlf guia5;
    ss >> guia5;
    cout << "Guia 5\n" << guia5;

    if (guia1.Modificar("Joaquin", "546789123")) {
        cout << "Se ha modificado la clave: \n" << guia1;
    } else {
        cout << "No se ha podido modificar la clave\n";
    }

    cout << endl << "Probamos indice" << endl;
    for (auto it : guia1.Indice('J')) {
        cout << it.first << '\t' << it.second << endl;
    }

    cout << endl << "Probamos rango sacando toda la guia" << endl;
    for (auto it : guia1.Rango(guia1.cbegin(), guia1.cend())) {
        cout << it.first << '\t' << it.second << endl;
    }
}
