/**
 * @author Mario Garcia Marquez y Daniel Alconchel Vazquez
 * @brief Descripcion del TDA pais
 * @file pais.h
 */

#ifndef PAIS_H
#define PAIS_H

#include "punto.h"
#include <string>

/**
 * @brief TDA Pais, representa a un pais de una ruta aerea
 */
class Pais{
    private:
        Punto localizacion;
        std::string nombre;
        std::string bandera;        
        std::string carpetaBanderas;
    public:

        /**
         * @brief constructor por defecto
         */
        Pais();

        /**
         * @brief constructor de la clase pais
         * @param localizacion localizacion del pais
         * @param nombre nombre del pais
         * @param folder directorio donde estara bandera
         * @param bandera nombre del archivo ppm de la bandera
         */
        Pais(Punto localizacion, std::string nombre, std::string folder, std::string bandera);

        /**
         * @brief getter de la localizacion del pais
         * @return la localizacion del pais
         */
        Punto Localizacion() const;

        /**
         * @brief getter del nombre del pais
         * @return el nombre del pais
         */
        std::string Nombre() const;

        /**
         * @brief establece la localizacion del pais
         * @param localizacion la nueva localizacion del pais
         */
        void setLocalizacion(Punto localizacion);

        /**
         * @brief establece el nombre del pais
         * @param nombre nuevo nombre del pais
         */
        void setNombre(std::string nombre);

        /**
         * @brief estable la bandera del pais
         * @param folder directorio donde esta almacenada la bandera del pais
         * @param bandera nombre de la bandera del pais
         */
        void setBandera(std::string folder, std::string bandera);
};

/**
   * @brief sobrecarga del operador >>
   * @param is flujo de entrada
   * @param p pais al que introducir datos
   * @note seguir formato de paises.txt (distinto para puntos)
   */
  std::istream& operator>>(std::istream& is, Pais& p);

#endif