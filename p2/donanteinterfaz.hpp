/**
* @file donanteinterfaz.hpp
* @brief <Práctica 2> Primera parte: Representación del TAD donante interfaz.
* @author Eduardo Roldán Pijuán
* @date Marzo de 2016
*/
#ifndef __DONANTEINTERFAZ_HPP__
#define __DONANTEINTERFAZ_HPP__

#include <string>

/**
* @brief Espacio de nombres para la asignatura Estructuras de Datos.
*/

namespace ed{
    class DonanteInterfaz{
        public:
            /** @name Modificadores. */
            /*
            * @brief Establece el nombre del donante.
            */
            virtual void setNombre(const std::string &nombre) = 0;
            /*
            * @brief Establece los apellidos del donante.
            */
            virtual void setApellidos(const std::string &apellidos) = 0;
            /*
            * @brief Establece el grupo sanguíneo del donante.
            */
            virtual void setGrupoSanguineo(const std::string &gSanguineo) = 0;
            /*
            * @brief Establece el factor RH del donante.
            */
            virtual void setFactorRH(const std::string &factorRH) = 0;
            /** @name Observadores. */
            /*
            * @brief Obtiene el nombre del donante.
            */
            virtual std::string getNombre() const = 0;
            /*
            * @brief Obtiene los apellidos del donante.
            */
            virtual std::string getApellidos() const = 0;
            /*
            * @brief Obtiene el grupo sanguíneo del donante.
            */
            virtual std::string getGrupoSanguineo() const = 0;
            /*
            * @brief Obtiene el factor RH del donante.
            */
            virtual std::string getFactorRH() const = 0;
    };
}

#endif
