/**
 * @file juego.h
 * @author Mario García Márquez y Daniel Alconchel Vázquez
 * @date 13 de Octubre de 2020
 */

#ifndef JUEGO_H
#define JUEGO_H
#include "acumulador.h"
#include "cola.h"

class juego {
   private:
    acumulador ac;
    cola cl;
    int piezasJugadas;
    int lineasRotas;
    int dificultad;
    bool jugando;

   public:
    /**
     * @brief imprime el juego
     * @param os instancia clase ostream
     * @see std::ostream
     * @param jg instancia clase juego
     */
    friend std::ostream &operator<<(std::ostream &os, const juego &jg);

    /**
     * @brief metodo alternativo de impresion ya sea porque se desea ventana
     * aparte y no querer usar la salida estandar
     * @warning implementación libre y equivale a la clase Imagen
     */
    void print() const;

    /**
     * @brief constructor base
     */
    juego();

    /**
     * @brief constructor copia
     */
    juego(const juego &orig);

    /**
     * @brief destructor de la clase
     */
    ~juego();

    /**
     * @brief comienza y desarrolla una partida de tetris
     * @warning aqui se incluye toda la lógica del juego
     * @warning finaliza si se fuerza la finalización o si jugando es false(has
     * perdido)
     */
    void jugar();
};

/**
 * @brief imprime el juego
 * @param os instancia clase ostream
 * @see std::ostream
 * @param jg instancia clase juego
 */
std::ostream &operator<<(std::ostream &os, const juego &jg);

#endif
