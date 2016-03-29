#ifndef __LISTASIMPLEENLAZADAINTERFAZ_HPP__
#define __LISTASIMPLEENLAZADAINTERFAZ_HPP__

namespace ed{
    template <class T>
    class ListaSimpleEnlazadaInterfaz{
        virtual bool isEmpty() const = 0;                                       // Hecho
        virtual T getItem(const uint &index) const = 0;                         // Hecho
        virtual int getIndex(const T &d) const = 0;                             // Hecho
        virtual void insertItem(const T &d) = 0;                                // Hecho
        virtual bool deleteItem(const int &index) = 0;                         // Hecho
        virtual bool isValid(const T &d) const = 0;                             // Hecho
        virtual uint getTotal() const = 0;                                      // Hecho
    };
}

#endif
