#include "imagen.h"

int main(int nargs, const char** vargs) {
    Imagen img(vargs[1]);
    int x1 = img.ancho() / 4;
    int x2 = img.ancho() * 3 / 4;
    int y1 = img.altura() / 4;
    int y2 = img.altura() * 3 / 4;

    img.zoom(x1, y1, x2, y2).EscribirImagen("Lol");
}
