/**
* @file graph.hpp
* @brief <Práctica 4> Primera parte: Representación del TAD grafo.
* @author Eduardo Roldán Pijuán
* @date Mayo de 2016
*/

#ifndef __GRAPH_HPP__
#define __GRAPH_HPP__

#include <vector>
#include <cassert>
#include <iostream>
#include <string>
#include "vertex.hpp"
#include "edge.hpp"
#include "extra.hpp"

/**
* @brief Espacio de nombres para la asignatura Estructuras de Datos.
*/

namespace ed {
    /// Clase Graph
    class Graph {
        private:
            /// Vector con los vértices del grafo.
            std::vector<Vertex<std::string> > _vector;
            /// Matriz de adyacencias del grafo.
            std::vector<std::vector<double> > _matrix;
            /// Variable que indica si el grado es dirigido o no.
            bool _directed;
            /// Cursor de vértices.
            uint _cursorV;
            /// Cursor de lados.
            uint _cursorE;
            /// Número de vértices.
            uint _nVertexes;
            /// Número de lados.
            uint _nEdges;
            /// Capacidad.
            uint _capacity;
        public:
            /** @name Constructores. */
            /**
            * @brief Constructor con valores por defecto.
            * @param capacity Capacidad del grafo (uint).
            * @param directed Grafo dirigido o no dirigido (bool).
            * @sa setCapacity()
            * @sa setVertexes()
            * @sa setEdges()
            * @sa setCursorV()
            * @sa setCursorE()
            * @sa setDirected()
            */
            Graph(const uint &capacity=0, const bool &directed=true){
                assert(capacity>=0);
                this->setCapacity(capacity);
                this->setVertexes(0);
                this->setEdges(0);
                this->setCursorV(0);
                this->setCursorE(0);
                this->setDirected(directed);
                _matrix = std::vector< std::vector< double > >(capacity, std::vector< double >(capacity));
                for( uint i = 0 ; i < capacity ; ++i){
                    for( uint j = 0 ; j < capacity ; ++j){
                        _matrix[i][j] = INFINITE;
                    }
                }
            }
            /** @name Observadores. */
            /**
            * @brief Devuelve si el grafo es dirigido o no.
            * @return true si el grafo es dirigido, false si no.
            */
            inline bool getDirected() const { return _directed; }
            /**
            * @brief Devuelve el valor del cursor de vértices.
            * @return Valor del cursor de vértices.
            */
            inline uint getCursorV() const { return _cursorV; }
            /**
            * @brief Devuelve el valor del cursor de lados.
            * @return Valor del cursor de lados.
            */
            inline uint getCursorE() const { return _cursorE; }
            /**
            * @brief Devuelve el número de vértices del grafo.
            * @return Número de vértices del grafo.
            */
            inline uint getVertexes() const { return _nVertexes; }
            /**
            * @brief Devuelve el número de lados del grafo.
            * @return Número de lados del grafo.
            */
            inline uint getEdges() const { return _nEdges; }
            /**
            * @brief Devuelve la capacidad del grafo.
            * @return Capacidad del grafo.
            */
            inline uint getCapacity() const { return _capacity; }
            /** @name Modificadores */
            /**
            * @brief Establece si el grafo es dirigido o no.
            * @param directed Grafo dirigido o no (bool).
            */
            inline void setDirected(const bool &directed) { _directed = directed; }
            /**
            * @brief Establece el valor del cursor de vértices.
            * @param cursorV Valor del cursor de vértices (uint).
            */
            inline void setCursorV(const uint &cursorV) { _cursorV = cursorV; }
            /**
            * @brief Establece el valor del cursor de lados.
            * @param cursorE Valor del culrsor de lados (uint).
            */
            inline void setCursorE(const uint &cursorE) { _cursorE = cursorE; }
            /**
            * @brief Establece el número de vértices del grafo.
            * @param vertexes Número de vértices del grafo (uin).
            */
            inline void setVertexes(const uint &vertexes) { _nVertexes = vertexes; }
            /**
            * @brief Establece el número de lados del grafo.
            * @param edges Núnero de lados del grafo (uint).
            */
            inline void setEdges(const uint &edges) { _nEdges = edges; }
            /**
            * @brief Establece la capacidad del grafo.
            * @param capacity Capacidad del grafo (uint).
            */
            inline void setCapacity(const uint &capacity) { _capacity = capacity; }
            /**
            * @brief Comprueba si el grafo está vacío.
            * @return true si el grafo está vacío, false si no.
            * @pre Ambos vértices deben ser vértices válidos del grafo.
            * @sa getVertexes()
            * @sa getEdges()
            */
            inline bool isEmpty() const { return this->getVertexes() == 0 && this->getEdges() == 0; }
            /**
            * @brief Devuelve la distancia entre dos vértices dados.
            * @return Distancia entre dos vértices dados.
            */
            inline double adyacent(const Vertex<std::string> &v1, const Vertex<std::string> &v2) const { return _matrix[v1.getLabel()][v2.getLabel()]; }
            /**
            * @brief Comprueba si el cursor de los vértices está en una posición válida.
            * @return true si el cursor de los vértices está en una posición válida, false si no.
            */
            inline bool hasCurV() const { return _cursorV < _nVertexes; }
            /**
            * @brief Comprueba si el cursor de los lados está en una posición válida.
            * @return true si el cursor de los lados está en una posición válida, false si
            */
            inline bool hasCurE() const { return _cursorE < _nEdges; }
            /**
            * @brief Devuelve el vértice referenciado por el cursor de vértices.
            * @return Vértice referenciado por el cursor de vértices.
            */
            inline Vertex<std::string> curVertex() const { return _vector[_cursorV]; }
            /**
            * @brief Devuelve el lado referenciado por los cursores.
            * @return Lado referenciado por los cursores
            * @sa getCursorV()
            * @sa curVertex()
            * @sa getCursorE()
            * @sa setCursorV()
            * @sa adyacent()
            */
            Edge<double> curEdge() {
                Edge<double> e;
                uint oldCur = this->getCursorV();
                Vertex<std::string> first, second;
                first = this->curVertex();
                this->goTo(this->getCursorE());
                second = this->curVertex();
                this->setCursorV(oldCur);
                e.setData(this->adyacent(first, second));
                e.setFirst(first);
                e.setSecond(second);
                return e;
            }
            /**
            * @brief Añade un vértice al grafo.
            * @param data Vértice a añadir.
            * @pre El número actual de vértices debe ser menoor a la capacidad del grafo.
            * @pre El vértice a añadir no debe estar ya dentro del grafo.
            * @sa getCursorV()
            * @sa getVertexes()
            * @sa getCapacity()
            * @sa searchVertex()
            * @sa setCursorV()
            * @sa setEdges()
            * @sa getEdges()
            */
            void addVertex(const std::string &data) {
#ifdef NDEBUG
                int old = this->getCursorV();
                assert(this->getVertexes() < this->getCapacity());
                assert(!this->searchVertex(data));
                this->setCursorV(old);
#endif
                Vertex<std::string> v;
                v.setData(data);
                v.setLabel(this->getVertexes());
                this->setVertexes(this->getVertexes()+1);
                this->setEdges(this->getEdges()+1);
                _vector.push_back(v);
            }
            /**
            * @brief Añade un lado al grafo.
            * @note Al añadir un lado, se actualiza el valor del peso en la matriz de adyacencias.
            * @param data Distancia a actualizar (double).
            * @param first Primer vértice del lado (Vertex).
            * @param second Segund vértice del lado (Vertex).
            * @pre Ambos vértices deben pertenecer al grafo.
            * @sa getCursorV()
            * @sa searchVertex()
            * @sa setCursorV()
            * @sa getDirected()
            */
            void addEdge(const double &data, const Vertex<std::string> &first, const Vertex<std::string> &second) {
#ifdef NDEBUG
                uint old = this->getCursorV();
                assert(this->searchVertex(first.getData()) && this->searchVertex(second.getData()));
                this->setCursorV(old);
#endif
                _matrix[first.getLabel()][second.getLabel()] = data;
                if(!this->getDirected())
                    _matrix[second.getLabel()][first.getLabel()] = data;
            }
            /**
            * @brief Comprueba si un dato existe en el grafo.
            * @note Adicionalmente, actualiza el cursor de vértices si el dato existe en el grafo.
            * @param data Dato a comprobar si existe en el grafo (string).
            * @return true si el dato existe en el grafo, false si no.
            * @sa getVertexes()
            * @sa setCursorV()
            */
            bool searchVertex(const std::string &data) {
                for( uint i = 0 ; i < this->getVertexes() ; ++i ){
                    if(_vector[i].getData() == data){
                        this->setCursorV(i);
                        return true;
                    }
                }
                return false;
            }
            /**
            * @brief Mueve el cursor de vértices a la posición i-ésima.
            * @note Esta función sirve de interfaz para setCursorV()
            * @param i Posición i-ésima a la que desplacar el cursor (uint).
            * @sa setCursorV()
            */
            inline void goTo(const uint &i) { this->setCursorV(i); }
            /**
            * @brief Mueve el cursor de vértices al principio.
            * @sa goTo()
            */
            inline void beginVertex() { this->goTo(0); }
            /**
            * @brief Mueve el cursor de vértices a la siguiente posición.
            * @sa setCursorV()
            * @sa getCursorV()
            */
            inline void nextVertex() { this->setCursorV(this->getCursorV()+1); }
            /**
            * @brief Comprueba si el valor del cursor de vértices es igual al número de vértices del grafo.
            * @return true si this->getCursorV() == this->getVertexes(), false si no.
            * @sa getCursorV()
            * @sa getVertexes()
            */
            inline bool afterEndVertex() const { return this->getCursorV() == this->getVertexes(); }
            /**
            * @brief Mueve los cursores para situarse en el principio del vértice pasado comoparámetro.
            * @note Si el peso del lado es infinito o no se llega al final, se va incrementando el cursor de lados.
            * @param v Vértice del cuál situarse al principio.
            * @sa setCursorV()
            * @sa setCursorE()
            * @sa getCursorV()
            * @sa getCursorE()
            * @sa afterEndEdge()
            */
            void beginEdge(const Vertex<std::string> &v) {
                this->setCursorV(v.getLabel());
                this->setCursorE(0);
                while((_matrix[this->getCursorV()][this->getCursorE()] == INFINITE) && !(this->afterEndEdge())){
                    this->setCursorE(this->getCursorE()+1);
                }
            }
            /**
            * @brief Mueve el cursor de lados a la siguiente posición válida.
            * @sa setCursorE()
            * @sa getCursorE()
            * @sa getCursorV()
            * @sa afterEndEdge()
            */
            void nextEdge() {
                this->setCursorE(this->getCursorE()+1);
                while((_matrix[this->getCursorV()][this->getCursorE()] == INFINITE) && !(this->afterEndEdge())){
                    this->setCursorE(this->getCursorE()+1);
                }
            }
            /**
            * @brief Comprueba si el valor del cursor de lados es igual al número de lados del grafo.
            * @return true si this->getCursorE() == this->getEdges();
            * @sa getCursorE()
            * @sa setEdges()
            */
            inline bool afterEndEdge() const { return this->getCursorE() == this->getEdges(); }
    };
}

#endif
