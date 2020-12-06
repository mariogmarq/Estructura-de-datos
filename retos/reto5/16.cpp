/**
 * @author Mario García Márquez
 * @file 16.cpp
 * @brief implementacion de Fibonnacci trees
 */

#include "bintree.h"
#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

/**
 * @brief Construye una sucesion de arboles binarios de Fibonacci y los almacena en v
 * @param v vector donde se almacenan los árboles
 * @param n numero de árboles a generar
 */
void Fibonacci(vector<bintree<int>> &v, int n)
{
    //limpiamos el vector v
    v.clear();

    //metemos los dos primeros arboles
    bintree<int> primero(rand() % 100);
    bintree<int> segundo(rand() % 100);
    segundo.insert_left(segundo.root(), rand() % 100);
    v.push_back(primero);
    v.push_back(segundo);

    int iteracion = 2;
    while (iteracion <= n)
    {
        bintree<int> actual(rand() % 100);
        auto anterior2 = v.at(iteracion - 2);
        actual.insert_left(actual.root(), anterior2);
        auto anterior1 = v.at(iteracion - 1);
        actual.insert_right(actual.root(), anterior1);
        iteracion++;
        v.push_back(actual);
    }
}

int main()
{
    vector<bintree<int>> v;
    Fibonacci(v, 3);

    for (auto a : v)
    {
        cout << "Nuevo arbol" << endl;
        for (auto b = a.begin_preorder(); b != a.end_preorder(); ++b)
            cout << *b << " ";
        cout << endl;
    }
}