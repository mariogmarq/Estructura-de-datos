#include <iostream>
#include <list>

#include "../include/diccionario.h"
using namespace std;

int main() {
    Diccionario<string, string> D;
    D.Insertar("hola", list<string>());
    D.AddSignificado_Palabra("saludo", "hola");
    D.AddSignificado_Palabra("no es la del mar", "hola");
    D.Insertar("adios", list<string>());
    D.AddSignificado_Palabra("despedida", "adios");
    D.Insertar("chorizo", list<string>());

    for (auto it = D.begin(); it != D.end(); ++it) {
        cout << (*it).clave << ":" << endl;
        for (auto i2 = (*it).info_asoci.begin(); i2 != (*it).info_asoci.end();
             ++i2) {
            cout << "\t" << *i2 << "\n";
        }
    }
    auto i = D.getInfo_Asoc(("hola"));
    for (auto& it : i) {
        cout << it << " ";
    }

    cout << endl;

    Diccionario<string, string> G(D);
    G.borrarEntrada("hola");
    for (auto& it : G) {
        cout << it.clave << ":" << endl;
        for (auto& i2 : it.info_asoci) {
            cout << "\t" << i2 << "\n";
        }
    }
    cout << endl;
    D.Diferencia(G);
    for (auto it = D.begin(); it != D.end(); ++it) {
        cout << (*it).clave << ":" << endl;
        for (auto i2 = (*it).info_asoci.begin(); i2 != (*it).info_asoci.end();
             ++i2) {
            cout << "\t" << *i2 << "\n";
        }
    }

    D.Merge(G);
    cout << endl;
    for (auto it = D.begin(); it != D.end(); ++it) {
        cout << (*it).clave << ":" << endl;
        for (auto i2 = (*it).info_asoci.begin(); i2 != (*it).info_asoci.end();
             ++i2) {
            cout << "\t" << *i2 << "\n";
        }
    }
}
