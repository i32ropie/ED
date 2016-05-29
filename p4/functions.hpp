/**
* @file functions.hpp
* @brief <Práctica 4> Segunda parte: Algoritmo de Floyd y camino mínimo.
* @author Eduardo Roldán Pijuán
* @date Mayo de 2016
*/

#ifndef __FUNCTIONS_HPP__
#define __FUNCTIONS_HPP__

#include <vector>
#include <iostream>
#include <string>
#include "graph.hpp"
#include "vertex.hpp"

/**
* @brief Función recursiva que calcula el camino mínimo entre dos vértices.
* @param g Grafo (Graph).
* @param origen Vértice de origen (Vertex<string>).
* @param destiny Vértide de destino (Vertex<string>).
* @param mids Matriz de intermedios (vetor<vector<int>>).
* @sa pprint()
* @sa Path()
*/
void Path(ed::Graph * g, ed::Vertex<std::string> &origen, ed::Vertex<std::string> &destiny, std::vector<std::vector<int> > &mids){
    if(mids[origen.getLabel()][destiny.getLabel()] != -1){
        g->goTo(mids[origen.getLabel()][destiny.getLabel()]);
        ed::Vertex<std::string> mid = g->curVertex();
        Path(g, origen, mid, mids);
        std::cout << "\e[1;4;92m"<< mid.getData() << "\e[m \e[1;33m->\e[m ";
        Path(g, mid, destiny, mids);
    }
}

/**
* @brief Algoritmo de Floyd
* @param g Grafo (Graph).
* @param distances Matriz de distancias (vector<vector<double>>).
* @param mids Matriz de intermedios (vector<vector<int>>).
*/
void Floyd(ed::Graph * g, std::vector<std::vector<double> > &distances, std::vector<std::vector<int> > &mids){
    int vertexes = g->getVertexes();                                            // Almacenamos el número de vértices del grafo en una variable para no llamar múltiples veces a la función.
    ed::Vertex<std::string> u, v;
    for( int i = 0 ; i < vertexes ; ++i ){
        for( int j = 0 ; j < vertexes ; ++j ){
            mids[i][j] = -1;                                                    // En principio, no conocemos los intermedios, por lo que inicializamos la matriz a -1, que es un identificador no válido.
            if(i==j){                                                           // En caso de que ambos vértices sean la misma ciudad, establecemos la distancia entre ambos a 0.
                distances[i][j] = 0;
            }
            else{
                g->goTo(i);
                u = g->curVertex();
                g->goTo(j);
                v = g->curVertex();
                distances[i][j] = g->adyacent(u, v);                            // En caso contrario, llamamos a la función adyacent de la clase Graph que nos devolverá la distancia entre dos vértices cualesquiera.
            }
        }
    }
    for( int k = 0 ; k < vertexes ; ++k ){
        for( int i = 0 ; i < vertexes ; ++i ){
            for( int j = 0 ; j < vertexes ; ++j ){
                if( distances[i][j] > ( distances[i][k] + distances[k][j] ) ){  // Comprobamos por cada par de vértices si la distancia de uno a otro utilizando un intermedio es menor.
                    distances[i][j] = distances[i][k] + distances[k][j];        // De ser así, actualizamos la distancia que hay entre ambos vértices...
                    mids[i][j] = k;                                             // ... e indicamos que hemos encontrado un vértice intermedio entre ambos.
                }
            }
        }
    }
}
#endif
