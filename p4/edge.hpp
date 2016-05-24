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
            /** @name Observadores. */
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
            /** @name Modificadores. */
            /**
            * @brief Establece el dato del lado.
            * @param data Dato del lado.
            */
            inline void setData(const T &data) { _data = data; }
            /**
            * @brief Establece el primer vértice del lado.
            * @param first Vértice.
            */
            inline void setFirst(const Vertex<std::string> &first) { _first = first; }
            /**
            * @brief Establece el segundo vértice del lado.
            * @param second Vértice.
            */
            inline void setSecond(const Vertex<std::string> &second) { _second = second; }
            /** @name Sobrecarga de operadores. */
            /**
            * @brief Sobrecarga del operador ==
            * @param e Lado.
            * @return true si this->getFirst() == e.getFirst() && this->getSecond() == e.getSecond(), false si no.
            * @sa getFirst()
            * @sa getSecond()
            */
            inline bool operator == (const Edge<T> &e) const { return this->getFirst() == e.getFirst() && this->getSecond() == e.getSecond(); }
    };
}

#endif
