/**
 * @author Mario García Márquez
 * @file 17.cpp
 * @brief implementacion de funciones sobres árboles de probabilidad
 */

#include "bintree.h"
#include <iostream>
using namespace std;

/**
 * @brief calcula si el árbol A es un árbol de probabilidad
 * @param A el árbol que será comprobado
 * @return Si el árbol A es de probabilidad o no
 */
bool esProbabilidad(const bintree<float> &A)
{
    bool returnValue = true;
    //Si A es nulo, devolvemos true
    if (A.root().null())
        return returnValue;

    //Usamos recursividad
    bintree<float> auxiliar;
    auxiliar.assign_subtree(A, A.root().left());
    if (!esProbabilidad(auxiliar))
        returnValue = false;

    auxiliar.assign_subtree(A, A.root().right());
    if (!esProbabilidad(auxiliar))
        returnValue = false;

    // Comprobamos que la raíz de nuestro árbol esta entre 0 y 1
    if (!(*(A.root()) >= 0 && *(A.root()) <= 1))
    {
        //En caso de que no esté nuestro árbol no es probabilidad
        returnValue = false;
    }

    //Comprobamos si nuestra raíz es una hoja o no
    if (!(A.root().right().null() && A.root().left().null()))
    {
        //En este caso nuestro nodo no es una hoja
        if (A.root().left().null())
        {
            if (A.root().right() != 1.0)
                returnValue = false;
        }
        else if (A.root().right().null())
        {
            if (A.root().left() != 1)
                returnValue = false;
        }
        else if (*A.root().left() + *A.root().right() != 1.0)
        {
            returnValue = false;
        }
    }

    return returnValue;
}

/**
 * @brief devuelve si un suceso es probable, esto, si el producto del camino del nodo hasta la raiz es mayor que 0.5
 * @param A el árbol a comprobar
 * @param acumulador no dar ningun valor, se usa para llamadas recursivas
 * @return si es probable
 * @pre A debe ser de probabilidad
 */
bool probable(const bintree<float> &A, float acumulador = 1)
{
    bool returnValue = false;
    //Comprobamos si A es nulo
    if (A.root().null())
        return returnValue;
    //Creamos un nuevo acumulador
    float futuroAcumulador = acumulador * *A.root();

    //Comprobamos si A es una hoja
    if (A.root().right().null() && A.root().left().null())
    {
        //Es una hoja, devolvemos si es probable
        returnValue = futuroAcumulador >= 0.5;
    }
    else
    {
        //Si no es una hoja hacemos llamada recursiva
        bintree<float> auxiliar;
        auxiliar.assign_subtree(A, A.root().left());
        if (probable(auxiliar, futuroAcumulador))
            returnValue = true;

        auxiliar.assign_subtree(A, A.root().right());
        if (probable(auxiliar, futuroAcumulador))
            returnValue = true;
    }

    return returnValue;
}

int main()
{
    bintree<float> prueba(1);
    prueba.insert_left(prueba.root(), 0.3);
    prueba.insert_right(prueba.root(), 0.7);
    prueba.insert_left(prueba.root().right(), 0.2);
    prueba.insert_right(prueba.root().right(), 0.8);
    cout << probable(prueba);

    prueba = bintree<float>(1);
    prueba.insert_right(prueba.root(), 0.4);
    prueba.insert_left(prueba.root(), 0.6);
    prueba.insert_left(prueba.root().left(), 0.3);
    prueba.insert_right(prueba.root().left(), 0.7);
    cout << probable(prueba);
}