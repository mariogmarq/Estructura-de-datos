/**
 * @author Mario Garcia Marquez y Daniel Alconchel Vazquez
 * @file paises.h
 * @brief implementa el TDA Paises
 */

#ifndef PAISES_H
#define PAISES_H

#include "pais.h"
#include <map>

/**
 * @brief TDA Paises, representa todos los paises que se pueden encontrar en una ruta aerea
 * @note usar junto a rutas aereas para determinar los paises de estas
 */
class Paises {
    private:
        std::map<Punto, Pais> paises;

    public:
        /**
         * @brief constructor por defecto
         */
        Paises();

        /**
         * @brief sobrecarga del operador [] para obtener un pais mediante su localizacion
         * @param localizacion localizacion del pais a buscar
         * @return el pais con la ubicacion asociada
         */
        Pais operator[](Punto localizacion) const;

        /**
         * @brief agrega un nuevo pais al objeto
         * @param pais pais a ser agregado
         * @note la clave del pais sera la localizacion de este
         */
        void introducirPais(Pais pais);
};

/**
   * @brief sobrecarga del operador >>
   * @param is flujo de entrada
   * @param paises objeto al que introducir datos
   * @note seguir formato de paises.txt, defiere del de las rutas aereas
   */
  std::istream& operator>>(std::istream& is, Paises& paises);

#endif