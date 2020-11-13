/**
 * @file 24.cpp
 * @author Mario García Márquez
 * @brief implementacion de postintercalar
 */
#include <iostream>
#include <list>
using namespace std;

/**
 * @brief intercala dos listas poniendo de forma seguida un elemento de una
 * lista y uno de la otra
 * @param l1 la primera lista, quedara vacia tras la funcion
 * @param l2 la lista donde se guardara el resultado
 */

void postintercalar(list<int>& l1, list<int>& l2) {
  // Miramos los casos en los que una lista es vacia
  if (l2.empty()) {
    for (auto i = l1.begin(); i != l1.end(); ++i) l2.push_front(*i);
    l1.clear();
    return;
  }
  if (l1.empty()) {
    return;
  }
  // Nos ponemos en la ultima posicion con un iterador, no usamos rbegin ya que
  // no funciona con la funcion insert
  auto dondeInsertar = --(l2.end());

  // mientras queden elementos en l1 los insertaremos en el iterador
  while (!l1.empty()) {
    l2.insert(dondeInsertar, l1.front());
    l1.pop_front();
    // nos movemos dos posiciones a la derecha sin pasarnos de begin
    if (dondeInsertar != l2.begin()) {
      --dondeInsertar;
      if (dondeInsertar != l2.begin()) --dondeInsertar;
    }
  }
}

int main() {
  int l1[] = {100, 200, 300};
  int l2[] = {1, 2, 3, 4, 5, 6};
  list<int> lis2(l1, l1 + 3);
  list<int> lis1(l2, l2 + 6);
  postintercalar(lis1, lis2);
  for (auto i = lis2.begin(); i != lis2.end(); ++i) cout << "  " << *i;
}
