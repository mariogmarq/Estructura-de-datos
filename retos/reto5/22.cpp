/**
 * @author Mario García Márquez
 * @file 22.cpp
 * @brief implementa es_inferio
 */
#include "bintree.h"
#include <iostream>
using namespace std;

/**
 * @brief Comprueba si A1 es inferior a A2
 * @param A1 Arbol binario
 * @param A2 Arbol binario
 * @return Si A1 es inferior a A2
 * @pre ambos arboles deben de tener la misma estructura
 */
bool es_inferior(bintree<int> &A1, bintree<int> &A2)
{
    auto it1 = A1.begin_preorder();
    auto it2 = A2.begin_preorder();

    while (it1 != A1.end_preorder())
    {
        if (!(*it1 < *it2))
            return false;
        ++it1;
        ++it2;
    }

    return true;
}

int main()
{
    bintree<int> ab1(1);
    bintree<int> ab2(2);
    cout << es_inferior(ab1, ab2);

    ab1.insert_left(ab1.root(), 3);
    ab2.insert_left(ab2.root(), 2);
    cout << es_inferior(ab1, ab2);
}