/**
 * @author Daniel Alconchel Vázquez y Mario García Márquez
 */

#ifndef PRACTICA_3_PILA_MAX_VD_H
#define PRACTICA_3_PILA_MAX_VD_H


#include <iostream>
#include <vector>

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

/**
 * @brief TDA Pila con Máximo
 * Representa una pila, donde cada elemento se contiene un dato y el valor máximo de la pila, cuando se introdujo
 * @warning Al ser una pila todas las operaciones se realizan en el tope
 * @warning Representación usando vectores de la STL
 */

template<class T>
class Pila_max_VD{
private:

    std::vector<Elemento<T>> pila;     // Vector dinámico, que ejercerá de  pila

    /**
     * @brief Función auxiliar para copiar
     * @param orig instancia clase Pila_Max_VD
     */
    void copy(const Pila_max_VD<T> &orig);
public:
    /**
     * @brief Constructor por defecto. Inicializa una pila vacía
     */
    Pila_max_VD();

    /**
     * @brief Constuctor de copia
     * @param p instancia de la clase Pila_max_VD
     */
    Pila_max_VD(const Pila_max_VD<T> &p);

    /**
     * @brief Destructor de la clase
     */
    ~Pila_max_VD();

    /**
     * @brief Operador de asignación
     * @param p instancia de la clase Pila_max_VD
     */
    Pila_max_VD & operator=(const Pila_max_VD<T> &p);

    /**
     * @brief Comprueba si la pila está vacía
     * @return Devuelve true si está vacia. En caso contrario, devuelve false
     */
    bool vacia();

    /**
     * @brief Inserta un elemento en el tope de la pila
     * @param t instancia del struct elemento (elemento a insertar)
     */
    void Insertar (const Elemento<T> &t);

    /**
     * @brief Elimina el tope de la pila
     */
    void Quitar();

    /**
     * @brief Consulta el tope de la pila
     * @return El elemento del tope
     */
    Elemento<T> Consultar() const;
};

#endif
