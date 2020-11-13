/**
 * @file 20.cpp
 * @author Mario García Márquez
 * @brief implementacion de rotacion
 */
#include <iostream>
#include <queue>
using namespace std;

/**
 * @brief mueve al final de la cola todos los elementos hasta el primer par
 * @param c la cola a ser rotada
 */
void rotacion(queue<int>& c) {
  while (c.front() % 2 != 0) {
    c.push(c.front());
    c.pop();
  }
}

int main() {
  queue<int> c;
  c.push(1);
  c.push(3);
  c.push(5);
  c.push(2);
  c.push(7);
  rotacion(c);

  while (!c.empty()) {
    cout << "  " << c.front();
    c.pop();
  }
}
