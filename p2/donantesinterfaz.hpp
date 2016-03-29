/**
* @file donantesinterfaz.hpp
* @brief <Práctica 2> Tercera parte: Representación del TAD donantes interfaz.
* @author Eduardo Roldán Pijuán
* @date Marzo de 2016
*/

#ifndef __DONANTESINTERFAZ_HPP__
#define __DONANTESINTERFAZ_HPP__

#include <string>
#include "donante.hpp"

/**
* @brief Espacio de nombres para la asignatura Estructuras de Datos.
*/

namespace ed{
    /// Clase DonantesInterfaz.
    class DonantesInterfaz{
        public:
            /**
            * @brief Inserta un donante en la lista.
            */
            virtual void insertarDonante(const Donante &d) = 0;
            /**
            * @brief Borra un donante de la lista.
            */
            virtual bool borrarDonante(const Donante &d) = 0;
            /**
            * @brief Comprueba si existe un donante.
            */
            virtual bool existeDonante(const Donante &d) const = 0;
            /**
            * @brief Comprueba si la lista está vacía.
            */
            virtual bool estaVacia() const = 0;
    };
}

#endif
