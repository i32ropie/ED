#ifndef __EDGE_HPP__
#define __EDGE_HPP__

#include <string>
#include "vertex.hpp"

namespace ed {
    template <class T>
    class Edge {
        private:
            T _data;
            Vertex<std::string> _first;
            Vertex<std::string> _second;
        public:
            inline T getData() const { return _data; }
            inline Vertex<std::string> getFirst() const { return _first; }
            inline Vertex<std::string> getSecond() const { return _second; }
            inline void setData(const T &data) { _data = data; }
            inline void setFirst(const Vertex<std::string> &first) { _first = first; }
            inline void setSecond(const Vertex<std::string> &second) { _second = second; }
            inline bool has(const Vertex<std::string> &v) const { return v == this->getFirst() || v == this->getSecond(); }
            inline bool operator == (const Edge<T> &e) const { return this->getFirst() == e.getFirst() && this->getSecond() == e.getSecond(); }
    };
}

#endif
