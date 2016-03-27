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
            Nodo<T> *_cabeza;                                                   // Puntero al primer elemento de la lista.
            Nodo<T> *_cursor;                                                   // Puntero al elemento actual de la lista.
            unsigned int _total;                                                // Número de donantes.
        public:
            Donantes(const T &d){
                _cabeza = new Nodo<T>(d);
                _cursor = new Nodo<T>(d);
                unsigned int contador = 0;
                for( Nodo<T> *aux = _cabeza ; aux ; aux = aux->siguiente)
                    contador++;
                _total = contador;
            }
            Donantes(): _cabeza(0), _cursor(0), _total(0){}
            inline unsigned int getTotal() const {return _total;}
            void insertarDonante(const T &d){
                Nodo<T> *nuevo = new Nodo<T>(d);                                // Creamos un nuevo nodo con el dato a insertar
                if(this->estaVacia()){                                          // Si la lista de donantes está vacía mi cursor y
                    _cabeza = nuevo;                                            // mi cabeza va a ser el dato a insertar.
                    _cursor = nuevo;
                }
                else{                                                           // Si no está vacía
                    if(_cabeza->dato <= d){                                     // Y el dato en la cabeza es menor o igual que a insertar
                        Nodo<T> *aux = _cabeza;                                 // Tendremos que buscar la posición donde insertarlo.
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
                        _cursor = nuevo;                                        // nuestro cursor.
                    }
                    else{                                                       // Si el dato en la cabeza es mayor que el que vamos a insertar
                        nuevo->siguiente = _cabeza;                             // actualizamos el puntero del nuevo y lo metemos en la cabeza.
                        _cabeza = nuevo;
                        _cursor = nuevo;
                    }
                }
                _total++;
            }
            bool borrarDonante(const T &d) {
                if(this->estaVacia()){                                          // Comprobamos si no hay donantes
                    return false;                                               // y devolvemos false ya que no eliminamos nada.
                }
                if(_cabeza->dato == d){                                         // Si el dato a borrar está en la cabeza
                    if(_cabeza->siguiente){                                     // comprobamos si hay sólo 1 donante o más.
                        _cabeza = _cabeza->siguiente;                           // En el caso de que haya más, actualizamos la cabeza al siguiente.
                    }
                    else{                                                       // En el caso de que solo haya un donante y sea ese mismo el que
                        _cabeza = 0;                                            // borramos, hacemos que _cabeza apunte a 0.
                    }                                                           // En ambos casos, hemos eliminado el donante, por lo que
                    _total--;
                    return true;                                                // devolvemos true.
                }
                Nodo<T> *aux = _cabeza;                                         // En caso de que no sea la cabeza, necesitaremos recorrer los
                Nodo<T> *anterior = 0;                                          // donantes para buscarlo.
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
                if(encontrado){
                    anterior->siguiente = aux->siguiente;                       // Si lo hemos encontrado lo borramos eliminando la unión.
                    _total--;
                    return true;                                                // y devolvemos true.
                }
                return false;                                                   // Si no, devolvemos false.
            }
            bool buscarDonante(T &d) const {
                Nodo<T> *aux = _cabeza;
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
                return _cabeza == NULL;
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
                if(this->estaVacia()){
                    std::cout << std::endl << "No hay ningún donante para mostrar." << std::endl;
                    return;
                }
                std::cout << "Estos son tus donantes:\n";
                for( unsigned int i = 1 ; i <= _total ; ++i ){
                    std::cout << "\t\e[33;1m" << i << "\e[0m - \e[1m"<< getDonante(i) << "\e[0m";
                }
            }
            T getDonante(const unsigned int &i) const{
                assert(i>=1 && i<=_total);
                assert(!this->estaVacia());
                Nodo<T> *aux = _cabeza;
                for( unsigned int x = 1 ; x < i ; ++x )
                    aux = aux->siguiente;
                return aux->dato;
            }
            void modificarDonante(const unsigned int &i){
                assert(i>=1 && i<=_total);
                assert(!this->estaVacia());
                Donante aux;
                aux = this->getDonante(i);
                this->borrarDonante(aux);
                aux.modificarDonante();
                this->insertarDonante(aux);
            }
    };

}

#endif
