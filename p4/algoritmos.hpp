#ifndef ALGORITMOS_HPP
#define ALGORITMOS_HPP

#include <vector>
#include <iostream>
#include <string>
#include "graph.hpp"
#include "vertex.hpp"

void Path(ed::Graph * g, ed::Vertex<std::string> &origen, ed::Vertex<std::string> &destiny, std::vector<std::vector<int> > &mids){
    if(mids[origen.getLabel()][destiny.getLabel()] != -1){
        g->goTo(mids[origen.getLabel()][destiny.getLabel()]);
        ed::Vertex<std::string> mid = g->curVertex();
        Path(g, origen, mid, mids);
        std::cout << mid.getData() << " ";
        Path(g, mid, destiny, mids);
    }
}

// Inicializar fuera 'distances' y 'mids'
void Floyd(ed::Graph * g, std::vector<std::vector<double> > &distances, std::vector<std::vector<int> > &mids, const std::string &origen, const std::string &destiny){
    int vertexes = g->getVertexes();
    ed::Vertex<std::string> u, v;
    for( int i = 0 ; i < vertexes ; ++i ){
        for( int j = 0 ; j < vertexes ; ++j ){
            mids[i][j] = -1;
            if(i==j){
                distances[i][j] = 0;
            }
            else{
                g->goTo(i);
                u = g->curVertex();
                g->goTo(j);
                v = g->curVertex();
                distances[i][j] = g->adyacent(u, v);
            }
        }
    }
    for( int k = 0 ; k < vertexes ; ++k ){
        for( int i = 0 ; i < vertexes ; ++i ){
            for( int j = 0 ; j < vertexes ; ++j ){
                if( distances[i][j] > ( distances[i][k] + distances[k][j] ) ){
                    distances[i][j] = distances[i][k] + distances[k][j];
                    mids[i][j] = k;
                }
            }
        }
    }
    g->searchVertex(origen);
    u = g->curVertex();
    g->searchVertex(destiny);
    v = g->curVertex();
    if( distances[u.getLabel()][v.getLabel()] == INFINITE ){
        std::cout << "No existe la distancia mínima" << std::endl;
        return;
    }
    std::cout << "La distancia mínima entre <" << u.getData() << "> y <" << v.getData() << "> es: \e[1m" << distances[u.getLabel()][v.getLabel()] << "\e[m" << std::endl;
    std::cout << "El camino mínimo es: " << origen << " ";
    Path(g,u,v,mids);
    std::cout << destiny << std::endl;
}
#endif
