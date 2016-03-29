#ifndef __LISTASIMPLEENLAZADA_HPP__
#define __LISTASIMPLEENLAZADA_HPP__

#include "listasimpleenlazadainterfaz.hpp"

namespace ed{

    template <class T>
    struct Nodo{
        T data;
        Nodo *next;
        Nodo(const T &d): data(d), next(0){}
    };

    template <class T>
    class ListaSimpleEnlazada:public ListaSimpleEnlazadaInterfaz<T>{
        private:
            Nodo<T> *_head;
            uint _total;
        public:
            ListaSimpleEnlazada(): _head(0), _total(0){}
            uint getTotal() const{
                return _total;
            }
            bool isEmpty() const{
                return _head == 0;
            }
            void insertItem(const T &d){
                Nodo<T> *n = new Nodo<T>(d);
                if(this->isEmpty()){
                    _head = n;
                }
                else{
                    if(_head->data <= d){
                        Nodo<T> *curr = _head;
                        Nodo<T> *prev = 0;
                        bool found = false;
                        while(curr && !found){
                            if(curr->data <= d){
                                prev = curr;
                                curr = curr->next;
                            }
                            else{
                                found = true;
                            }
                        }
                        prev->next = n;
                        n->next = curr;
                    }
                    else{
                        n->next = _head;
                        _head = n;
                    }
                }
                _total++;
            }
            bool deleteItem(const int &index){
                if(this->isEmpty() || index == -1){
                    return false;
                }
                T d = this->getItem(index);
                if(d == _head->data){
                    _head = _head->next;
                    _total--;
                    return true;
                }
                Nodo<T> *curr = _head;
                Nodo<T> *prev = 0;
                bool found = false;
                while(curr && !found){
                    if(d == curr->data){
                        found = true;
                    }
                    else{
                        prev = curr;
                        curr = curr->next;
                    }
                }
                if(found){
                    prev->next = curr->next;
                    _total--;
                    return true;
                }
                else{
                    return false;
                }

            }
            T getItem(const uint &index) const{
                assert(index>=1 && index<=_total);
                assert(!this->isEmpty());
                Nodo<T> *curr = _head;
                for( uint x = 1 ; x < index ; ++x ){
                    curr = curr->next;
                }
                return curr->data;
            }
            int getIndex(const T &d) const{
                if(this->isEmpty()){
                    return -1;
                }
                int index = -1;
                bool found = false;
                for( uint x = 1 ; x <= this->getTotal() && !found ; ++x ){
                    if(this->getItem(x) == d){
                        index = x;
                        found = true;
                    }
                }
                return index;
            }
            bool isValid(const T &d) const{
                int index;
                if((index = this->getIndex(d)) == -1){
                    return false;
                }
                else{
                    return true;
                }
            }
    };
}

#endif
