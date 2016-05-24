/**
* @file vertex.hpp
* @brief <Práctica 4> Primera parte: Representación del TAD vértice.
* @author Eduardo Roldán Pijuán
* @date Mayo de 2016
*/

#ifndef __VERTEX_HPP__
#define __VERTEX_HPP__

/**
* @brief Espacio de nombres para la asignatura Estructuras de Datos.
*/

namespace ed {
    /// Clase Vertex.
    template <class T>
    class Vertex{
        private:
            /// Etiqueta del vértice.
            int _label;
            /// Dato del vértice.
            T _data;
        public:
            /** @name Observadores. */
            /**
            * @brief Devuelve la etiqueta del vértice.
            * @return Etiqueta del vértice.
            */
            inline const int & getLabel() const { return _label; }
            /**
            * @brief Devuelve el dato del vértice.
            * @return Dato del vértice.
            */
            inline const T & getData() const { return _data; }
            /** @name Modificadores. */
            /**
            * @brief Establece la etiqueta del vértice.
            * @param label Etiqueta del vértice.
            */
            inline void setLabel(const int &label) { _label = label; }
            /**
            * @brief Establece el dato del vértice
            * @param data Dato del vértice
            */
            inline void setData(const T &data) { _data = data; }
            /** @name Sobrecarga de operadores. */
            /**
            * @brief Sobrecarga del operador ==
            * @param v Vértice.
            * @return true si this->getData() == v.getData(), false si no.
            * @sa getData()
            */
            inline bool operator == (const Vertex<T> &v) const { return this->getData() == v.getData(); }
            /**
            * @brief Sobrecarga del operador !=
            * @param v Vértice.
            * @return true si this->getData() != v.getData(), false si no.
            * @sa getData()
            */
            inline bool operator != (const Vertex<T> &v) const { return this->getData() != v.getData(); }
    };
}

#endif
