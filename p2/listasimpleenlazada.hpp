/**
* @file listasimpleenlazada.hpp
* @brief <Práctica 2> Tercera parte: Representación del TAD lista simple enlazada.
* @author Eduardo Roldán Pijuán
* @date Marzo de 2016
* Esta clase mantiene los elementos ordenados.
*/

#ifndef __LISTASIMPLEENLAZADA_HPP__
#define __LISTASIMPLEENLAZADA_HPP__

#include "listasimpleenlazadainterfaz.hpp"

/**
* @brief Espacio de nombres para la asignatura Estructuras de Datos.
*/

namespace ed{
    /**
    * @brief Estructura Nodo usada en la clase.
    * La clase consta de el elemento y un puntero al siguiente nodo.
    */
    template <class T>
    struct Nodo{
        T data;
        Nodo *next;
        Nodo(const T &d): data(d), next(0){}
    };

    template <class T>
    class ListaSimpleEnlazada:public ListaSimpleEnlazadaInterfaz<T>{
        private:
            Nodo<T> *_head;
            uint _total;
        public:
            /**
            * @brief Constructor.
            */
            ListaSimpleEnlazada(): _head(0), _total(0){}
            /**
            * @brief Devuelve el total de elementos de la lista.
            * @return Total de elementos de la lista.
            * @post Que isEmpty() devuelva true aquí implica que esta función devuelva 0.
            */
            uint getTotal() const{
                return _total;
            }
            /**
            * @brief Devuelve si la lista está vacía o no.
            * @return true si la lista está vacía, false si no lo esta.
            * @bost Que getTotal() devuelva != 0 implica que esta función devuelva false.
            */
            bool isEmpty() const{
                return _head == 0;
            }
            /**
            * @brief Inserta un elemento en la lista.
            * @param d Elemento.
            * @post isEmpty() == false
            * @post getTotal() == total_old+1
            * @sa isEmpty()
            */
            void insertItem(const T &d){
                Nodo<T> *n = new Nodo<T>(d);
                if(this->isEmpty()){
                    _head = n;
                }
                else{
                    if(_head->data <= d){
                        Nodo<T> *curr = _head;
                        Nodo<T> *prev = 0;
                        bool found = false;
                        while(curr && !found){
                            if(curr->data <= d){
                                prev = curr;
                                curr = curr->next;
                            }
                            else{
                                found = true;
                            }
                        }
                        prev->next = n;
                        n->next = curr;
                    }
                    else{
                        n->next = _head;
                        _head = n;
                    }
                }
                _total++;
            }
            /**
            * @brief Borra el elemento i-ésimo de la lista.
            * @param index Índice del elemento a borrar.
            * @return true si borra el elemento, false si no.
            * @post Si la lista estaba vacía, la función debe devolver false.
            * @post Si el índice no se encuentra entre 1 y el total de elementos, la función debe devolver false.
            * @post getTotal() == old.getTotal()-1 implica que la función devuelva true.
            * @sa isEmpty()
            * @sa getTotal()
            * @sa getItem()
            */
            bool deleteItem(const int &index){
                if(this->isEmpty() || index < 1 || index > this->getTotal()){
                    return false;
                }
                T d = this->getItem(index);
                if(d == _head->data){
                    _head = _head->next;
                    _total--;
                    return true;
                }
                Nodo<T> *curr = _head;
                Nodo<T> *prev = 0;
                bool found = false;
                while(curr && !found){
                    if(d == curr->data){
                        found = true;
                    }
                    else{
                        prev = curr;
                        curr = curr->next;
                    }
                }
                if(found){
                    prev->next = curr->next;
                    _total--;
                    return true;
                }
                else{
                    return false;
                }
            }
            /**
            * @brief Devuelve el elemento i-ésimo.
            * @param index Índice del elemento a devolver.
            * @pre La lista no puede estar vacía.
            * @pre index debe estar acotado entre 1 y el total de elementos.
            */
            T getItem(const uint &index) const{
                assert(index>=1 && index<=this->getTotal());
                assert(!this->isEmpty());
                Nodo<T> *curr = _head;
                for( uint x = 1 ; x < index ; ++x ){
                    curr = curr->next;
                }
                return curr->data;
            }
            /**
            * @brief Devuelve el índice de un elemento.
            * @note En caso de que no exista o la lista esté vacía devolverá -1.
            * @param d Elemento.
            * @return Índice del elemento o -1.
            * @post El valor de retorno no puede ser superior al número de elementos.
            * @sa isEmpty()
            * @sa getTotal()
            * @sa getItem()
            */
            int getIndex(const T &d) const{
                if(this->isEmpty()){
                    return -1;
                }
                int index = -1;
                bool found = false;
                for( uint x = 1 ; x <= this->getTotal() && !found ; ++x ){
                    if(this->getItem(x) == d){
                        index = x;
                        found = true;
                    }
                }
                return index;
            }
            /**
            * @brief Comprueba si un donante es válido o no.
            * @note Realmente, esta función podría eliminarse y usar getIndex().
            * @param d Elemento.
            * @return true si el elemento se encuentra en la lista, false si no.
            * @sa getIndex()
            */
            bool isValid(const T &d) const{
                int index;
                if((index = this->getIndex(d)) == -1){
                    return false;
                }
                else{
                    return true;
                }
            }
    };
}

#endif
