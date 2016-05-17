#include <iostream>
#include <vector>
#include "algoritmos.hpp"
#include "vertex.hpp"
#include "graph.hpp"

// void Floyd(ed::Graph * g,double **distancias,int **intermedios, string origen)
// {
// int i,j,k;
// double distanciaT;
// Vertex u,v;
// string destino;
//
// //Reservamos memoria para las dos matrices    PONER BONITO :>
// distancias=new double*[g->capacity()];//cambiar capacity
// for(int i=0;i<g->capacity();i++)
// distancias[i]=new double[g->capacity()];
//
//
// intermedios=new int*[g->capacity()];
// for(int i=0;i<g->capacity();i++)
// intermedios[i]=new int[g->capacity()];
//
//
//
// 	for(i=0;i<g->numVertexes();i++) // g->getVertexes()
// 	{
// 		for(j=0;j<g->numVertexes();j++)
// 		{
// 		intermedios[i][j]=-1;
// 		if(i==j)
// 		distancias[i][j]=0;
// 		else{
// 		g->goTo(i);
// 		u=g->currVertex();  // curVertex()
// 		g->goTo(j);
// 		v=g->currVertex();
// 		distancias[i][j]=g->adjacent(u,v);} // CAMBIAR EN Graph
// 		}
// 	}
//
// for(k=0;k<g->numVertexes();k++)
// {
// 	for(i=0;i<g->numVertexes();i++)
// 	{
// 		for(j=0;j<g->numVertexes();j++)
// 		{
// 			if( distancias[i][j] > ( (distancias[i][k]) + (distancias[k][j]) ) )
// 			{
// 			distancias[i][j]=( distancias[i][k]+distancias[k][j] );
// 			intermedios[i][j]=k;
// 			}
// 		}
// 	}
// }
// // PEDIR EN LA MAIN
// // cout<<"Introduce el primer nodo: ";
// // cin>>origen;
// g->searchVertex(origen);
// u=g->currVertex();
//
//
// cout<<"Introduce el segundo nodo: ";
// cin>>destino;
// g->searchVertex(destino);
// v=g->currVertex();
//
// 	if( distancias[u.getLabel()][v.getLabel()] == 32000 ) // INFINITE
// 	cout<<"No existe distancia mínima"<<endl;
// 	else
// 	cout<<"La distancia mínima entre "<<u.getData()<<" y "<<v.getData()<<" es: "<<distancias[u.getLabel()][v.getLabel()]<<endl;
//
// 	cout<<"El camino mínimo es: ";
// 	cout<<origen<<" ";
// 	// camino(g,u,v,intermedios);
// 	cout<<destino<<endl;
//
// }


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
    // int i, j, k;
    int vertexes = g->getVertexes();
    double distanceT;
    ed::Vertex<std::string> u, v;
    // distances = std::vector<std::vector<double> >(g->getVertexes(), std::vector<double>(g->getVertexes()));
    // mids = std::vector<std::vector<int> >(g->getVertexes(), std::vector<int>(g->getVertexes()));
    // std::string destiny;
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



// void camino(GraphMatrix *g,Vertex &origen,Vertex &destino,int **intermedios){
//
// 	if(intermedios[origen.getLabel()][destino.getLabel()] != -1){
// 		g->goTo(intermedios[origen.getLabel()][destino.getLabel()]);
// 		Vertex intermedio=g->currVertex();
// 		camino(g,origen,intermedio,intermedios);
// 		cout<<intermedio.getData()<<" ";
// 		camino(g,intermedio,destino,intermedios);
// 	}
// }
//
//
// void recorridoProfundidad(GraphMatrix *g, Vertex nodo, bool *visitado)
// {
//      int i;
//      Vertex u;
//
//      visitado[nodo.getLabel()] = true;
//      cout << nodo.getData() << " ";
//
//      for (i = 0; i < g->numVertexes(); i++)
//      {
// 	g->goTo(i);
// 	u=g->currVertex();
//          if (g->adjacent(nodo, u) < 32000 && visitado[i] ==  false)
//             recorridoProfundidad(g,u,visitado);
//      }
// }
