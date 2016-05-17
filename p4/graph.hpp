#ifndef __GRAPH_HPP__
#define __GRAPH_HPP__

#include <vector>
#include <cassert>
#include <iostream>
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
            std::vector<std::vector<double> > _matrix;
            // Matriz de adyacencias v2.
            // ¿Grafo dirigido?
            bool _directed;
            // Cursor _vector (Vértices) o primera posición _matrix.
            int _cursorV; // UINT
            // Cursor segunda posición _matrix.
            int _cursorM; // CAMBIAR A _cursorE;
            // Número de vértices.
            int _nVertexes;
            // Número de lados.
            int _nEdges;
            // Capacidad. (CREO QUE HAY QUE QUITARLO)
            int _capacity;
        public:
            // METER SI ES DIRECTED O NO, Y LLAMAR A makeDirected O makeUndirected
            Graph(const int &capacity=0, const bool &directed=true){
                assert(capacity>=0);
                this->setCapacity(capacity);
                this->setVertexes(0);
                this->setEdges(0);
                this->setCursorV(0);
                this->setCursorM(0);
                // ESTO VALE COMO 'makeDirected'
                this->setDirected(directed);
                /*
primero puntero a grafo (se crea dinamicamente a partir de un fichero)
    - 1º numero de nodos
    - 2º dirigido o no
    - voy leyendo lados
    - despues pongo distancia de los lados
FUNCION ADYACENT DEVUELVE EL PESO DEL LADO
                */
                // RELLENAR LA MATRIZ DE LA OTRA FORMA
                _matrix = std::vector< std::vector< double > >(capacity, std::vector< double >(capacity));
                for( int i = 0 ; i < capacity ; ++i){
                    for( int j = 0 ; j < capacity ; ++j){
                        _matrix[i][j] = INFINITE;
                    }
                }
                // _matrix = new double *[this->getCapacity()];
                // for( int i = 0 ; i < this->getCapacity() ; ++i )
                //     _matrix[i] = new double [this->getCapacity()];
                // for( int i = 0 ; i < this->getCapacity() ; ++i ){
                //     for( int j = 0 ; j < this->getCapacity() ; ++j ){
                //         _matrix[i][j] = INFINITE;
                //     }
                // }
            }
            inline std::vector<Vertex<std::string> > getVector() const { return _vector; }
            inline std::vector<std::vector<double> > getMatrix() const { return _matrix; }
            inline bool getDirected() const { return _directed; }
            inline int getCursorV() const { return _cursorV; }
            inline int getCursorM() const { return _cursorM; }
            inline int getVertexes() const { return _nVertexes; }
            inline int getEdges() const { return _nEdges; }
            inline int getCapacity() const { return _capacity; }
            inline void setVector(const std::vector<Vertex<std::string> > &vector) { _vector = vector; }
            inline void setMatrix(const std::vector<std::vector<double> > &matrix) { _matrix = matrix; }
            inline void setDirected(const bool &directed) { _directed = directed; }
            inline void setCursorV(const int &cursorV) { _cursorV = cursorV; }
            inline void setCursorM(const int &cursorM) { _cursorM = cursorM; }
            inline void setVertexes(const int &vertexes) { _nVertexes = vertexes; }
            inline void setEdges(const int &edges) { _nEdges = edges; }
            inline void setCapacity(const int &capacity) { _capacity = capacity; }

            inline bool isEmpty() const { return this->getVertexes() == 0 && this->getEdges() == 0; }
            inline double adyacent(const Vertex<std::string> &v1, const Vertex<std::string> &v2) const { return _matrix[v1.getLabel()][v2.getLabel()]; } // USAR CURSORES (CREO QUE NO HACE FALTA :DDDDDD)
            // Comprueba si el cursor de los vertices esta en una posicion valida
            inline bool hasCurV() const { return _cursorV < _nVertexes; }
            inline bool hasCurM() const { return _cursorM < _nEdges; }
            // Devuelve el vértice referenciado por el cursor
            Vertex<std::string> curVertex() const {
                // assert(this->hasCurV());
                return _vector[_cursorV];
            }
            Edge<double> curEdge() { // MIRAR PARA MOVER CURSORES Y TAL (USANDO GOTO)
                // assert(this->hasCurM());
                Edge<double> e;
                // //
                // int oldCur = this->getCursorV();
                // Vertex<std::string> first, last;
                // first = this->curVertex();
                // this->goTo(this->getCursorM()); // CAMBIAR A _cursorM
                // last = this->curVertex();
                // //
                e.setData(_matrix[this->getCursorV()][this->getCursorM()]);
                e.setFirst(_vector[this->getCursorV()]);
                e.setSecond(_vector[this->getCursorM()]);
                // //
                // this->setCursorV(oldCur);
                // //
                return e;
            }
            inline void makeDirected() { _directed = true; }
            inline void makeUndirected() { _directed = false; }
            // Añade un vértice pasándole la ciudad.
            void addVertex(const std::string &data) {
                // COMPROBAR CAPACIDAD Y QUE NO ESTE YA EL VERTICE
                Vertex<std::string> v;
                v.setData(data);
                v.setLabel(this->getVertexes());
                this->setVertexes(this->getVertexes()+1);
                this->setEdges(this->getEdges()+1);
                _vector.push_back(v);
            }
            // Añadir un lado (Edge)
            void addEdge(const double &data, const Vertex<std::string> &v1, const Vertex<std::string> &v2) { // N_EDGES ++
                assert(v1.getLabel() < this->getVertexes() && v2.getLabel() < this->getVertexes()); // COMPROBAR QUE EXISTEN LOS VERTICES
                _matrix[v1.getLabel()][v2.getLabel()] = data;
                // this->setEdges(this->getEdges()+1);
                // Si no es dirigido, lo metemos al contrario tmb
                if(!this->getDirected())
                    _matrix[v2.getLabel()][v1.getLabel()] = data;
                    // this->setEdges(this->getEdges()+1);
            }
            // Mueve el cursorV recibiendo una ciudad
            bool searchVertex(const std::string &data) {
                for( int i = 0 ; i < this->getVertexes() ; ++i ){
                    if(_vector[i].getData() == data){
                        this->setCursorV(i);
                        return true;
                    }
                }
                return false;
            }
            // Mueve el cursorV recibiendo un vértice
            void goTo(const Vertex<std::string> &v) {
                this->searchVertex(v.getData());
                // for( int i = 0 ; i < this->getVertexes() ; ++i ){
                //     if(_vector[i] == v){
                //         this->setCursorV(i);
                //         return;
                //     }
                // }
            }
            void goTo(const int &i){
                // assert posicion valida
                this->setCursorV(i);
            }
            // Mueve el cursorE
            void searchEdge(const Vertex<std::string> &v1, const Vertex<std::string> &v2) {
                assert(v1.getLabel() < this->getVertexes() && v2.getLabel() < this->getVertexes());
                this->setCursorV(v1.getLabel());
                this->setCursorM(v2.getLabel());
            }
            /*
Las tres funciones siguientes son para recorrer el grafo asi:
g->beginVertex();
do{
    v = g->curVertex();
    // Lo que sea
    g->nextVertex();
}while(!g->afterEndVertex());
            */
            inline void beginVertex() { this->goTo(0); } // No hace falta, llamar a goto(0) a pelo
            inline void nextVertex() { this->setCursorV(this->getCursorV()+1); }
            inline bool afterEndVertex() const { return this->getCursorV() == this->getVertexes(); }
            //
            void beginEdge(const Vertex<std::string> &v) {
                this->setCursorV(v.getLabel());
                this->setCursorM(0);
                while((_matrix[this->getCursorV()][this->getCursorM()] == INFINITE) && !(this->afterEndEdge())){
                    this->setCursorM(this->getCursorM()+1);
                }
            }
            void nextEdge() {
                this->setCursorM(this->getCursorM()+1);
                while((_matrix[this->getCursorV()][this->getCursorM()] == INFINITE) && !(this->afterEndEdge())){
                    this->setCursorM(this->getCursorM()+1);
                }
            }
            bool afterEndEdge() const {
                return this->getCursorM() == this->getEdges();
             }
    };
}

#endif


/*
    :CARGAR GRAFO:

-USAR EN MAIN PUNTERO A GRAFO, YA SE RESERVA MEMORIA DESPUES EN FUNCIONES DE ENTRADA_SALIDA
-METEMOS LOS VERTICES
while(f >> dataEdgeFirst >> dataEdegeSecond >> weight){
    g->searchVertex(dataEdgeFirst);
    first.setLabel(g->curVertex().getLabel());
    first.setData(dataEdgeFirst);

    g->searchVertex(dataEdegeSecond);
    second.setLabel(g->curVertex().getLabel());
    second.setData(dataEdegeSecond);

    g->addEdge(weight, first, second);
}



*/
