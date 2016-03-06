/**
* @file monomiointerfaz.hpp
* @brief <Práctica 1> Primera parte: Representación del TAD monomio interfaz.
* @author Eduardo Roldán Pijuán
* @date Marzo de 2016
*/

#ifndef __MONOMIOINTERFAZ_HPP__
#define __MONOMIOINTERFAZ_HPP__

/**
* @brief Espacio de nombres para la asignatura Estructuras de Datos.
*/

namespace ed{

    class MonomioInterfaz{
        public:
            /** @name Observadores. */
            /**
            * @brief Obtiene el grado del monomio.
            */
            virtual int getGrado() const = 0;
            /**
            * @brief Obtiene el coeficiente del monomio.
            */
            virtual double getCoeficiente() const = 0;
            /** @name Modificadores. */
            /**
            * @brief Establece el grado del monomio.
            */
            virtual void setGrado(const int &grado) = 0;
            /**
            * @brief Establece el coeficiente del monomio.
            */
            virtual void setCoeficiente(const double &coeficiente) = 0;
    };

}

#endif
