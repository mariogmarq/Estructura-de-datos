/**
 * @author Mario García Márquez y Daniel Alconchel Vázquez
 * @file imagen.cpp
 */

#include "imagen.h"
#include <cassert>
#include <cmath>

#include "imagenES.h"

//Implementacion de la clase imagen

void Imagen::deallocate()
{
    tipo = TipoImagen::IMG_DESCONOCIDO;
    alt = longt = 0;
    delete[] imagen;
    imagen = nullptr;
}

void Imagen::allocate(int alt, int longt, TipoImagen tipo)
{
    deallocate();
    if (tipo == TipoImagen::IMG_PGM)
    {
        imagen = new byte[alt * longt];
        this->alt = alt;
        this->longt = longt;
    }
    if (tipo == TipoImagen::IMG_PPM)
    {
        imagen = new byte[alt * longt * 3];
        this->alt = alt;
        this->longt = longt;
    }
}

void Imagen::copiar(const Imagen &orig)
{
    allocate(orig.altura(), orig.ancho(), orig.tipoImagen());
    int bytesPorPixel = this->tipo == TipoImagen::IMG_PGM ? 1 : 3;

    for (int i = 0; i < alt * longt * bytesPorPixel; ++i)
        this->imagen[i] = orig.imagen[i];
}

Imagen::Imagen()
{
    tipo = TipoImagen::IMG_DESCONOCIDO;
    alt = longt = 0;
    imagen = nullptr;
}

Imagen::~Imagen()
{
    deallocate();
}

Imagen::Imagen(const Imagen &orig)
{
    imagen = nullptr;
    copiar(orig);
}

void Imagen::LeerImagen(const char *nombre)
{
    deallocate();
    tipo = LeerTipoImagen(nombre);

    if (tipo == TipoImagen::IMG_DESCONOCIDO)
        return;

    auto func = tipo == TipoImagen::IMG_PPM ? LeerImagenPPM : LeerImagenPGM;

    imagen = func(nombre, this->alt, this->longt);
}

Imagen::Imagen(const char *nombre)
{
    imagen = nullptr;
    LeerImagen(nombre);
}
void Imagen::EscribirImagen(const char *nombre) const
{
    //if (this->tipo == TipoImagen::IMG_DESCONOCIDO)
    //throw(-1);
    auto func = tipo == TipoImagen::IMG_PPM ? EscribirImagenPPM : EscribirImagenPGM;
    bool x = func(nombre, this->imagen, this->alt, this->longt);
    assert(x);
}

void Imagen::operator=(const Imagen &orig)
{
    copiar(orig);
}

int Imagen::altura() const { return alt; }

int Imagen::ancho() const { return longt; }

byte Imagen::valor(int fila, int columna) const
{

    return this->imagen[fila * longt + columna];
}

void Imagen::asignarPixel(int fila, int columna, byte valor)
{
    this->imagen[fila * longt + columna] = valor;
}

void Imagen::binarizacion(byte umbral, byte oscuridad)
{
    int bytesPorPixel = this->tipo == TipoImagen::IMG_PGM ? 1 : 3;
    for (int i = 0; i < alt * longt * bytesPorPixel; ++i)
        this->imagen[i] = this->imagen[i] >= umbral ? 255 : oscuridad;
}

void Imagen::umbralizar(byte t1, byte t2)
{
    int bytesPorPixel = this->tipo == TipoImagen::IMG_PGM ? 1 : 3;
    for (int i = 0; i < alt * longt * bytesPorPixel; ++i)
        this->imagen[i] = this->imagen[i] <= t2 && this->imagen[i] >= t1 ? this->imagen[i] : 255;
}

Imagen Imagen::zoom(int x1, int y1, int x2, int y2) const
{
    //Comprobamos que las dimensiones son validas
    assert(x1 >= 0 && x2 >= 0 && y1 >= 0 && y2 >= 0);
    assert(x1 < alt && x2 < alt && y1 < longt && y2 < longt);

    //calculamos dimension de la nueva imagen
    int newAlt = abs(2 * (y1 - y2) - 1);
    int newLongt = abs(2 * (x1 - x2) - 1);

    //Comprobamos que las dimensiones no son negativas
    assert(newAlt > 0 || newLongt > 0);

    //Creamos una nueva imagen llamada rv(return value)
    Imagen rv;
    rv.tipo = this->tipo;
    rv.allocate(newAlt, newLongt, this->tipo);

    //Primero copiamos los datos en sus huecos
    for (int i = 0; i < newAlt; i += 2)
        for (int j = 0; j < newLongt; j += 2)
        {
            rv.asignarPixel(i, j, this->valor(x1 + i / 2, y1 + j / 2));
        }

    //Ahora interpolamos las columnas
    for (int i = 1; i < newAlt; i += 2)
        for (int j = 0; j < newLongt; j += 2)
        {
            rv.asignarPixel(i, j, byte(ceil((rv.valor(i - 1, j) + rv.valor(i + 1, j)) / 2.0)));
        }

    //Ahora interpolamos las filas
    for (int i = 0; i < newAlt; i += 2)
        for (int j = 1; j < newLongt; j += 2)
        {
            rv.asignarPixel(i, j, byte(ceil((rv.valor(i, j - 1) + rv.valor(i, j + 1)) / 2.0)));
        }

    return rv;
}

Imagen Imagen::corregirContraste() const
{
    Imagen rv(*this);
    byte max = 0, min = 0;
    int bytesPorPixel = this->tipo == TipoImagen::IMG_PGM ? 1 : 3;

    //se calculan el maximo y el minimo
    for (int i = 0; i < longt * alt * bytesPorPixel; ++i)
    {
        if (rv.imagen[i] > max)
            max = rv.imagen[i];
        if (rv.imagen[i] < min)
            min = rv.imagen[i];
    }

    //aplicamos transformacion lineal
    for (int i = 0; i < longt * alt * bytesPorPixel; ++i)
    {
        rv.imagen[i] = (byte(255 / (max - min)) * rv.imagen[i]);
    }

    return rv;
}

TipoImagen Imagen::tipoImagen() const
{
    return tipo;
}