/**
 * @author Mario Garcia Marquez y Daniel Alconchel Vazquez
 * @file ruta.h
 * @brief descripcion de la clase ruta
 */

#ifndef RUTA_H
#define RUTA_H

#include "Paises.h"
#include <vector>

/**
 * @class Clase ruta para almacenar una ruta aerea
 */

class Ruta {
private:
    Paises *paises; // Puntero a nuestro almacen de paises, para poder determinar
                  // datos sobre ellos, no es memoria dinamica!!!
    std::string nombre; //nombre de la ruta
    std::vector<Punto> recorrido; //Puntos por donde pasa la ruta, en orden

public:
    /**
     * @brief constructor por defecto
     */
    Ruta();

    /**
     * @brief constructor con direccion almacen de paises
     * @param paises datos de los paises de las rutas
     */
    Ruta(Paises* paises);

    /**
     * @brief constructor copia
     */
    Ruta(const Ruta& orig) = default;

    /**
     * @brief destructor de la clase
     * @warning no borra paises
     */
    ~Ruta() = default;

    /**
     * @brief operador de asignacion
     */
    Ruta& operator=(const Ruta& orig) = default;

    /**
     * @brief agrega un nuevo punto a la ruta
     * @param punto Punto a agregar en la ruta
     * @pre punto debe de ser la localizacion valida de un pais
     */
    void nuevoPunto(Punto punto);

    /**
     * @brief permite cambiar el nombre de la ruta
     * @param nombre el nuevo nombre de la ruta
     */
    void nuevoNombre(std::string nombre);


};

#endif