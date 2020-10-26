/**
 * @author Mario García Márquez y Daniel Alconchel Vázquez
 * @file imagen.cpp
 */

#include "imagen.h"

#include <cmath>

#include "../imagenES/imagenES.h"

// Implementacion de la clase imagen

void Imagen::deallocate() {
    tipo = TipoImagen::IMG_DESCONOCIDO;
    alt = longt = 0;
    delete[] imagen;
    imagen = nullptr;
}

void Imagen::allocate(int alt, int longt, TipoImagen tipo) {
    deallocate();
    if (tipo == TipoImagen::IMG_PGM) {
        this->tipo = TipoImagen::IMG_PGM;
        imagen = new byte[alt * longt];
        this->alt = alt;
        this->longt = longt;
    }
    if (tipo == TipoImagen::IMG_PPM) {
        this->tipo = TipoImagen::IMG_PPM;
        imagen = new byte[alt * longt * 3];
        this->alt = alt;
        this->longt = longt;
    }
}

void Imagen::copiar(const Imagen &orig) {
    this->tipo = orig.tipo;
    allocate(orig.altura(), orig.ancho(), orig.tipoImagen());
    int bytesPorPixel = this->tipo == TipoImagen::IMG_PGM ? 1 : 3;

    for (int i = 0; i < alt * longt * bytesPorPixel; ++i)
        this->imagen[i] = orig.imagen[i];
}

Imagen::Imagen() {
    tipo = TipoImagen::IMG_DESCONOCIDO;
    alt = longt = 0;
    imagen = nullptr;
}

Imagen::~Imagen() { deallocate(); }

Imagen::Imagen(const Imagen &orig) {
    imagen = nullptr;
    copiar(orig);
}

void Imagen::LeerImagen(const char *nombre) {
    deallocate();
    tipo = LeerTipoImagen(nombre);

    if (tipo == TipoImagen::IMG_DESCONOCIDO) return;

    auto func = tipo == TipoImagen::IMG_PPM ? LeerImagenPPM : LeerImagenPGM;

    imagen = func(nombre, this->alt, this->longt);
}

Imagen::Imagen(const char *nombre) {
    imagen = nullptr;
    LeerImagen(nombre);
}
void Imagen::EscribirImagen(const char *nombre) const {
    if (this->tipo == TipoImagen::IMG_DESCONOCIDO) return;
    auto func =
        tipo == TipoImagen::IMG_PPM ? EscribirImagenPPM : EscribirImagenPGM;
    func(nombre, this->imagen, this->alt, this->longt);
}

void Imagen::operator=(const Imagen &orig) { copiar(orig); }

int Imagen::altura() const { return alt; }

int Imagen::ancho() const { return longt; }

byte Imagen::valor(int fila, int columna) const {
    if (fila < 0 || columna < 0 || fila >= alt || columna >= longt) throw(-1);

    return this->imagen[fila * longt + columna];
}

void Imagen::asignarPixel(int fila, int columna, byte valor) {
    if (fila < 0 || columna < 0 || fila >= alt || columna >= longt) throw(-1);
    this->imagen[fila * longt + columna] = valor;
}

void Imagen::binarizacion(byte umbral, byte oscuridad) {
    int bytesPorPixel = this->tipo == TipoImagen::IMG_PGM ? 1 : 3;
    for (int i = 0; i < alt * longt * bytesPorPixel; ++i)
        this->imagen[i] = this->imagen[i] >= umbral ? 255 : oscuridad;
}

void Imagen::umbralizar(byte t1, byte t2) {
    int bytesPorPixel = this->tipo == TipoImagen::IMG_PGM ? 1 : 3;
    for (int i = 0; i < alt * longt * bytesPorPixel; ++i)
        this->imagen[i] = this->imagen[i] <= t2 && this->imagen[i] >= t1
                              ? this->imagen[i]
                              : 255;
}

Imagen Imagen::zoom(int x1, int y1, int x2, int y2) const {
    // Comprobamos que las dimensiones son validas
    if (x1 < 0 || x2 < 0 || y1 < 0 || y2 < 0) throw(-1);
    if (x1 >= alt || x2 >= alt || y1 >= longt || y2 >= longt) throw(-1);

    // calculamos dimension de la nueva imagen
    int newAlt = 2 * (y2 - y1) - 1;
    int newLongt = 2 * (x2 - x1) - 1;

    // Comprobamos que las dimensiones no son negativas
    if (newAlt <= 0 || newLongt <= 0) throw(-1);

    // Creamos una nueva imagen llamada rv(return value)
    Imagen rv;
    rv.allocate(newAlt, newLongt, this->tipo);
    rv.tipo = this->tipo;

    // Primero copiamos los datos en sus huecos
    for (int i = 0; i < newAlt; i += 2)
        for (int j = 0; j < newLongt; j += 2) {
            rv.asignarPixel(i, j, this->valor(x1 + i / 2, y1 + j / 2));
        }
    // Ahora interpolamos las filas
    for (int i = 1; i < newAlt; i += 2)
        for (int j = 0; j < newLongt; ++j) {
            rv.asignarPixel(
                i, j,
                byte(ceil((rv.valor(i - 1, j) + rv.valor(i + 1, j)) / 2.0)));
        }

    // Ahora interpolamos las columnas
    for (int i = 0; i < newAlt; ++i)
        for (int j = 1; j < newLongt; j += 2) {
            rv.asignarPixel(
                i, j,
                byte(ceil((rv.valor(i, j - 1) + rv.valor(i, j + 1)) / 2.0)));
        }

    return rv;
}

Imagen Imagen::corregirContraste() const {
    Imagen rv(*this);
    byte max = 0, min = 255;
    int bytesPorPixel = this->tipo == TipoImagen::IMG_PGM ? 1 : 3;

    // se calculan el maximo y el minimo
    for (int i = 0; i < longt * alt * bytesPorPixel; ++i) {
        if (rv.imagen[i] > max) max = rv.imagen[i];
        if (rv.imagen[i] < min) min = rv.imagen[i];
    }

    // aplicamos transformacion lineal

    for (int i = 0; i < longt * alt * bytesPorPixel; ++i) {
        rv.imagen[i] = int((255.0 / (max - min)) * (rv.imagen[i] - min));
    }

    return rv;
}

Imagen Imagen::icono(int nf, int nc) const {
    // Comprobamos que el nuevo tamaño es correcto
    if (nf < 0 || nc < 0) throw(-1);
    if (nf >= alt || nc >= longt) throw(-1);

    Imagen rv;
    rv.allocate(nf, nc, this->tipo);
    int av;
    byte celda;

    av = alt / nf;
    for (int i = 0; i < nf; i++) {
    }

    return rv;
}

TipoImagen Imagen::tipoImagen() const { return tipo; }

