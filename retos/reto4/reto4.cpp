/**
 * @file reto4.cpp
 * @author mariogmarq
 * @brief resolución del reto 4 de la asignatura de estructura de datos
 * @warning no ejecutar problemas memoria dinamica
 */
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

/**
 * @class Arbol representa a un arbol binario de enteros
 */
class Arbol {
 public:
  struct Nodo {
    int valor;
    Nodo* izquierda;
    Nodo* derecha;
  };

  Arbol() { root = nullptr; }

  ~Arbol() {
    clear(this->root);
    delete root;
  }

  void clear(Nodo* r) {
    if (r == nullptr) return;
    if (r->izquierda != nullptr) clear(r->izquierda);
    if (r->derecha != nullptr) clear(r->izquierda);
    delete r->izquierda;
    delete r->derecha;
  }

  Nodo* root;
};

/**
 * @brief para el algoritmo usaremos un preorden con caracteres centilas, estos
 * serán 3, x si no el nodo no tiene hijos ni a la derecha ni a la izquierda, d
 * si no tiene hijos a la izquierda pero si a la derecha y i si el nodo no tiene
 * hijos a la derecha pero si a la izquierda
 */
istream& operator>>(istream& is, Arbol::Nodo*& n) {
  n = new Arbol::Nodo;
  is >> n->valor;
  auto guardian = char(is.peek());
  if (guardian == -1) return is;
  if (guardian == ' ') {
    guardian = is.get();
    guardian = char(is.peek());
  }

  if (guardian == 'x') {
    n->derecha = n->izquierda = nullptr;
    guardian = is.get();
    return is;
  }
  if (guardian == 'i') {
    n->derecha = nullptr;
    guardian = is.get();
    is >> n->izquierda;
    return is;
  }
  if (guardian == 'd') {
    n->izquierda = nullptr;
    guardian = is.get();
    is >> n->derecha;
    return is;
  }

  is >> n->izquierda >> n->derecha;

  return is;
}

ostream& operator<<(ostream& os, Arbol::Nodo* n) {
  os << n->valor << " ";
  if (n->derecha == nullptr && n->izquierda == nullptr) os << "x ";
  if (n->derecha == nullptr && n->izquierda != nullptr) {
    os << "i " << n->izquierda;
  }
  if (n->derecha != nullptr && n->izquierda == nullptr) {
    os << "d " << n->derecha;
  }
  if (n->derecha != nullptr && n->izquierda != nullptr) {
    os << n->izquierda << n->derecha;
  }
  return os;
}

istream& operator>>(istream& is, Arbol& ar) {
  is >> ar.root;
  return is;
}

ostream& operator<<(ostream& os, Arbol& ar) {
  os << ar.root;
  return os;
}

int main() {
  string s("1 2 x 3 5 i 6 x 7 x\0");
  stringstream is(s);
  Arbol ar;
  is >> ar;
  cout << ar;
}

