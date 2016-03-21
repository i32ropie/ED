#ifndef __DONANTESINTERFAZ_HPP__
#define __DONANTESINTERFAZ_HPP__

#include <string>

namespace ed{
    template <class T>
    class DonantesInterfaz{
        public:
            virtual void insertarDonante(const T &d) = 0;
            virtual bool borrarDonante(const T &d) = 0;
            virtual bool buscarDonante(T &d) const = 0;
            virtual bool estaVacia() const = 0;
    };
}

#endif
