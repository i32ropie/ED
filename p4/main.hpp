#ifndef __MAIN_HPP__
#define __MAIN_HPP__

#include <fstream>
#include <string>
#include <cstdio>
#include <unistd.h>
#include <iostream>
#include "graph.hpp"
#include "algoritmos.hpp"
#include "edge.hpp"
#include "vertex.hpp"

ed::Graph *cargarGrafo1( std::string &file_name){
    ed::Graph *g;
    std::ifstream f(file_name.c_str());
    bool dir;
    int n, d;
    double dist;
    std::string c, c2;
    ed::Vertex<std::string> v1, v2;
    f >> n;
    f >> d;
    if(d)
        dir = true;
    else
        dir = false;
    g = new ed::Graph(n,dir);
    for( int i = 0 ; i < n ; ++i ){
        f >> c;
        g->addVertex(c);
    }
    while(f >> c >> c2 >> dist){
        g->searchVertex(c);
        v1 = g->curVertex();

        g->searchVertex(c2);
        v2 = g->curVertex();

        g->addEdge(dist, v1, v2);
    }
    return g;
}


void cargarGrafo2(ed::Graph **g){
    // cabecera();
    // std::string nombre_fichero="grafo_andalucia.txt";
    std::string nombre_fichero="grafo_peninsula.txt";
    // std::cout << "Introduce el nombre del fichero: \e[1;4m";
    // std::cout << "\e[0m";
    // std::cin >> nombre_fichero;
    // if(!existe(nombre_fichero.c_str())){
    //     error("El fichero " + nombre_fichero + " no existe");
    //     return;
    // }
    *g=cargarGrafo1(nombre_fichero);
    std::cout << std::endl << "Grafo actualizado con éxito." << std::endl;
    // volver();
}

void mostrarGrafo(ed::Graph *g){
    ed::Vertex<std::string> v, u;
    ed::Edge<double> e;
    std::vector<ed::Vertex<std::string> > aux = g->getVector();
    std::cout << "Mostrando vector de vértices:" << std::endl;
    g->beginVertex();
    do{
        v = g->curVertex();
        std::cout << v.getData() << " : " << v.getLabel() << std::endl;
        g->nextVertex();
    }while(!g->afterEndVertex());
    std::cout << "Mostrando matriz de adyacencias:" << std::endl;
    g->beginVertex();
    do{
        v = g->curVertex();
        g->beginEdge(v);
        while(!g->afterEndEdge()){
            // std::cout << "ADIOS" << std::endl;
            // fflush(stdout);
            e = g->curEdge();
            std::cout << e.getFirst().getData() << " -> " << e.getSecond().getData() << " : " << e.getData() << std::endl;
            g->nextEdge();
        }
        g->nextVertex();
    }while(!g->afterEndVertex());
}

void floyd(ed::Graph * g){
    // std::string origen="CORDOBA", destiny="BARCELONA";
    std::string origen="CORDOBA", destiny="CADIZ";
    std::vector<std::vector<double> > distances = std::vector<std::vector<double> >(g->getVertexes(), std::vector<double>(g->getVertexes()));
    std::vector<std::vector<int> > mids = std::vector<std::vector<int> >(g->getVertexes(), std::vector<int>(g->getVertexes()));
    Floyd(g, distances, mids, origen, destiny);
}

#endif




/*
do{
    std::cout << "HOLA" << std::endl;
    v = g->curVertex();
    // for( ed::Vertex<std::string> u = aux[0] ; u != aux.end() ; ++u ){
    std::cout << "v.getLabel() = " << v.getLabel() << std::endl;
    std::cout << "aux.size() - 1 = " << aux.size()-1 << std::endl;
    for( int i = 0 ; i < (aux.size() - 1) ; ++i ){
        u = aux[i];
        std::cout << "---------" << std::endl;
        std::cout << "u.getLabel() = " << u.getLabel() << "  u.getData() = " << u.getData() << std::endl;
        std::cout << "v.getLabel() = " << v.getLabel() << "  v.getData() = " << v.getData() << std::endl;
        std::cout << "g->adyacent(u,v) = " << g->adyacent(u,v) << "  g->adyacent(v,u) = " << g->adyacent(u,v) << std::endl;
        std::cout << "---------" << std::endl;
        if( u!=v && (g->adyacent(u,v) != INFINITE) )
            std::cout << v.getData() << " -> " << u.getData() << " : " << g->adyacent(u,v);
    }
    // for ( Vertex<std::string> u = g->beginVertex() ; !g->afterEndVertex() ; u = g->nextVertex()  ){
    //
    // }
    // g->beginEdge(v);
    // while(!g->afterEndEdge()){
    //     std::cout << "ADIOS" << std::endl;
    //     // fflush(stdout);
    //     e = g->curEdge();
    //     std::cout << e.getFirst().getData() << " -> " << e.getSecond().getData() << " : " << e.getData() << std::endl;
    //     g->nextEdge();
    // }
    g->nextVertex();
}while(!g->afterEndVertex());
*/
