#ifndef ALGORITMOS_HPP
#define ALGORITMOS_HPP
// #include "graph_matrix.hpp"
#include <vector>
#include <string>
#include "graph.hpp"

void Path(ed::Graph * g, ed::Vertex<std::string> &origen, ed::Vertex<std::string> &destiny, std::vector<std::vector<int> > &mids);
void Floyd(ed::Graph * g, std::vector<std::vector<double> > &distances, std::vector<std::vector<int> > &mids, const std::string &origen, const std::string &destiny);

// using namespace edi;
// void reservarMatriz(int tam,double **m);
// void reservarMatriz(int tam,int **m);
// void Floyd(GraphMatrix * &g,double **distancias,int **intermedios);
// void camino(GraphMatrix *g,Vertex &origen,Vertex &destino,int ** intermedios);
// void recorridoProfundidad(GraphMatrix *g, Vertex nodo, bool *visitado);
#endif
