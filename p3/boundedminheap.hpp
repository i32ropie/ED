/**
* @file boundedminheap.hpp
* @brief <Práctica 3> Segunda parte: Representación del TAD montículo.
* @author Eduardo Roldán Pijuán
* @date Marzo de 2016
*/

#ifndef __BOUNDEDMINHEAP_HPP__
#define __BOUNDEDMINHEAP_HPP__

#include <vector>
#include <cassert>
#include <iostream>
#include "boundedminheapinterfaz.hpp"
#include "extra.hpp"

/**
* @brief Espacio de nombres para la asignatura Estructuras de Datos.
*/

namespace ed{
    /// Clase BoundedMinHeap. Hereda de BoundedMinHeapInterfaz.
    template <class T>
    class BoundedMinHeap: public BoundedMinHeapInterfaz<T>{
        private:
            /// Vector interno utilizado para administrar la pila.
            std::vector<T> _data;
            /**
            * @brief Devuelve la última posición libre del montículo.
            * @return Tamaño del vector, es decir, el siguiente índice a rellenar.
            */
            int lastItem() const{
                return _data.size();
            }
            /**
            * @brief Devuelve el índice que le corresponde al hijo izquierdo del elemento i-ésimo.
            * @param i Índice del elemento al que calcular su hijo izquierdo.
            * @return Índice del hijo izquierdo del elemento i-ésimo.
            */
            int leftChild(const int &i) const{
                return i*2+1;
            }
            /**
            * @brief Devuelve el índice que le corresponde al hijo derecho del elemento i-ésimo.
            * @param i Índice del elemento al que calcular su hijo derecho.
            * @return Índice del hijo derecho del elemento i-ésimo.
            */
            int rightChild(const int &i) const{
                return i*2+2;
            }
            /**
            * @brief Devuelve el índice que le corresponde al padre del elemento i-ésimo.
            * @param i Índice del elemento al que calcular su padre.
            * @return Índice del padre del elemento i-ésimo.
            */
            int parent(const int &i) const{
                return (i-1)/2;
            }
            /**
            * @brief Flota el elemento i-ésimo.
            * @note Función recursiva utilizada a la hora de insertar nuevos elementos en el montículo.
            * @param i Índice del elemento a flotar.
            * @sa parent()
            * @sa shiftUp()
            */
            void shiftUp(const int &i){
                if( i > 0 && (_data[i]) < (_data[this->parent(i)])){
                    swap(_data, i, this->parent(i));
                    this->shiftUp(this->parent(i));
                }
            }
            /**
            * @brief Hunde el elemento i-ésimo.
            * @note Función recursiva utilizada a la hora de eliminar el elemento en la cima del montículo.
            * @param i Índice del elemento a hundir.
            * @sa leftChild()
            * @sa rightChild()
            * @sa lastItem()
            * @sa shiftDown()
            */
            void shiftDown(const int &i){
                int n = i;
                int lC = this->leftChild(i);
                int rC = this->rightChild(i);
                if( (lC < this->lastItem()) && (_data[lC] < _data[n]) ){
                    n=lC;
                }
                if( (rC < this->lastItem()) && (_data[rC] < _data[n]) ){
                    n=rC;
                }
                if( i != n ){
                    swap(_data, i, n);
                    this->shiftDown(n);
                }
            }
            /**
            * @brief Comprueba si un elemento pertenece al montículo.
            * @param d Elemento a comprobar.
            * @return true si ya existe ese elemento, false si no.
            */
            bool has(const T &d){
                for( int i = 0 ; i < this->lastItem() ; ++i ){
                    if(_data[i] == d)
                        return true;
                }
                return false;
            }

        public:
            /**
            * @brief Comprueba si el montículo está vacío.
            * @return true si está vacío, false si no.
            */
            bool isEmpty() const{
                return _data.empty();
            }
            /**
            * @brief Obtiene el elemento de la cima del montículo.
            * @pre El montículo no debe estar vacío.
            * @return Elemento en la cima.
            */
            T top() const{
                assert(!this->isEmpty());
                return _data[0];
            }
            /**
            * @brief Inserta un elemento en el montículo.
            * @note Se comprueba que no exista el elemento antes de insertarse.
            */
            void insert(const T &d){
                if(!this->has(d)){
                    _data.push_back(d);
                    this->shiftUp(this->lastItem()-1);
                }
            }
            /**
            * @brief Elimina el elemento en la cima del montículo.
            * @pre El montículo no debe estar vacío.
            */
            void remove(){
                assert(!this->isEmpty());
                if( this->lastItem()-1 > 0){
                    _data[0] = _data[this->lastItem()-1];
                    _data.pop_back();
                    this->shiftDown(0);
                }
                else if( this->lastItem() == 1){
                    _data.pop_back();
                }
            }
    };
}

#endif
