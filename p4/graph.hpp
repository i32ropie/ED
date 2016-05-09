#ifndef __GRAPH_HPP__
#define __GRAPH_HPP__

#include <vector>
#include <cassert>
#include <string>
#include "vertex.hpp"
#include "edge.hpp"
#include "extra.hpp"

namespace ed {
    class Graph {
        private:
            // Todas las ciudades con sus respectivas labels
            std::vector<Vertex<std::string> > _vector;
            // Matriz de adyacencias v1.
            // std::vector<std::vector<double>> _adyacencias;
            // Matriz de adyacencias v2.
            double **_matrix;
            // ¿Grafo dirigido?
            bool _directed;
            // Cursor _vector (Vértices) o primera posición _matrix.
            int _cursorV;
            // Cursor segunda posición _matrix.
            int _cursorM;
            // Número de vértices.
            int _nVertexes;
            // Número de lados.
            int _nEdges;
            // Capacidad.
            int _capacity;
        public:
            Graph(const int &capacity=0, const bool &directed=true){
                assert(capacity>=0);
                this->setCapacity(capacity);
                this->setVertexes(0);
                this->setEdges(0);
                this->setDirected(directed);
                _matrix = new double *[this->getCapacity()];
                for( int i = 0 ; i < this->getCapacity() ; ++i )
                    _matrix[i] = new double [this->getCapacity()];
                for( int i = 0 ; i < this->getCapacity() ; ++i ){
                    for( int j = 0 ; j < this->getCapacity() ; ++j ){
                        _matrix[i][j] = INFINITE;
                    }
                }
            }
            inline std::vector<Vertex<std::string> > getVector() const { return _vector; }
            inline double ** getMatrix() const { return _matrix; }
            inline bool getDirected() const { return _directed; }
            inline int getCursorV() const { return _cursorV; }
            inline int getCursorM() const { return _cursorM; }
            inline int getVertexes() const { return _nVertexes; }
            inline int getEdges() const { return _nEdges; }
            inline int getCapacity() const { return _capacity; }
            inline void setVector(const std::vector<Vertex<std::string> > &vector) { _vector = vector; }
            inline void setMatrix(double **matrix) { _matrix = matrix; }
            inline void setDirected(const bool &directed) { _directed = directed; }
            inline void setCursorV(const int &cursorV) { _cursorV = cursorV; }
            inline void setCursorM(const int &cursorM) { _cursorM = cursorM; }
            inline void setVertexes(const int &vertexes) { _nVertexes = vertexes; }
            inline void setEdges(const int &edges) { _nEdges = edges; }
            inline void setCapacity(const int &capacity) { _capacity = capacity; }

            inline bool isEmpty() const { return this->getVertexes() == 0 && this->getEdges() == 0; }
            inline bool adyacent(const Vertex<std::string> &v1, const Vertex<std::string> &v2) const { return _matrix[v1.getLabel()][v2.getLabel()] != 3200; }
            // Comprueba si el cursor de los vertices esta en una posicion valida
            inline bool hasCurV() const { return _cursorV < _nVertexes; }
            inline bool hasCurM() const { return _cursorM < _nEdges; }
            // Devuelve el vértice referenciado por el cursor
            Vertex<std::string> curVertex() const {
                assert(this->hasCurV());
                return _vector[_cursorV];
            }
            Edge<double> curEdge() const{
                assert(this->hasCurM());
                Edge<double> e;
                e.setData(_matrix[this->getCursorV()][this->getCursorM()]);
                e.setFirst(_vector[this->getCursorV()]);
                e.setSecond(_vector[this->getCursorM()]);
                return e;
            }
            inline void makeDirected() { _directed = true; }
            inline void makeUndirected() { _directed = false; }
            // Añade un vértice pasándole la ciudad.
            void addVertex(const std::string &data) {
                Vertex<std::string> v;
                v.setData(data);
                v.setLabel(this->getVertexes());
                this->setVertexes(this->getVertexes()+1);
                _vector.push_back(v);
            }
            // Añadir un lado (Edge)
            void addEdge(const double &data, const Vertex<std::string> &v1, const Vertex<std::string> &v2) {
                assert(v1.getLabel() < this->getVertexes() && v2.getLabel() < this->getVertexes());
                _matrix[v1.getLabel()][v2.getLabel()] = data;
                // Si no es dirigido, lo metemos al contrario tmb
                if(!this->getDirected())
                    _matrix[v2.getLabel()][v1.getLabel()] = data;
            }
            // Mueve el cursorV recibiendo una ciudad
            void searchVertex(const std::string &data) {
                for( int i = 0 ; i < this->getVertexes() ; ++i ){
                    if(_vector[i].getData() == data){
                        this->setCursorV(i);
                        return;
                    }
                }
            }
            // Mueve el cursorV recibiendo un vértice
            void goTo(const Vertex<std::string> &v) {
                for( int i = 0 ; i < this->getVertexes() ; ++i ){
                    if(_vector[i] == v){
                        this->setCursorV(i);
                        return;
                    }
                }
            }
            // Mueve el cursorE
            void searchEdge(const Vertex<std::string> &v1, const Vertex<std::string> &v2) {
                assert(v1.getLabel() < this->getVertexes() && v2.getLabel() < this->getVertexes());
                this->setCursorV(v1.getLabel());
                this->setCursorM(v2.getLabel());
            }
            inline Vertex<std::string> beginVertex() const { return _vector[this->getCursorV()]; }
            inline void beginVertexS() { this->setCursorV(this->getCursorV()+1); }
    };
}

#endif
