#include "imagen.h"
#include <cmath>
#include <iostream>

int main(int nargs, const char **vargs)
{
    Imagen img(vargs[1]);
    int x1 = abs(img.ancho() / 4);
    int x2 = abs(img.ancho() * 3 / 4);
    int y1 = abs(img.altura() / 4);
    int y2 = abs(img.altura() * 3 / 4);
    std::cout << img.tipoImagen();
    img.zoom(64, 192, 64, 192)
        .EscribirImagen("Lol");
}