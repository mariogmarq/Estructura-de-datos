/**
 * @file ficha.h
 * @author Mario García Márquez y Daniel Alconchel Vázquez
 * @date 13 de Octubre de 2020
 */

#ifndef FICHA_H
#define FICHA_H
#include <vector>

/**
 * @brief T.D.A. Ficha
 *
 * Una instancia del tipo de dato abstracto Ficha es un objeto que representa
 * una ficha del tetris. Está representado por una forma seleccionada de un
 * enum.
 */
class ficha {
   public:
    /**
     * @brief enum indicando el tipo de ficha
     */
    enum tipo {
	vacio,
	recta,
	cuadrado,
	t,
	lDerecha,
	lIzquierda,
	zDerecha,
	zIzquierda,
	/**
	 * @warning Solo usado por acumulador
	 */
	activo
    };

    /**
     * @brief constructor base
     */
    ficha();

    /**
     * @brief constructor copia
     * @param orig instancia clase ficha
     */
    ficha(const ficha &orig);

    /**
     * @brief constructor inializando la forma
     * @param forma tipo de la ficha
     * @note se recomienda usar
     */
    ficha(ficha::tipo forma);

    /**
     * @brief destructor de la clase
     */
    ~ficha();

    /**
     * @brief establece la forma de la ficha
     * @param forma la forma a establecer
     */
    void setForma(ficha::tipo forma);

    /**
     * @brief devuelve la forma establecida
     * @return la forma de la ficha
     */
    tipo getForma() const;

    /**
     * @brief devuelve la matriz asociada a la forma de la ficha
     * @return la matriz asociada a la forma de la ficha
     * @note en la matriz solo se marcan las casillas ocupadas y las no ocupadas
     * tendran el tipo tipo::vacio
     * @see ficha::tipo
     */
    std::vector<std::vector<ficha::tipo>> getMatriz() const;

   private:
    /**
     * @brief forma de la ficha
     */
    tipo forma;
};

#endif
