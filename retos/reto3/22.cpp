/**
 * @file 22.cpp
 * @author Mario García Márquez
 * @brief implementacion de intercambia_sec
 */
#include <iostream>
#include <list>
using namespace std;

/**
 * @brief intercambia el grupo de los primeros elementos consecutivos impares
 * por el siguiente de los pares sucesivamente
 * @param l la lista ha ser modificada
 */
void intercambia_sec(list<int>& l) {
  bool impar = l.front() % 2;
  int cambios = 0;
  bool prImpar = impar;
  list<int> acumulador;
  list<int>::iterator dondeInsertar;

  for (auto it = l.begin(); it != l.end(); ++it) {
    impar = *it % 2;

    // Comprobamos si hemos acabado una secuencia de pares/impares
    if (impar != prImpar) {
      ++cambios;

      // En caso de cambiemos y cambios sea par entonces sabemos que ya hemos
      // pasado por dos secuencias, entonces apuntamos al ultimo elemento de
      // acumulador(--end() Es importante ver que esta iteracion es necesaria
      // para cambiar correctamente dondeInsertar
      if (cambios % 2 == 0) {
        acumulador.push_back(*it);
        dondeInsertar = --acumulador.end();
        prImpar = impar;
        continue;
      }
    }
    // Excepcion para la primera iteracion, si inicializamos dondeInsertar a
    // acumulador.begin() al estar este vacia realmente lo hara a
    // acumulador.end()
    if (it == l.begin()) {
      acumulador.push_back(*it);
      dondeInsertar = acumulador.begin();
    } else {
      // Si cambios % 2 == 1 nos encontramos en la segunda secuencia, que
      // insertaremos delante de la primera secuencia
      if (cambios % 2) {
        acumulador.insert(dondeInsertar, *it);
      }

      // En otro caso acumularemos directamente al final del vector
      if (cambios % 2 == 0) {
        acumulador.push_back(*it);
      }
    }
    prImpar = impar;
  }

  // Intercambiamos ambas listas
  l.swap(acumulador);
}

int main() {
  int lis[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  list<int> l(lis, lis + 10);
  cout << "Lista original: \n";
  for (auto i = l.begin(); i != l.end(); ++i) cout << " " << *i;

  intercambia_sec(l);
  cout << "\nSegunda lista: \n";
  for (auto i = l.begin(); i != l.end(); ++i) cout << " " << *i;
}
