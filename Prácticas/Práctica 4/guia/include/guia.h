/**
 * @file guia.h
 * @author Mario García Márquez
 * @brief declaración de la clase guia y sus metodos
 */
#ifndef GUIA_H
#define GUIA_H

// Includes
#include <iostream>
#include <map>
#include <vector>

/**
 * @brief Sobrecarga del operador >> para pair de strings
 * @return flujo istream tal y como indica el estándar de C++
 */
std::istream &operator>>(std::istream &is,
                         std::pair<std::string, std::string> &d);

/**
 * @brief Clase guia teléfono
 */
class Guia_Tlf {
 private:
  std::map<std::string, std::string> datos;

 public:
  /**
   * @brief constructor por defecto de la clase
   */
  Guia_Tlf() {}

  /**
   * @brief constructor copia de la clase
   * @param gt
   */
  Guia_Tlf(const Guia_Tlf &gt);

  /**
   * @brief destructor de la clase
   */
  ~Guia_Tlf() {}

  /**
   * @brief operador de asignacion de la clase
   * @param gt Guía que hace de rvalue
   * @return una referencia a la guía asignada
   */
  Guia_Tlf &operator=(const Guia_Tlf &gt);

  /**
   * @brief Acceso a un elemento
   * @param nombre: nombre del elemento elemento acceder
   * @return devuelve el valor asociado a un nombre, es decir el teléfono
   */
  std::string &operator[](const std::string &nombre);

  /**
   * @brief Insert un nuevo telefono
   * @param nombre: nombre clave del nuevo telefono
   * @param tlf: numero de telefono
   * @return : un pair donde first apunta al nuevo elemento insertado y bool es
   * true si se ha insertado el nuevo tlf o false en caso contrario
   */
  std::pair<std::map<std::string, std::string>::iterator, bool> insert(
      std::string nombre, std::string tlf);

  /**
   * @brief Insert un nuevo telefono
   * @param p: pair con el nombre y el telefono asociado
   * @return : un pair donde first apunta al nuevo elemento insertado y bool es
   * true si se ha insertado el nuevo tlf o false en caso contrario
   */
  std::pair<std::map<std::string, std::string>::iterator, bool> insert(
      std::pair<std::string, std::string> p);

  /**
   * @brief Borrar un telefono
   * @param nombre: nombre que se quiere borrar
   * @note: en caso de que fuese un multimap borraria todos con ese nombre
   */
  void borrar(const std::string &nombre);

  /**
   * @brief Union de guias de telefonos
   * @param g: guia que se une
   * @return: una nueva guia resultado de unir el objeto al que apunta this y g
   */
  Guia_Tlf operator+(const Guia_Tlf &g);

  /**
   * @brief Diferencia de guias de telefonos
   * @param g: guia que se une
   * @return: una nueva guia resultado de la diferencia del objeto al que apunta
   * this y g
   */
  Guia_Tlf operator-(const Guia_Tlf &g);

  /**
   * @brief Escritura de la guia de telefonos
   * @param os: flujo de salida. Es MODIFICADO
   * @param g: guia de telefonos que se escribe
   * @return el flujo de salida
   */
  friend std::ostream &operator<<(std::ostream &os, Guia_Tlf &g);

  /**
   * @brief Lectura de la guia de telefonos
   * @param is: flujo de entrada. ES MODIFICADO
   * @param g: guia de telefonos. ES MODIFICADO
   * @return el flujo de entrada
   */
  friend std::istream &operator>>(std::istream &is, Guia_Tlf &g);

  /**
   * @brief Clase iteradora de Guia_Tlf
   */
  class const_iterator {
   private:
    std::map<std::string, std::string>::const_iterator it;

    const_iterator(std::map<std::string, std::string>::const_iterator it);

    friend class Guia_Tlf;

   public:
    const_iterator();

    const_iterator(const const_iterator &it);

    const_iterator &operator=(const const_iterator &it);

    const_iterator &operator++();

    const_iterator &operator--();

    std::pair<const std::string, std::string> operator*() const;

    bool operator!=(const const_iterator &it) const;

    bool operator==(const const_iterator &it) const;
  };

  class iterator {
   private:
    std::map<std::string, std::string>::iterator it;

    iterator(std::map<std::string, std::string>::iterator it);

    friend class Guia_Tlf;

   public:
    iterator();

    iterator(const iterator &it);

    iterator &operator=(const iterator &it);

    iterator &operator++();

    iterator &operator--();

    std::pair<const std::string, std::string> &operator*();

    bool operator!=(const iterator &it) const;

    bool operator==(const iterator &it) const;
  };

  /**
   * @brief devuelve un iterador al principio de la guia
   * @return un iterador al principio de la guia
   */
  iterator begin();

  /**
   * @brief devuelve un iterador a despues del ultimo elemento de la guia
   * @return iterador a despues del ultimo elemento de la guia
   */
  iterator end();

  /**
   * @brief devuelve un iterador al principio de la guia
   * @return un iterador al principio de la guia
   */
  const_iterator cbegin() const;

  /**
   * @brief devuelve un iterador a despues del ultimo elemento de la guia
   * @return iterador a despues del ultimo elemento de la guia
   */
  const_iterator cend() const;

  /**
   * @brief Fusiona g, h y el diccionario actual en este
   * @param g guia que se fusionará
   * @param h guia que se fusionará
   */
  void Merge(const Guia_Tlf &g, const Guia_Tlf &h);

  /**
   * @brief modifica el numero asociado a nombre
   * @param nombre Nombre de la persona a modificar su número
   * @param nuevoNumero Nuevo número a introducir
   * @return Si se ha podido modificar el número
   */
  bool Modificar(std::string nombre, std::string nuevoNumero);

  /**
   * @brief devuelve todos los números de aquellas personas cuyo nombre empiece
   * por letra
   * @param letra letra por la que debe empezar el nombre
   * @return array de los números y nombres devueltos
   */
  std::vector<std::pair<const std::string, std::string>> Indice(
      const char letra) const;

  /**
   * @brief devuelve un rango del diccionario
   * @param principio Principio del rango
   * @param end Final del rango
   * @return Array que contiene los elementos
   */
  std::vector<std::pair<const std::string, std::string>> Rango(
      const_iterator principio, const_iterator end) const;
};

#endif  // GUIA_H

