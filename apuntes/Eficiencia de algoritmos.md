# Eficiencia de algoritmos
Existen distintos tipos de algoritmos para resolver problemas, sin embargos no todos
consumen el mismo tiempo y recursos. El tiempo de ejecución de problema depende del tamaño del
mismo. Para comparar algoritmos se debe hacer en el caso de tamaño n.

## Índice
- [Familias de orden de eficiencia](##Familias de orden de eficiencia)
- [Notación O](##Notación O)


## Familias de orden de eficiencia
Decimos que un algoritmo pertenece a una familia de orden de eficiencia si esta acotado a
partir de cierto punto por otra función. Las más comunes son:
    - lineal: n
    - cuadrático: n^2
    - polinómico: n^k (k natural)
    - log n: logarítmico
    - exponencial: c^n (c constante)

insertar foto de familias aquí


Diremos que un algoritmo es más eficiente que otro si su crecimiento es menor.

## Notación O
Diremos que f(n) pertenece a O(g(n)) si a partir de un cierto punto x, existe una constante que
cumpla que f(x) <= cg(n). La gracia es obtener la mejor cota para nuestra función f(n).

Tambien tenemos que tener en cuenta en la práctica el espacio que tengamos y el tamaño de
nuestro problema.

Gracias a esta notación podemos quitarnos los miembros de menor orden y las constantes. Esto
significa que la función 3n^2 + 3 pertenece a O(n^2). Esto se debe a que se evalua cuando n
tiende a infinito. Esta es la idea de la notación O, el asociar funciones que podrían ser mucho más complejas con
familias más comunes y con las que son más fácil operar.

La eficiencia siempre se mide para el **peor** de los casos.

insertar foto de jerarquía de funciones
