/**
* @file edge.hpp
* @brief <Práctica 4> Primera parte: Representación del TAD lado.
* @author Eduardo Roldán Pijuán
* @date Mayo de 2016
*/

#ifndef __EDGE_HPP__
#define __EDGE_HPP__

#include <string>
#include "vertex.hpp"

/**
* @brief Espacio de nombres para la asignatura Estructuras de Datos.
*/

namespace ed {
    /// Clase Edge.
    template <class T>
    class Edge {
        private:
            /// Dato del lado.
            T _data;
            /// Primer vértice.
            Vertex<std::string> _first;
            /// Segundo vértice.
            Vertex<std::string> _second;
        public:
            /**
            * @brief Devuelve el dato del lado.
            * @return Dato del lado.
            */
            inline T getData() const { return _data; }
            /**
            * @brief Devuelve el primer vértice del lado.
            * @return Primer vértice del lado.
            */
            inline Vertex<std::string> getFirst() const { return _first; }
            /**
            * @brief Devuelve el segundo vértice del lado.
            * @return Segundo vértice del lado.
            */
            inline Vertex<std::string> getSecond() const { return _second; }
            inline void setData(const T &data) { _data = data; }
            inline void setFirst(const Vertex<std::string> &first) { _first = first; }
            inline void setSecond(const Vertex<std::string> &second) { _second = second; }
            inline bool has(const Vertex<std::string> &v) const { return v == this->getFirst() || v == this->getSecond(); }
            inline bool operator == (const Edge<T> &e) const { return this->getFirst() == e.getFirst() && this->getSecond() == e.getSecond(); }
    };
}

#endif
