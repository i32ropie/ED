/**
* @file donante.hpp
* @brief <Práctica 2> Tercera parte: Representación del TAD donantes.
* @author Eduardo Roldán Pijuán
* @date Marzo de 2016
* Pese a que el nombre de la clase es Donantes y hace referencias a Donante en el nombre de las funciones, la clase funciona como una lista para cualquier tipo de dato, ya que usa una plantilla con tipo genérico T.
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
    /**
    * @brief Estructura auxiliar nodo para la lista.
    */
    // template <class T>
    // struct Nodo{
    //     T dato;
    //     Nodo *siguiente;
    //     Nodo(const T &n): dato(n), siguiente(0){}
    // };

    // template <class T>
    class Donantes:public DonantesInterfaz{
        private:
            ListaSimpleEnlazada<Donante> _l;
        public:
            /** @name Constructores. */
            /**
            * @brief Constructor parametrizado.
            */
            Donantes(){}
            /** @name Observadores. */
            /**
            * @brief Obtiene el total de elementos de la lista.
            * @return Total de elementos de la lista.
            */
            uint totalDonantes() const{
                return _l.getTotal();
            }
            /**
            * @brief Devuelve el donante i-ésimo.
            * @note Función muy útil para recorrer los donantes.
            * @param i Índice del donante.
            * @return Donante i-ésimo.
            * @pre i >= 1 && i <= _total
            * @pre No puede estar vacía.
            * @sa estaVacia()
            */
            T getDonante(const uint &indice) const{
                return _l.getItem(indice);
            }
            // T getDonante(const unsigned int &i) const{
            //     assert(i>=1 && i<=_total);
            //     assert(!this->estaVacia());
            //     Nodo<T> *aux = _cabeza;
            //     for( unsigned int x = 1 ; x < i ; ++x )
            //         aux = aux->siguiente;
            //     return aux->dato;
            // }
            /**
            * @brief Devuelve el índice de un donante.
            * @note Función muy útil para obtener el índice a partir de un donante.
            * @param d Elemento.
            * @return Índice de un dato T o -1 en caso de que no esté o no haya elementos.
            * @sa estaVacia()
            * @sa getTotal()
            * @sa getDonante()
            */
            int getIndice(const Donante &d) const{
                return _l.getIndex(d);
            }
            // int getIndice(const T &d){
            //     if(this->estaVacia()){
            //         return -1;
            //     }
            //     int indice = -1;
            //     bool encontrado = false;
            //     for( unsigned int x = 1 ; x <= this->getTotal() && !encontrado ; ++x ){
            //         if(this->getDonante(x) == d){
            //             indice = x;
            //         }
            //     }
            //     return indice;
            // }
            /**
            * @brief Inserta un donante.
            * @note Inserta un donante de manera ordenada.
            * @param d Elemento.
            * @sa estaVacia()
            */
            void insertarDonante(const Donante &d){
                _l.insertItem(d);
            }
            // void insertarDonante(const T &d){
            //     Nodo<T> *nuevo = new Nodo<T>(d);                                // Creamos un nuevo nodo con el dato a insertar
            //     if(this->estaVacia()){                                          // Si la lista de donantes está vacía mi cursor y
            //         _cabeza = nuevo;                                            // mi cabeza va a ser el dato a insertar.
            //     }
            //     else{                                                           // Si no está vacía
            //         if(_cabeza->dato <= d){                                     // Y el dato en la cabeza es menor o igual que a insertar
            //             Nodo<T> *aux = _cabeza;                                 // Tendremos que buscar la posición donde insertarlo.
            //             Nodo<T> *anterior = 0;                                  // Puede ocurrir que insertemos entre dos nodos o al final
            //             bool encontrado = false;                                // por lo que recorreremos la lista de donantes comparando
            //             while(aux && !encontrado){                              // nuestros nodos para ver en qué posición insertarmos
            //                 if(aux->dato <= d){                                 // el nuevo nodo.
            //                     anterior = aux;
            //                     aux = aux->siguiente;
            //                 }
            //                 else{
            //                     encontrado = true;
            //                 }
            //             }
            //             anterior->siguiente = nuevo;                            // Una vez recorridos todos los nodos y hecho las comprobaciones
            //             nuevo->siguiente = aux;                                 // insertamos el nuevo nodo donde le corresponda y actualizamos
            //         }
            //         else{                                                       // Si el dato en la cabeza es mayor que el que vamos a insertar
            //             nuevo->siguiente = _cabeza;                             // actualizamos el puntero del nuevo y lo metemos en la cabeza.
            //             _cabeza = nuevo;
            //         }
            //     }
            //     _total++;
            // }
            /**
            * @brief Borra un donante pasado por parámetro.
            * @param d Elemento.
            * @return true si lo borra, false si no lo borra.
            * @sa estaVacia()
            * @sa getIndice()
            * @sa borrarElemento()
            */
            bool borrarDonante(const Donante &d){
                return _l.deleteItem(this->getIndice(d));
            }
            bool borrarDonante(const uint &indice){
                return _l.deleteItem(indice);
            }
            // bool borrarDonante(const T &d){
            //     if(this->estaVacia()){                                          // Si está vacía, devolvemos false.
            //         return false;
            //     }
            //     int indice;
            //     if((indice = this->getIndice(d)) == -1){                        // Si al comprobar el índice del donante dentro de la lista obtenemos
            //         return false;                                               // -1 quiere decir que no está en la lista, por lo que devolvemos false.
            //     }
            //     if(this->borrarElemento(indice)){                               // Intentamos el elemento llamando a la función borrarElemento.
            //         _total--;
            //         return true;
            //     }
            //     else{
            //         return false;
            //     }
            // }
            /**
            * @brief Borra un donante pasándole el índice.
            * @param indice Índice.
            * @return true si lo borra, false si no lo borra.
            * @sa getDonante()
            */
            // bool borrarElemento(const unsigned int &indice){
            //     T d = this->getDonante(indice);
            //     if(d == _cabeza->dato){                                         // Si queremos borrar la cabeza, la actualizamos.
            //         _cabeza = _cabeza->siguiente;
            //         return true;
            //     }
            //     Nodo<T> *aux = _cabeza;
            //     Nodo<T> *anterior = 0;
            //     bool encontrado = false;
            //     while(aux && !encontrado){                                      // Si no, recorremos los donantes hasta encontrarlo
            //         if(d == aux->dato){
            //             encontrado = true;
            //         }
            //         else{
            //             anterior = aux;
            //             aux = aux->siguiente;
            //         }
            //     }
            //     if(encontrado){
            //         anterior->siguiente = aux->siguiente;
            //         return true;
            //     }
            //     else{
            //         return false;
            //     }
            // }
            // bool borrarDonante(const T &d) {
            //     if(this->estaVacia()){                                          // Comprobamos si no hay donantes
            //         return false;                                               // y devolvemos false ya que no eliminamos nada.
            //     }
            //     if(_cabeza->dato == d){                                         // Si el dato a borrar está en la cabeza
            //         if(_cabeza->siguiente){                                     // comprobamos si hay sólo 1 donante o más.
            //             _cabeza = _cabeza->siguiente;                           // En el caso de que haya más, actualizamos la cabeza al siguiente.
            //         }
            //         else{                                                       // En el caso de que solo haya un donante y sea ese mismo el que
            //             _cabeza = 0;                                            // borramos, hacemos que _cabeza apunte a 0.
            //         }                                                           // En ambos casos, hemos eliminado el donante, por lo que
            //         _total--;
            //         return true;                                                // devolvemos true.
            //     }
            //     Nodo<T> *aux = _cabeza;                                         // En caso de que no sea la cabeza, necesitaremos recorrer los
            //     Nodo<T> *anterior = 0;                                          // donantes para buscarlo.
            //     bool encontrado = false;
            //     while( aux && !encontrado){
            //         if(aux->dato == d){
            //             encontrado = true;
            //         }
            //         else{
            //             anterior = aux;
            //             aux = aux->siguiente;
            //         }
            //     }
            //     if(encontrado){
            //         anterior->siguiente = aux->siguiente;                       // Si lo hemos encontrado lo borramos eliminando la unión.
            //         _total--;
            //         return true;                                                // y devolvemos true.
            //     }
            //     return false;                                                   // Si no, devolvemos false.
            // }
            // EXTRA
            bool existeDonante(const Donante &d) const{
                return _l.isValid(d);
            }
            // bool buscarDonante(T &d){
            //     int indice;
            //     if((indice = this->getIndice(d)) == -1){
            //         return false;
            //     }
            //     else{
            //         return true;
            //     }
            // }
            // bool buscarDonante(T &d) const {
            //     Nodo<T> *aux = _cabeza;
            //     while( aux ){                                                   // Recorremos nuestra lista de donantes.
            //         if(aux->dato == d){                                         // Si lo encontramos
            //             d = aux->dato;                                          // actualizamos el parámetro pasado por referencia
            //             return true;                                            // y devolvemos true.
            //         }
            //         else if(aux->dato <= d){                                    // Si no lo encontramos, miramos si nos hemos pasado
            //             return false;                                           // y devolvemos false. (Esto es para que sea más eficiente)
            //         }
            //         aux = aux->siguiente;
            //     }
            //     return false;
            // }
            bool estaVacia() const {
                return _l.isEmpty();
            }
            void leerDonantes(){
                T d;
                bool continuar = true, encontrado;
                unsigned int respuesta;
                unsigned int nDonante = 1;
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
            void mostrarDonantes() const{
                if(this->estaVacia()){
                    std::cout << "No hay ningún donante para mostrar." << std::endl;
                }
                else{
                    std::cout << "Estos son tus donantes:" << std::endl;
                    for( uint i = 1 ; i <= this->totalDonantes() ; ++i ){
                        std::cout << "\t\e[33;1m[" << i << "]\e[0m - \e[1m"<< this->getDonante(i) << "\e[0m";
                    }
                }
            }
            // void mostrarDonantes(){
            //     if(this->estaVacia()){
            //         std::cout << "No hay ningún donante para mostrar." << std::endl;
            //         return;
            //     }
            //     std::cout << "Estos son tus donantes:\n";
            //     for( unsigned int i = 1 ; i <= _total ; ++i ){
            //         std::cout << "\t\e[33;1m[" << i << "]\e[0m - \e[1m"<< getDonante(i) << "\e[0m";
            //     }
            // }
            void modificarDonante(const unsigned int &i){
                assert(i>=1 && i<=_total);
                assert(!this->estaVacia());
                T aux;
                aux = this->getDonante(i);
                this->borrarDonante(aux);
                aux.modificarDonante();
                this->insertarDonante(aux);
            }
    };

}

#endif
