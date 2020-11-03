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
    l2.swap(l1);
    return;
  }
  if (l1.empty()) {
    return;
  }

  auto dondeInsertar = l2.begin();

  while (!l1.empty()) {
    l2.insert(dondeInsertar, l1.front());
    l1.pop_front();
    if (dondeInsertar != l2.end()) ++dondeInsertar;
  }
}

int main() {
  int l1[] = {100, 200};
  int l2[] = {1, 2, 3, 4, 5, 6};
  list<int> lis1(l1, l1 + 2);
  list<int> lis2(l2, l2 + 6);
  postintercalar(lis1, lis2);
  for (auto i = lis2.begin(); i != lis2.end(); ++i) cout << "  " << *i;
}
