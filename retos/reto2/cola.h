/**
 * @file cola.h
 * @author Mario García Márquez y Daniel Alconchel Vázquez
 * @date 13 de Octubre de 2020
 */

#ifndef COLA_H
#define COLA_H
#include <ostream>

#include "ficha.h"

/**
 * @brief T.D.A. Cola
 *
 * Una instancia del tipo de dato abstracto cola es un objeto que contiene las 4
 * siguientes fichas a jugar
 */
class cola {
   private:
    /**
     * @brief lista enlazada para representar la cola
     */
    struct elemento {
	ficha valor;
	elemento *siguiente;
    };

    /**
     * @brief representacion interna de la cola como una lista enlazada cerrada
     * @note el ultimo elemento de la lista apunta al primer elemento de esta
     * como el tamaño de la lista siempre es 4 elementos nos aporta una mayor
     * facilidad a la hora de extraer fichas
     */
    elemento *lista;

   public:
    /**
     * @brief constructor de cola
     * @note genera 4 fichas aleatorias y las mete en la cola
     */
    cola();

    /**
     * @brief constructor copia
     * @param orig instancia clase cola
     */
    cola(const cola &orig);

    /**
     * @brief destructor de la clase
     */
    ~cola();

    /**
     * @brief devuelve un vector con las componentes de la lista
     * @return std::vector con todas las componentes de la lista
     */
    std::vector<ficha> getFichas() const;

    /**
     * @brief devuelve el primer elemento de la lista, lo devuelve, lo elimina y
     * añade uno nuevo al final
     * @return la primera ficha de la lista
     */
    ficha sacarFicha();

    /**
     * @brief imprime el cola
     * @param os instancia clase ostream
     * @see std::ostream
     * @param cl instancia clase cola
     */
    friend std::ostream &operator<<(std::ostream &os, const cola &cl);
};

/**
 * @brief imprime el cola
 * @param os instancia clase ostream
 * @see std::ostream
 * @param cl instancia clase cola
 */
std::ostream &operator<<(std::ostream &os, const cola &cl);

#endif
