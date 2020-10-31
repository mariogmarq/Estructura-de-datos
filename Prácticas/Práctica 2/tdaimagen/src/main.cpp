#include "imagen.h"

int main(int nargs, const char** vargs) {
    Imagen img(vargs[1]);
    int x = img.altura()/2;
    int y = img.ancho()/2;

    img.icono(x,y).EscribirImagen("Arrebatao");
}
