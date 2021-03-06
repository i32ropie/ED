/**
* @file polinomiointerfaz.hpp
* @brief <Práctica 1> Tercera parte: Representación del TAD polinomio interfaz.
* @author Eduardo Roldán Pijuán.
* @date Marzo de 2016
*/

#ifndef __POLINOMIOINTERFAZ_HPP__
#define __POLINOMIOINTERFAZ_HPP__

#include <iostream>
#include <list>
#include "monomio.hpp"

/**
* @brief Espacio de nombres para la asignatura Estructuras de Datos.
*/

namespace ed{

    class PolinomioInterfaz{
        public:
            /**
            * @brief Comprueba si la lista de monomios está vacía.
            */
            virtual bool estaVacio() const = 0;
            /**
            * @brief Obtiene el grado del polinomio.
            */
            virtual int getGrado() const = 0;
            /**
            * @brief Obtiene el número de términos del polinomio.
            */
            virtual int getNumeroTerminos() const = 0;
            /**
            * @brief Obtiene el monomio i-ésimo
            */
            virtual Monomio getMonomio(const int &i) const = 0;
            /** @name Modificadores. */
            /**
            * @brief Establece el grado del polinomio.
            */
            virtual void setGrado(const int &grado) = 0;
            /**
            * @brief Establece el número de términos del polinomio.
            */
            virtual void setNumeroTerminos(const int &nTerminos) = 0;
            /**
            * @brief Agrega un monomio al polinomio.
            */
            virtual void setMonomio(const Monomio &m) = 0;
    };

}

#endif
