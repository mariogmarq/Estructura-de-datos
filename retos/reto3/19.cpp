/**
 * @file 19.cpp
 * @author Mario García Márquez
 * @brief implementacion de transformarpila
 */
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/**
 * @brief transforma p en otra pila sin elementos consecutivos repetidos
 * @param p la pila a ser transformada
 */
void transformarpila(stack<int>& p) {
  // Para lograr el resultado deseado primero pasaremos los elementos a un
  // vector filtrandolos para luego ser insertados en la pila
  vector<int> almacenamiento;
  int ultimoElemento;

  while (!p.empty()) {
    if (almacenamiento.empty() || p.top() != ultimoElemento) {
      ultimoElemento = p.top();
      almacenamiento.push_back(ultimoElemento);
    }
    p.pop();
  }

  // Con la pila ya vacia y filtrada procedemos a volver a colocar los elementos
  // a la pila

  for (auto it = almacenamiento.rbegin(); it != almacenamiento.rend(); ++it) {
    p.push(*it);
  }
}

int main() {
  stack<int> p;
  for (int x = 0; x < 2; x++)
    for (int i = 0; i < 10; i++)
      for (int j = 0; j < 3; j++) p.push(i);

  transformarpila(p);
  while (!p.empty()) {
    cout << "  " << p.top();
    p.pop();
  }
}
