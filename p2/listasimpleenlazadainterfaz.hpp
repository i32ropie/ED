/**
* @file listasimpleenlazadainterfaz.hpp
* @brief <Práctica 2> Tercera parte: Representación del TAD lista simple enlazada interfaz.
* @author Eduardo Roldán Pijuán
* @date Marzo de 2016
*/


#ifndef __LISTASIMPLEENLAZADAINTERFAZ_HPP__
#define __LISTASIMPLEENLAZADAINTERFAZ_HPP__

/**
* @brief Espacio de nombres para la asignatura Estructuras de Datos.
*/

namespace ed{
    /// Clase ListaSimpleEnlazadaInterfaz.
    template <class T>
    class ListaSimpleEnlazadaInterfaz{
        public:
            /**
            * @brief Comprueba si la lista está vacía.
            */
            virtual bool isEmpty() const = 0;
            /**
            * @brief Devuelve el elemento i-ésimo.
            */
            virtual T getItem(const uint &index) const = 0;
            /**
            * @brief Devuelve el índice de un elemento.
            */
            virtual int getIndex(const T &d) const = 0;
            /**
            * brief Inserta de manera ordenada un elemento.
            */
            virtual void insertItem(const T &d) = 0;
            /**
            * @brief Borra el elemento i-ésimo en el caso de que pueda.
            */
            virtual bool deleteItem(const int &index) = 0;
            /**
            * @brief Comprueba si un elemento es miembro de la lista.
            */
            virtual bool isValid(const T &d) const = 0;
            /**
            * @brief Devuelve el total de elementos de la lista.
            */
            virtual uint getTotal() const = 0;
    };
}

#endif
