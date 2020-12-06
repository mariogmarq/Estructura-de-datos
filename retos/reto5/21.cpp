/**
 * @author Mario García Márquez
 * @file 21.cpp
 * @brief implementa peso interior
 */
#include <iostream>
#include "bintree.h"
using namespace std;

/**
 * @brief comprueba si la suma de las etiquetas de los nodos es la suma de las hojas que cuelgan
 * @param A arbol binario a comprobar
 * @return si la condicion explicada es cierta
 */
bool pesointerior(bintree<int> A)
{
    //Comprobamos que la raiz no es nula
    if (A.root().null())
        return true;

    //Es facil ver que un arbol cumplira estas condiciones si la suma de sus hijos es igual que el valor del padre
    bool returnValue = true;

    //Miramos si se cumple este requisito

    //Nos aseguramos de que los hijos cumplan este requisito
    bintree<int> copia;
    copia.assign_subtree(A, A.root().left());
    if (!pesointerior(copia))
        returnValue = false;

    copia.assign_subtree(A, A.root().right());
    if (!pesointerior(copia))
        returnValue = false;

    //Nos aseguramos de no estar en una hoja
    if (!(A.root().left().null() && A.root().right().null()))
    {
        //Comprobamos
        if (A.root().left().null())
        {
            if (*A.root().right() != *A.root())
                returnValue = false;
        }
        else if (A.root().right().null())
        {
            if (*A.root().left() != *A.root())
                returnValue = false;
        }
        else
        {
            if ((*(A.root().left()) + *(A.root().right())) != *A.root())
                returnValue = false;
        }
    }

    return returnValue;
}

int main()
{
    bintree<int> arbol(30);
    arbol.insert_left(arbol.root(), 22);
    arbol.insert_right(arbol.root(), 11);
    arbol.insert_left(arbol.root().left(), 16);
    arbol.insert_left(arbol.root().right(), 8);
    arbol.insert_right(arbol.root().left(), 6);
    cout << pesointerior(arbol);

    arbol = bintree<int>(30);
    arbol.insert_left(arbol.root(), 21);
    arbol.insert_right(arbol.root(), 9);
    arbol.insert_left(arbol.root().left(), 7);
    arbol.insert_left(arbol.root().right(), 9);
    arbol.insert_right(arbol.root().left(), 14);
    arbol.insert_left(arbol.root().left().right(), 1);
    arbol.insert_right(arbol.root().left().right(), 13);
    cout << '\n'
         << pesointerior(arbol);
}