# Reto 1
### Por Mario García Márquez

## Ejercicio 1
### a)
En este caso tenemos una complejidad de O(nlog(n)). Esto se debe a que tenemos 3 for anidados. El
primero tiene una complejidad de O(n), el segundo siempre va a tomar 4-5 iteraciones así que tiene
una complejidad de O(1) y el tercero tiene una complejidad de O(log(n)). Por tanto al estar anidados
al multiplicar las complejidades obtenemos una total de O(nlog(n)).

### b)
La complejidad de esta función es de O(nlog(n)). Esto se debe a que tenemos dos partes de código con
compejidad no constante que corresponden al bloque if y al bloque else de la función. Escogeremos el
bloque del else para medir la complejidad de la función pues al ser dos bloques independientes la
complejidad del programa equivale a la mayor complejidad de un bloque. 

El motivo para escoger el else es que tanto para el if como para el else el primer for es igual. Sin
embargo el segundo se puede apreciar que tiene más iteraciones el del else que el del if. De todos
modos la complejidad de ambos bloques es de O(nlog(n)).

El primer for tiene una complejidad de O(log(n)) dado que k es multiplicado por 2 en cada iteración.
El segundo for se ejecuta n veces. Dado que ambos bucles están anidados deducimos que la complejidad
del bloque y por tanto de la función es de O(nlog(n)).

### c)
La complejidad de la función es de O(nlog(n)). Esto se debe a que el bloque cuenta con dos bucles:
un do while que se ejecuta un total de n veces y un while anidado con el do while.

El bucle do while es evidente que tiene una complejidad propia de O(n). Sin embargo el bucle
anidado se ejecuta O(log(n)) veces pues j es multiplicado por 2 en cada iteración de este. Al ser
código anidado llegamos a la conclusión de que la eficiencia del código es O(nlog(n)).

### d)
Este bloque de código también tiene una complejidad de O(nlog(n)). Este es muy parecido al anterior
cambiando sin embargo el las iteraciones del while interno que pasan de ser log(i) iteraciones y el
inicio del contador i. 

Sin embargo gracias a la notación O, que evalua cuando n tiende a infinito, resulta sencillo probar
que la complejidad es muy similar a la del apartado c). Por lo tanto la complejidad de la función es
de O(nlog(n)).


## Ejercicio 2
### a)
En este caso la complejidad de la función es de O(n^2). Esto se debe a que el bucle de por si es de
complejidad O(n) y en cada iteración se ejecutan una vez fin, elemento y borrar de complejidad O(n).
Sin embargo estas 3 son independientes de si mismas por lo que la complejidad todas juntas es la
máxima, es decir O(n). Como se ejecuta n veces debido al bucle deducimos que la función tiene una
complejidad de O(n^2) en este caso.

En este caso no se puede disminuir la complejidad de la función pues siempre va a ser O(n^2) debido
a que en cada iteración se debe hacer una llamada a elemento. Sin embargo un cambio que se le puede
hacer para mejor su eficiencia es guardar el valor de fin(L) en una variable para tener que
llamar así una sola vez a la función.

```c++
int aux, p, final;
final = fin(L);
for(p=primero(L);p!=final;){}
```

### b)
La complejidad de la función es O(n^2) ya que en cada iteración del bucle se llama a fin que tiene
una complejidad de O(n). Por lo tanto la complejidad de la función es O(n^2).

El arreglo hecho en la función a) también serviría para esta y además en este caso sí que cambiaría
la complejidad de la función pasando de ser O(n) dado que solo habría una llamada a fin y su
complejidad de sumaría con la del bucle haciendo la complejidad total de la función de
O(máx(n,n))=O(n).

### c)
En este caso la complejidad del código sería de O(n) pues el bucle tiene que ejecutarse n veces. Dado que esto no se puede cambiar afirmamos que no se puede disminuir la complejidad del código para esta función.
