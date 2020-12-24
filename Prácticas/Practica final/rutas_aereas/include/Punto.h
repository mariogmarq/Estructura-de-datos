/**
 * @author Mario Garcia Marquez y Daniel Alconchel Vazquez
 * @file punto.h
 * @brief descripcion de TDA punto que se usara para indicar la posicion de los
 * paises en el mapa
 */

#ifndef PUNTO_H
#define PUNTO_H

#include <utility>
#include <iostream>

/**
 * @brief TDA Punto, representa un punto en coordenadas geograficas
 */
class Punto {
private:
  float latitud;
  float longitud;

public:
  /**
   * @brief contructor por defecto de la clase punto
   */
  Punto();

  /**
   * @brief contructor con parametros de la clase punto
   * @param latitud latitud del punto (entre 90 y -90)
   * @param longitud longitud del punto (entre -180 y 180)
   * @note en la longitud -180 y 180 representan el mismo valor
   */
  Punto(float latitud, float longitud);

  /**
   * @brief getter de la latitud
   * @return la latitud del punto
   */
  float GetLatitud() const;

  /**
   * @brief getter de la longitud
   * @return la longitud del punto
   */
  float GetLongitud() const;

  /**
   * @brief setter de la latitud
   * @param latitud nueva latitud del punto
   */
  void setLatitud(float latitud);

  /**
   * @brief setter de la longitud
   * @param longitud nuevo longitud del punto
   */
  void setLongitud(float longitud);

  /**
   * @brief Aplica una transformacion lineal a la longitud y latitud tal que
   * devuelve una nueva longitud comprendida entre [0, nLong) y latitud
   * comprendida entre [0,nLat)
   * @param nLat nueva valor maximo para la latitud, debe de ser positivo
   * @param nLong nuevo valor maximo para la longitud, debe de ser positivo
   * @return un pair con los valores nuevos calculados, siendo en orden la
   * latitud y la longitud
   * @note utilizar esta funcion para obtener la posicion del punto en una
   * imagen de dimensiones nLat*nLong
   */
  std::pair<float, float> transLineal(float nLat, float nLong) const;

  /**
   * @brief operador de comparacion
   */
  bool operator==(const Punto& orig) const {
    return this->latitud == orig.latitud && this->longitud == orig.longitud;
  }
};

  /**
   * @brief sobrecarga del operador >>
   * @param is flujo de entrada
   * @param p punto al que introducir datos
   * @note seguir formato de paises.txt, difiere del formato de las rutas aereas
   */
  std::istream& operator>>(std::istream& is, Punto& p);


#endif