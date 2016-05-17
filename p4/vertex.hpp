#ifndef __VERTEX_HPP__
#define __VERTEX_HPP__

// #include <string>

namespace ed {
    template <class T>
    class Vertex{
        private:
            int _label;
            T _data;
        public:
            inline const int & getLabel() const { return _label; }
            inline const T & getData() const { return _data; }
            inline void setLabel(const int &label) { _label = label; }
            inline void setData(const T &data) { _data = data; }
            inline bool operator == (const Vertex<T> &v) const { return this->getData() == v.getData(); }
            inline bool operator != (const Vertex<T> &v) const { return this->getData() != v.getData(); }
    };
}

#endif
