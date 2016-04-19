#ifndef __BOUNDEDMINHEAPINTERFAZ_HPP__
#define __BOUNDEDMINHEAPINTERFAZ_HPP__

namespace ed{
    template <class T>
    class BoundedMinHeapInterfaz{
        public:
            virtual bool isEmpty() const = 0;
            virtual T top() const = 0;
            virtual void insert(const T &d) = 0;
            virtual void remove() = 0;
    };
}

#endif
