#ifndef __DONANTES_HPP__
#define __DONANTES_HPP__

#include <cassert>
#include <cstdio>
#include "donantesinterfaz.hpp"

namespace ed{
    template <class T>
    struct Nodo{
        T dato;
        Nodo *siguiente;
        Nodo(const T &n): dato(n), siguiente(0){}
    };

    template <class T>
    class Donantes:public DonantesInterfaz<T>{
        private:
            Nodo<T> *cabeza_; // Puntero al primer elemento de la lista.
            Nodo<T> *cursor_; // Puntero al elemento actual de la lista.
        public:
            Donantes(const T &d){
                cabeza_ = new Nodo<T>(d);
                cursor_ = new Nodo<T>(d);
            }
            Donantes(): cabeza_(0), cursor_(0){}
            void insertarDonante(const T &d){
                Nodo<T> *nuevo = new Nodo<T>(d);                                // Creamos un nuevo nodo con el dato a insertar
                if(this->estaVacia()){                                          // Si la lista de donantes está vacía mi cursor y
                    cabeza_ = nuevo;                                            // mi cabeza va a ser el dato a insertar.
                    cursor_ = nuevo;
                }
                else{                                                           // Si no está vacía
                    if(cabeza_->dato <= d){                                     // Y el dato en la cabeza es menor o igual que a insertar
                        Nodo<T> *aux = cabeza_;                                 // Tendremos que buscar la posición donde insertarlo.
                        Nodo<T> *anterior = 0;                                  // Puede ocurrir que insertemos entre dos nodos o al final
                        bool encontrado = false;                                // por lo que recorreremos la lista de donantes comparando
                        while(aux && !encontrado){                              // nuestros nodos para ver en qué posición insertarmos
                            if(aux->dato <= d){                                 // el nuevo nodo.
                                anterior = aux;
                                aux = aux->siguiente;
                            }
                            else{
                                encontrado = true;
                            }
                        }
                        anterior->siguiente = nuevo;                            // Una vez recorridos todos los nodos y hecho las comprobaciones
                        nuevo->siguiente = aux;                                 // insertamos el nuevo nodo donde le corresponda y actualizamos
                        cursor_ = nuevo;                                        // nuestro cursor.
                    }
                    else{                                                       // Si el dato en la cabeza es mayor que el que vamos a insertar
                        nuevo->siguiente = cabeza_;                             // actualizamos el puntero del nuevo y lo metemos en la cabeza.
                        cabeza_ = nuevo;
                        cursor_ = nuevo;
                    }
                }
            }
            bool borrarDonante(const T &d) {
                if(this->estaVacia()){
                    return false;
                }
                if(cabeza_->dato == d){
                    if(cabeza_->siguiente){
                        cabeza_ = cabeza_->siguiente;
                    }
                    else{
                        cabeza_ = 0;
                    }
                    return true;
                }
                Nodo<T> *aux = cabeza_;
                Nodo<T> *anterior = 0;
                bool encontrado = false;
                while( aux && !encontrado){
                    if(aux->dato == d){
                        encontrado = true;
                    }
                    else{
                        anterior = aux;
                        aux = aux->siguiente;
                    }
                }
                if(aux){
                    anterior->siguiente = aux->siguiente;
                    return true;
                }
                return false;
            }
            bool buscarDonante(T &d) const {
                // assert(!this->estaVacia());
                Nodo<T> *aux = cabeza_;
                while( aux ){                                                   // Recorremos nuestra lista de donantes.
                    if(aux->dato == d){                                         // Si lo encontramos
                        d = aux->dato;                                          // actualizamos el parámetro pasado por referencia
                        return true;                                            // y devolvemos true.
                    }
                    else if(aux->dato <= d){                                    // Si no lo encontramos, miramos si nos hemos pasado
                        return false;                                           // y devolvemos false. (Esto es para que sea más eficiente)
                    }
                    aux = aux->siguiente;
                }
                return false;
            }
            bool estaVacia() const {
                return cabeza_ == NULL;
            }
            void leerDonantes(){
                Donante d;
                bool continuar = true, encontrado;
                unsigned int respuesta;
                unsigned int nDonante = 1;
                do{
                    std::cout << "Introduce tu donante nº " << nDonante << ": " << std::endl;
                    std::cin >> d;
                    encontrado = this->buscarDonante(d);
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
            void mostrarDonantes(){
                Nodo<T> *aux = cabeza_;
                while( aux ){
                    std::cout << aux->dato;
                    aux = aux->siguiente;
                }
            }
    };

}

#endif
