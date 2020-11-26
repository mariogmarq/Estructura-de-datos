/**
 * @file diccionario.h
 * @author Mario García Márquez
 * @brief declaración de la clase diccionario y sus metodos
 */
#ifndef DICCIONARIO_H
#define DICCIONARIO_H

// Includes
#include <list>

/**
 * @brief Tipo elemento que define el diccionario. T es el tipo de dato asociado
 * a una clave que no se repite y list<U> es una lista de datos asociados a la
 * clave de tipo T.
 */
template <class T, class U>
struct data {
  T clave;
  std::list<U> info_asoci;
};

/**
 * @brief Comparador de datos respecto al tipo T. Puede usarse como functor
 * @param d1 primer data
 * @param d2 segundo data
 * @return devuelve si d1 < d2
 */
template <class T, class U>
bool operator<(const data<T, U> &d1, const data<T, U> &d2) {
  return d1.clave < d2.clave;
}

/**
 * @brief Un diccionario es una lista de data
 */
template <class T, class U>
class Diccionario {
 private:
  std::list<data<T, U>> datos;
  void Copiar(const Diccionario<T, U> &D);
  void Borrar();  // Borra el diccionario

 public:
  /**
   * @brief constructor por defecto
   */
  Diccionario();
  /**
   * @brief constructor copia
   */
  Diccionario(const Diccionario &D);
  /**
   * @brief destructor de la clase
   */
  ~Diccionario();
  /**
   * @brief Operator de asignacion
   */
  Diccionario<T, U> &operator=(const Diccionario<T, U> &D);
  /**
   * @brief Clase iteradora de diccionario
   */
  class const_iterator {
   private:
    typename std::list<data<T, U>>::const_iterator it;
    const_iterator(typename std::list<data<T, U>>::const_iterator it);
    friend class Diccionario<T, U>;

   public:
    const_iterator();
    const_iterator(const const_iterator &it);
    const_iterator &operator=(const const_iterator &it);
    const_iterator &operator++();
    const_iterator &operator--();
    data<T, U> operator*() const;

    bool operator!=(const const_iterator &it) const;
    bool operator==(const const_iterator &it) const;
  };

    class iterator {
    private:
        typename std::list<data<T, U>>::iterator it;
        iterator(typename std::list<data<T, U>>::iterator it);
        friend class Diccionario<T, U>;

    public:
        iterator();
        iterator(const iterator &it);
        iterator &operator=(const iterator &it);
        iterator &operator++();
        iterator &operator--();
        data<T, U> &operator*();

        bool operator!=(const iterator &it) const;
        bool operator==(const iterator &it) const;
    };
  /**
   * @brief devuelve un iterador al principio del diccionario
   * @return un iterador al principio del diccionario
   */
  iterator begin();
  /**
   * @brief devuelve un iterador a despues del ultimo elemento del diccionario
   * @return iterador a despues del ultimo elemento del diccionario
   */
  iterator end();

    /**
     * @brief devuelve un iterador al principio del diccionario
     * @return un iterador al principio del diccionario
     */
    const_iterator cbegin() const;
    /**
     * @brief devuelve un iterador a despues del ultimo elemento del diccionario
     * @return iterador a despues del ultimo elemento del diccionario
     */
    const_iterator cend() const;

    /**
   * @brief busca la clave p en el diccionario
   * @return un iterador a donde esta la clave, si no esta devuelve end() y deja
   * el iterador de salida apuntando a donde deberia estar
   */
  bool Esta_Clave(const T &p, typename std::list<data<T, U>>::iterator &it_out);

  /**
   * @brief Inserta un nuevo registro en el diccionario
   */
  void Insertar(const T &clave, const std::list<U> &info);

  /**
   * @brief incluye una nueva información asociada a una clave en el diccionario
   * @note si la clave no esta se inserta
   */
  void AddSignificado_Palabra(const U &s, const T &p);

  /**
   * @brief devuelve informacion asociada a la clave p
   * @param p la clave a ser comprobada
   * @return la informacion asociada a p
   * @note en caso de que p no exista se devuelve una lista vacia
   */
  std::list<U> getInfo_Asoc(const T &p);

  /**
   * @brief devuelve el tamaño del diccionario
   * @return tamaño del diccionario
   */
  int size() const;

  /**
   * @brief borra elemento mediante una clave dada
   * @param p la clave a ser eliminada
   */
  void borrarEntrada(const T &p);

  /**
   * @brief hace merge en este diccionario con D
   * @param D diccionario a ser fusionado
   */
  void Merge(const Diccionario<T, U> &D);

  /**
   * @brief hace en este diccionario la diferencia de dos diccionarios
   * @param D diccionario que "resta"
   * @note si una clave esta en un diccionario se elimina del otro
   */
  void Diferencia(const Diccionario<T, U> &D);

  /**
   * @brief devuelve elementos en un rango de claves
   * @return una lista con elementos en un rango de claves
   */
  std::list<data<T, U>> Rango(const T& t1, const T& t2) const;

};



#include "../src/diccionario.cpp"
#endif
