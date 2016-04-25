#ifndef __BOUNDEDMINHEAP_HPP__
#define __BOUNDEDMINHEAP_HPP__

#include <vector>
#include <cassert>
#include <iostream>
#include "boundedminheapinterfaz.hpp"
#include "extra.hpp"

namespace ed{
    template <class T>
    class BoundedMinHeap: public BoundedMinHeapInterfaz<T>{
        private:
            std::vector<T> _data;
            int lastItem() const{
                return _data.size();
            }
            int leftChild(const int &i) const{
                return i*2+1;
            }
            int rightChild(const int &i) const{
                return i*2+2;
            }
            int parent(const int &i) const{
                return (i-1)/2;
            }
            void shiftUp(const int &i){
                if( i > 0 && (_data[i]) < (_data[this->parent(i)])){
                    swap(_data, i, this->parent(i));
                    this->shiftUp(parent(i));
                }
            }
            void shiftDown(const int &i){
                int n = i;
                int lC = this->leftChild(i);
                int rC = this->rightChild(i);
                if( (lC < this->lastItem()) && (_data[lC] < _data[n]) ){
                    n=lC;
                }
                if( (rC < this->lastItem()) && (_data[rC] < _data[n]) ){
                    n=rC;
                }
                if( i != n ){
                    swap(_data, i, n);
                    this->shiftDown(n);
                }
            }
            bool has(const T &d){
                for( int i = 0 ; i < this->lastItem() ; ++i ){
                    if(_data[i] == d)
                        return true;
                }
                return false;
            }

        public:
            // BoundedMinHeap(){}
            bool isEmpty() const{
                return _data.empty();
            }
            /// prec: assert(!this->isEmpty())
            T top() const{
                assert(!this->isEmpty());
                return _data[0];
            }
            void insert(const T &d){
                if(!this->has(d)){
                    _data.push_back(d);
                    this->shiftUp(this->lastItem()-1);
                }
            }
            /// prec: assert(!this->isEmpty())
            void remove(){
                if( this->lastItem()-1 > 0){
                    _data[0] = _data[this->lastItem()-1];
                    _data.pop_back();
                    this->shiftDown(0);
                }
                else if( this->lastItem() == 1){
                    _data.pop_back();
                }
            }
    };
}

#endif
