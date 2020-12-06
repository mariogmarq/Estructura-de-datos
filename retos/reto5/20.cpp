/**
 * @author Mario García Márquez
 * @file 20.cpp
 * @brief implementacion de max_subtree
 */

#include "bintree.h"
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/**
 * @brief devuelve la suma máxima de las etiquetas del arbol A
 * @param A el árbol binario a calcular su suma máxima
 */

void auxiliar(const bintree<int> &A, vector<int> &v, int actual = 0);

int max_subtree(const bintree<int> &A)
{
    vector<int> sumas;
    auxiliar(A, sumas);
    //Devolvemos el mayor valor de sumas
    return *(max_element(sumas.begin(), sumas.end()));
}

void auxiliar(const bintree<int> &A, vector<int> &v, int actual)
{
    //Si el arbol es nulo devolvemos
    if (A.root().null())
        return;

    //Calculamos el nuevo actual y lo metemos en el vector
    int nuevoActual = actual + *A.root();
    v.push_back(nuevoActual);

    //Para cada hijo que tenga llamamos a la funcion
    if (!A.root().left().null())
    {
        bintree<int> nuevo;
        nuevo.assign_subtree(A, A.root().left());
        auxiliar(nuevo, v, nuevoActual);
    }

    if (!A.root().right().null())
    {
        bintree<int> nuevo;
        nuevo.assign_subtree(A, A.root().right());
        auxiliar(nuevo, v, nuevoActual);
    }
}

int main()
{
    bintree<int> arbol(-5);
    arbol.insert_left(arbol.root(), 1);
    arbol.insert_right(arbol.root(), 3);
    arbol.insert_left(arbol.root().left(), 1);
    cout << max_subtree(arbol);
}