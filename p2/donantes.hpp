/**
* @file donantes.hpp
* @brief <Práctica 2> Tercera parte: Representación del TAD donantes.
* @author Eduardo Roldán Pijuán
* @date Marzo de 2016
*/

#ifndef __DONANTES_HPP__
#define __DONANTES_HPP__

#include <cassert>
#include <cstdio>
#include <iostream>
#include "listasimpleenlazada.hpp"
#include "donante.hpp"
#include "donantesinterfaz.hpp"

/**
* @brief Espacio de nombres para la asignatura Estructuras de Datos.
*/

namespace ed{

    class Donantes:public DonantesInterfaz{
        private:
            ListaSimpleEnlazada<Donante> _l;
        public:
            /** @name Constructores. */
            /**
            * @brief Constructor.
            */
            Donantes(){}
            /** @name Observadores. */
            /**
            * @brief Obtiene el total de elementos de la lista.
            * @return Total de elementos de la lista.
            */
            uint getTotal() const{
                return _l.getTotal();
            }
            /**
            * @brief Devuelve el donante i-ésimo.
            * @param indice Índice del donante.
            * @return Donante i-ésimo.
            * @pre i >= 1 && i <= _total
            * @pre No puede estar vacía.
            */
            Donante getDonante(const uint &indice) const{
                return _l.getItem(indice);
            }
            /**
            * @brief Devuelve el índice de un donante.
            * @param d Donante.
            * @return Índice del donante o -1 en caso de que no exista el donante o no haya ninguno insertado.
            */
            int getIndice(const Donante &d) const{
                return _l.getIndex(d);
            }
            /**
            * @brief Inserta un donante.
            * @note Inserta un donante de manera ordenada.
            * @param d Donante.
            * @post Tras insertar un donante, la lista no puede estar vacía.
            * @sa estaVacia()
            */
            void insertarDonante(const Donante &d){
                _l.insertItem(d);
                assert(!this->estaVacia());
            }
            /**
            * @brief Borra un donante pasado como parámetro.
            * @note Si no existe el donante, no borrará nada y devolverá false.
            * @param d Donante.
            * @return true si lo borra, false si no lo borra.
            * @sa getIndice()
            * @post Si se elimina con éxito, el total de elementos debe ser 1 menos que antes de llamar a la función.
            */
            bool borrarDonante(const Donante &d){
                return _l.deleteItem(this->getIndice(d));
            }
            /**
            * @brief Borra un donante pasado su índice como parámetro.
            * @note Si no existe el donante, no borrará nada y devolverá false.
            * @param indice Índice del donante a borrar.
            * @return true si lo borra, false si no lo borra.
            * @post Si se elimina con éxito, el total de elementos debe ser 1 menos que antes de llamar a la función.
            */
            bool borrarDonante(const uint &indice){
                return _l.deleteItem(indice);
            }
            /**
            * @brief Comprueba si un donante existe en nuestra lista de donantes.
            * @param d Donante.
            * @return true si existe el donante, false si no existe.
            */
            bool existeDonante(const Donante &d) const{
                return _l.isValid(d);
            }
            /**
            * @brief Comprueba si la lista está vacía.
            * @return true si la lista está vacía, false si no lo está.
            */
            bool estaVacia() const {
                return _l.isEmpty();
            }
            /**
            * @brief Función para leer múltiples donantes.
            */
            void leerDonantes(){
                Donante d;
                bool continuar = true, encontrado;
                int respuesta;
                uint nDonante = 1;
                do{
                    std::cout << "Introduce tu donante nº " << nDonante << ": " << std::endl;
                    std::cin >> d;
                    encontrado = this->existeDonante(d);
                    if(!encontrado){
                        this->insertarDonante(d);
                        std::cout << "Donante insertado.";
                    }
                    else{
                        std::cout << "Error, ya existía ese donante. Donante no insertado" << std::endl;
                    }
                    getchar();
                    do{
                        std::cout << "¿Deseas introducir más donantes? (1 = continuar; 0 = parar): ";
                        std::cin >> respuesta;
                        switch (respuesta) {
                            case 1:
                                continuar = true;
                                getchar();
                                break;
                            case 0:
                                continuar = false;
                                break;
                            default:
                                std::cout << "Opción no válida." << std::endl;
                                break;
                        }
                    }while(respuesta < 0 || respuesta > 1);
                }while(continuar);
            }
            /**
            * @brief Función para mostrar los donantes en caso de que haya alguno.
            */
            void mostrarDonantes() const{
                if(this->estaVacia()){
                    std::cout << "No hay ningún donante para mostrar." << std::endl;
                }
                else{
                    std::cout << "Estos son tus donantes:" << std::endl;
                    for( uint i = 1 ; i <= this->getTotal() ; ++i ){
                        std::cout << "\t\e[33;1m[" << i << "]\e[0m - \e[1m"<< this->getDonante(i) << "\e[0m";
                    }
                }
            }
            /**
            * @brief Función para modificar el donante iésimo.
            * @param indice Número entero positivo con el índice del donante a modificar.
            * @pre El valor de indice debe estar entre 1 y el total de donantes.
            * @pre Debe haber algún donante insertado.
            */
            void modificarDonante(const uint &indice){
                assert(indice>=1 && indice<=this->getTotal());
                assert(!this->estaVacia());
                Donante aux = this->getDonante(indice);
                this->borrarDonante(aux);
                aux.modificarDonante();
                this->insertarDonante(aux);
            }
    };

}

#endif
