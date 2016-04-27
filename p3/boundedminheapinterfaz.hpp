/**
* @file boundedminheapinterfaz.hpp
* @brief <Práctica 3> Segunda parte: Representación del TAD montículo interfaz.
* @author Eduardo Roldán Pijuán
* @date Abril de 2016
*/
#ifndef __BOUNDEDMINHEAPINTERFAZ_HPP__
#define __BOUNDEDMINHEAPINTERFAZ_HPP__

/**
* @brief Espacio de nombres para la asignatura Estructuras de Datos.
*/

namespace ed{
    /// Clase BoundedMinHeapInterfaz
    template <class T>
    class BoundedMinHeapInterfaz{
        public:
            /**
            * @brief Comprueba si el montículo está vacío.
            */
            virtual bool isEmpty() const = 0;
            /**
            * @brief Devuelve el elemento en la cima del montículo.
            */
            virtual T top() const = 0;
            /**
            * @brief Inserta un elemento en el montículo.
            */
            virtual void insert(const T &d) = 0;
            /**
            * @brief Elimina el elemento de la cima.
            */
            virtual void remove() = 0;
    };
}

#endif
