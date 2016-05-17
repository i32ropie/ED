
// #include <fstream>
// #include <string>
#include "main.hpp"
#include "graph.hpp"


int main() {
    ed::Graph *g;
    unsigned int opcion;
    bool salir;
    cargarGrafo2(&g);
    // mostrarGrafo(g);
    floyd(g);
    // FORZAR QUE META PRIMERO EL NOMBRE | AÑADIR PRECARGAR????
    // do{
    //     opcion = opciones();
    //     switch (opcion) {
    //         case 0:
    //             despedida();
    //             salir = true;
    //             break;
    //         case 1:
    //             cargarGrafo2(&g);
    //             break;
    //         case 2:
    //             mostrarGrafo(g);
    //             break;
    //         case 3:
                    // INICIALIZAR VECTOR DE DOUBLES 'dist_sum'
                    // sumDist(g,dist_sum)
                    // mostrarMinimo(dist_sum)

// ESTO METERLO EN FUNCIONACA EN MAIN.HPP
// CORDOBA = 595
                    // g->searchVertex(origen);
                    // u = g->curVertex();
                    // std::cout << u.getData() << " : " << dist_sum[u.getLabel()] << std::endl;

    //             aplicarFloyd(g);
    //             break;
    //     }
    // }while(!salir);
    return 0;
}
/*
void sumDist(Grafo *g, vector<double> dist_sum){
    Vertex u,v;
    double x,total
    for(int i=0;i<g->getVertexes();++i){
        total=0;
        g->goTo(i);
        u=g->curVertex();
        for(int j=0;j<g->getVertexes();++j){
            g->goTo(j);
            v=g->curVertex();
            x=g->adyacent(u,v);
            if(x!=INFINITE)
                total+=x;
        }
        dist_sum[i]=total;
    }
}

void mostrarMinimo(vector<double> dist_sum,graph *g){ // tam es g.getVertexes()
    Vertex u;
    double min=INFINITE;
    int pos;
    for(int i=0;i<g->getVertexes();++i){
        if(min>dist_sum[i]){
            min=dist_sum[i];
            pos=i;
        }
    }
    g->goTo(pos);
    u=g->curVertex();
    cout<<"el v con la mnor suma d distancias es "<< u.getData() << endl;
}
*/
