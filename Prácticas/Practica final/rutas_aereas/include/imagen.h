#ifndef __IMAGEN_H
#define __IMAGEN_H
#include "imagenES.h"
#include <cassert>
#include <iostream>
#include <string>
enum Tipo_Pegado { OPACO, BLENDING };
using namespace std;

/**
 * @brief representa un pixel de una imagen a color
 */
struct Pixel {
  unsigned char r, g, b;
  unsigned char transp; // 0 no 255 si
};

/**
 * @brief representacion de una imagen, agrega operaciones de lectura y
 * escritura sobre ella ademas de otros metodos basicos
 */
class Imagen {
private:
  Pixel **data;
  int nf, nc;
  void Borrar();
  void Copiar(const Imagen &I);

public:
  /**
   * @brief constructor por defecto
   */
  Imagen();

  /**
   * @brief constructor con parametros de la clase imagen
   * @param f filas de la imagen
   * @param c columnas de la imagen
   */
  Imagen(int f, int c);

  /**
   * @brief constructor copia
   */
  Imagen(const Imagen &I);

  /**
   * @brief operador de asignacion
   */
  Imagen &operator=(const Imagen &I);

  /**
   * @brief destructor de la clase
   */
  ~Imagen();

  // set y get
  /**
   * @brief getter de la imagen no constante
   */
  Pixel &operator()(int i, int j);

  /**
   * @brief getter de la imagen constante
   */
  const Pixel &operator()(int i, int j) const;

  /**
   * @brief Permite escribir la imagen en un archivo
   * @param nombre nombre del archivo
   */
  void EscribirImagen(const char *nombre);

  /**
   * @brief permite leer una imagen de un archivo
   * @param nombre nombre del archivo
   * @param nombremascara mascara opcional de la foto
   */
  void LeerImagen(const char *nombre, const string &nombremascara = "");
  void LimpiarTransp();
  int num_filas() const { return nf; }
  int num_cols() const { return nc; }
  void PutImagen(int posi, int posj, const Imagen &I,
                 Tipo_Pegado tippegado = OPACO);
  Imagen ExtraeImagen(int posi, int posj, int dimi, int dimj);
};

#endif
