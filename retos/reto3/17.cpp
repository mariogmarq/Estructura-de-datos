/**
 * @file 17.cpp
 * @author Mario García Márquez
 * @brief implementar la funcion bool encuentra
 */
#include <iostream>
#include <list>
using namespace std;

/**
 * @brief comprueba si l1 es una sublista de l2
 * @param l1 lista a comprobar si es sublista
 * @param l2 lista donde se deben encontrar la sublista
 * @param indx vector donde se guardaran los indices de la lista
 * @return si l1 es una sublista o no
 * @warning por el ejemplo dado por el enunciado entiendo que los elementos de
 * l1 deben aparecer en ese mismo orden en l2
 */
bool encuentra(list<int> &l1, list<int> &l2, list<int> &indx) {
  // Limpiamos indx
  indx.clear();

  // Si l1 tiene mayor tamaño que l2 no hay nada que comprobar y se devuelve
  if (l1.size() > l2.size()) return false;

  // Iteraremos sobre l2 y mantendremos un iterador sobre l1
  auto it1 = l1.begin();
  int indice = 0;

  for (auto it2 = l2.begin(); it2 != l2.end(); ++it2) {
    if (*it1 == *it2) {
      ++it1;
      indx.push_back(indice);
    }
    ++indice;
  }

  // Si ahora mismo it1 == l1.end() entonces habremos llegado al final de la
  // lista, lo que significa que todos los elementos de l1 estan contenidos en
  // l2
  if (it1 == l1.end()) {
    return true;
  }

  // En otro caso vaciamos la lista y devolvemos false
  indx.clear();
  return false;
}

int main() {
  int l2[] = {13, 9, 8, 12, 9, 6, 12, 2, 9, 14, 18, 10};
  int l1[] = {13, 9, 9, 6, 2, 14};

  list<int> lista1(l1, l1 + 6), lista2(l2, l2 + 12), indx;

  if (encuentra(lista1, lista2, indx)) {
    for (auto i = indx.begin(); i != indx.end(); ++i) cout << "  " << *i;
    cout << std::endl;
  } else {
    cout << "Indx esta vacia " << indx.empty();
  }
}
