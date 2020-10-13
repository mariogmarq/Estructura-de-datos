/**
 * @file acumulador.h
 * @author Mario García Márquez y Daniel Alconchel Vázquez
 * @date 13 de Octubre de 2020
 */

#ifndef ACUMULADOR_H
#define ACUMULADOR_H
#include <ostream>

#include "ficha.h"

/**
 * @brief T.D.A. Acumulador
 *
 * Una instancia del tipo acumulador representa el tablero donde vamos a jugar.
 * Se encarga de almacenar las piezas depositadas durante la partida.
 * También almacena la ficha que estamos jugando en un determinado instante de
 * tiempo.
 */

class acumulador {
   private:
    std::vector<std::vector<ficha::tipo>> tablero;

    // Forma de la ficha que esta cayendo, usarse para cambiar tablero cuando
    // la ficha pase a depositada
    ficha::tipo formaCayendo;

   public:
    /**
     * @brief constructor base
     * @note inicializa el tablero a ficha::tipo::vacio
     * @see ficha::tipo
     */
    acumulador();

    /**
     * @brief constructor copia
     * @param orig instancia de la clase acumulador
     */
    acumulador(const acumulador &orig);

    /**
     * @brief constructor con dimensiones
     * @param h altura del tablero
     * @param w anchura del tablero
     * @note inicializa el tablero con esas dimensiones a ficha::tipo::vacio
     * @see ficha::tipo
     */
    acumulador(int h, int w);

    /**
     *  @brief destructor de la clase
     */
    ~acumulador();

    /**
     * @brief imprime el tablero
     * @param os instancia clase ostream
     * @see std::ostream
     * @param ac instancia clase acumulador
     */
    friend std::ostream &operator<<(std::ostream &os, const acumulador &ac);

    /**
     * @brief coloca la ficha para caer arriba del tablero
     * @param f la ficha que se deja caer
     * @note la coloca en el centro de la parte superior del tablero
     */
    void dejarCaer(ficha f);

    /**
     * @brief indica si la partida ha acabado
     * @retval true si la partida ha acabado(no se puede dejar caer otra ficha)
     */
    bool finDePartida() const;

    /**
     * @brief rota la ficha actual
     * @param horario decide si rotar la ficha en sentido horario o antihorario
     * @note si la ficha no puede ser rotada se mantendrá como está
     */
    void rotarFicha(bool horario);

    /**
     * @brief mueve la ficha actual
     * @param derecha mueve la ficha a la derecha si es true. En caso contrario
     * hacia la izquierda
     * @note si la ficha no puede ser movida se mantendrá como está
     */
    void moverFicha(bool derecha);

    /**
     * @brief deposita la ficha actual
     * @warning usar para bajar la ficha directamente
     */
    void depositarFicha();

    /**
     * @brief determina si la ficha puede seguir cayendo o esta depositada
     * @retval true si la ficha puede seguir cayendo
     * @note en caso de que la ficha este depositada se cambiaran los
     * tipo::activo del tablero por tipo::forma
     */
    bool puedeCaer();

    /**
     * @brief baja la ficha una casilla
     * @warning llamar periodicamente con un reloj, aumentar el reloj para mayor
     * dificultad
     */
    void ticDeReloj();

    /**
     * @brief comprueba si hay filas llenas
     * @retval true si hay filas llenas
     */
    bool filaLlena() const;

    /**
     * @brief borra las filas llenas
     * @return la cantidad de filas eliminadas
     * @note usar con acumulador::filaLlena()
     * @see acumulador::filaLlena()
     */
    int limpiarFilas();
};

/**
 * @brief imprime el tablero
 * @param os instancia clase ostream
 * @see std::ostream
 * @param ac instancia clase acumulador
 * @warning nota para el profesor, no usamos clase imagen ya que como hemos
 * implementado el acumulador solo hace falta "colorear", es decir, asociar una
 * imagen nxn a cada ficha::tipo
 */
std::ostream &operator<<(std::ostream &os, const acumulador &ac);

#endif
