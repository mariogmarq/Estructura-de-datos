/**
 * @author Daniel Alconchel Vázquez y Mario García Márquez
 */

#ifndef PRÁCTICA_3_COLA_MAX_H
#define PRÁCTICA_3_COLA_MAX_H

#include <iostream>
#include <stack>

template<class T>
/**
* @brief Representación elementos de la pila
* @param T tipo de elemento
*/
struct elemento{
    T dato;
    T maximo;
};

template <class T>
/**
 * @brief Clase auxiliar para representar los elementos de la pila
 * @tparam T
 */
class Elemento{
private:
    elemento<T> a;
public:
    T ConsultarMaximo() const;
    T ConsultarDato() const;
    void Insertar(T c, T b);
};

template<class T>
/**
 * @brief TDA Cola Máximo
 * Representación de una cola, a través de la pila stack de la STL, de
 * una cola con máximo
 * @warning Se introducen los elementos por el "front de la cola y se eliminan por el "back"
 */
class Cola_max {
    private:
        std::stack<Elemento<T>> cola; //  Representacón de la cola con máximo

        /**
         * @brief Función auxiliar para copiar
         * @param orig instancia de la clase Cola_max
         */
        void copy(const Cola_max<T> &orig);
    public:
        /**
         * @brief Constructor por defecto
         */
        Cola_max();

        /**
         * @brief Constructor de copia
         * @param orig instancia de la clase Cola_max
         */
        Cola_max(const Cola_max<T> &orig);

        /**
         * @brief Destructor de la clase
         */
        ~Cola_max();

        /**
         * @brief Inserta un elemento en la cola
         * @param e elemento a insertar
         * @warning Los elementos se insertan en el front
         */
        void Insertar(const Elemento<T> &e);

        /**
         * @brief Elimina un elemento de la cola
         * @warning Los elementos se eliminan en el back
         */
        void Eliminar();

        /**
         * @brief Consulta el front de la cola
         * @return Front de la cola (Instancia de la clase Elemento)
         */
        Elemento<T> Front() const;

        /**
         * @brief Consulta el back de la cola
         * @return Back de la cola (Instancia de la clase Elemento)
         */
        Elemento<T> Back() const;

        /**
         * @brief Comprueba si la cola está vacía
         * @return true en caso afirmativo y false en caso contrario
         */
        bool vacio() const;

        /**
         * @brief Devuelve el tamaño de la cola
         * @return Tmamaño de la cola
         */
        int size() const;
};


#endif
