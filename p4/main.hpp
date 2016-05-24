#ifndef __MAIN_HPP__
#define __MAIN_HPP__

#include <fstream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <unistd.h>
#include <iostream>
#include "graph.hpp"
#include "algorithms.hpp"
// #include "extra.hpp"
#include "edge.hpp"
#include "vertex.hpp"
#define cls() system("clear");


/**
* @brief Cabecera que se mostrará durante la ejecución del programa.
*/
void cabecera(){
    cls();
    std::cout << "\e[1;92m###############################" << std::endl;
    std::cout << "###############################" << std::endl;
    std::cout << "####                       ####" << std::endl;
    std::cout << "####       \e[96mPrograma\e[92m        ####" << std::endl;
    std::cout << "####                       ####" << std::endl;
    std::cout << "###############################" << std::endl;
    std::cout << "###############################\e[0m" << std::endl << std::endl;
}
/**
* @brief Mensaje que se muestra al final de cada opción del menú.
*/
void volver(const int &count = 2, const std::string &mensaje="Presiona ENTER para volver al menú."){
    std::cout << std::endl << mensaje;
    for( int i = 0 ; i < count ; ++i)
        std::cin.ignore();
}
/**
* @brief Muestra un error personalizado por pantalla.
* @note Con 2 segundos de sleep da tiempo a leer los errores.
* @param er Error a mostrar.
*/
void error(const std::string &er){
    std::cout << std::endl << "\e[31;1m[ERROR]\e[0m - " << er << std::endl;
    fflush(stdout);
    sleep(2);
}
/**
* @brief Comprueba si existe un fichero.
* @param fichero Nombre del fichero a comprobar si existe.
* @return true si el fichero existe, false si no.
*/
bool existe(const char *fichero){
    return (access( fichero, F_OK) != -1);
}
/**
* @brief Muestra las opciones del menú e interactua con el usuario.
* @return Opción del menú a ejecutar.
* @sa error()
*/
uint opciones(){
    int opcion;
    do{
        cabecera();
        std::cout << "Estas son las opciones disponibles:" << std::endl;
        std::cout << "\t\e[33;1m[1]\e[0m - Cargar un grafo desde un fichero." << std::endl;
        std::cout << "\t\e[33;1m[2]\e[0m - Mostrar el grafo por pantalla." << std::endl;
        std::cout << "\t\e[33;1m[3]\e[0m - Aplicar algoritmo de Floyd + EXTRA." << std::endl;
        std::cout << "\t\e[33;1m[0]\e[0m - Salir del programa." << std::endl;
        std::cout << "Introduce tu opción: \e[33;1m";
        std::cin >> opcion;
        std::cout << "\e[0m";
        if(opcion<0 || opcion>3){
            error("Opción no válida. Volviendo al menú principal...");
        }
    }while(opcion<0 || opcion>3);
    return opcion;
}

uint opciones2(){
    int opcion;
    do{
        cabecera();
        std::cout << "Estas son las opciones disponibles:" << std::endl;
        std::cout << "\t\e[33;1m[1]\e[0m - Mostrar el vértice que tiene la menor suma de distancias a los" << std::endl << "\t      demás vértices y la suma de distancias cuando cada vértice es" << std::endl <<"\t      usado como origen." << std::endl;
        std::cout << "\t\e[33;1m[2]\e[0m - Mostrar la distancia y el camino mínimo entre dos vértices " << std::endl << "\t      indicados." << std::endl;
        std::cout << "Introduce tu opción: \e[33;1m";
        std::cin >> opcion;
        std::cout << "\e[0m";
        if(opcion<1 || opcion>2){
            error("Opción no válida. Volviendo al menú principal...");
        }
    }while(opcion<1 || opcion>2);
    return opcion;
}
/**
* @brief Transforma a mayúsculas una cadena.
* @param strToConvert Cadena a convertir.
* @return strToConvert en mayúsuclas.
*/
std::string toUpper(std::string strToConvert)
{
    std::transform(strToConvert.begin(), strToConvert.end(), strToConvert.begin(), ::toupper);

    return strToConvert;
}


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
    cabecera();
    std::string nombre_fichero;
    std::cout << "Introduce el nombre del fichero: \e[1;4m";
    std::cout << "\e[0m";
    std::cin >> nombre_fichero;
    if(!existe(nombre_fichero.c_str())){
        error("El fichero " + nombre_fichero + " no existe");
        return;
    }
    *g=cargarGrafo1(nombre_fichero);
    std::cout << std::endl << "Grafo actualizado con éxito." << std::endl;
    volver();
}

void mostrarGrafo(ed::Graph *g){
    cabecera();
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
    volver();
}
// Función para sumar todas las distancias
void sumaDist(ed::Graph *g, std::vector<std::vector<double> > &distances, std::vector<int> &sum){
    double total;
    for( int i = 0 ; i < g->getVertexes() ; ++i ){
        total = 0;
        for( int j = 0 ; j < g->getVertexes() ; ++ j)
            total += distances[i][j];
        sum[i] = total;
    }
}

int menorDist(std::vector<int> &sum){
    int min = sum[0], min_pos = 0;
    uint i;
    for( i = 0 ; i < sum.size() ; ++i ){
        if( min > sum[i] ){
            min = sum[i];
            min_pos = i;
        }
    }
    return min_pos;
}

void sumaDist_menorDist(ed::Graph *g, std::vector<std::vector<double> > &distances){
    cabecera();
    ed::Vertex<std::string> v;
    std::vector<int> sum = std::vector<int>(g->getVertexes());
    sumaDist(g, distances, sum);
    g->goTo(menorDist(sum));
    v = g->curVertex();
    std::cout << std::endl << "El vértice que tiene la menor suma de distancias a los demás vértices es " << v.getData() << std::endl;
    std::cout << std::endl << "Suma de distancias cuando cada vértice es usado como origen:" << std::endl << std::endl;
    for( uint i = 0 ; i < sum.size() ; ++i ){
        g->goTo(i);
        v = g->curVertex();
        std::cout << v.getData() << " -> " << sum[i] << std::endl;
    }
    volver();
}

void mostrarMinimo(ed::Graph *g, std::vector<std::vector<double> > &distances, std::vector<std::vector<int> > &mids){
    cabecera();
    std::string origen, destiny;
    std::cin.ignore();
    do{
        std::cout << "Introduce la ciudad de origen: ";
        std::getline(std::cin, origen);
        origen = toUpper(origen);
        if(origen.empty() or !g->searchVertex(origen))
            error("Debes introducir una ciudad válida.");
    }while(origen.empty() or !g->searchVertex(origen));
    do{
        std::cout << "Introduce la ciudad de destino: ";
        std::getline(std::cin, destiny);
        destiny = toUpper(destiny);
        if(origen.empty() or !g->searchVertex(destiny))
            error("Debes introducir una ciudad válida.");
    }while(origen.empty() or !g->searchVertex(destiny));

    ed::Vertex<std::string> u, v;
    g->searchVertex(origen);
    u = g->curVertex();
    g->searchVertex(destiny);
    v = g->curVertex();
    if( distances[u.getLabel()][v.getLabel()] == INFINITE ){
        std::cout << "No existe la distancia mínima" << std::endl;
        return;
    }
    std::cout << std::endl << "La distancia mínima entre <" << u.getData() << "> y <" << v.getData() << "> es: \e[1m" << distances[u.getLabel()][v.getLabel()] << "\e[m" << std::endl;
    std::cout << "El camino mínimo es: " << origen << " ";
    Path(g,u,v,mids);
    std::cout << destiny << std::endl;
    volver(1);
}

void aplicarFloyd(ed::Graph * g){
    cabecera();
    // std::string origen="CORDOBA", destiny="BARCELONA";
    // std::string origen="CORDOBA", destiny="CADIZ";
    uint opcion;
    std::vector<std::vector<double> > distances = std::vector<std::vector<double> >(g->getVertexes(), std::vector<double>(g->getVertexes()));
    std::vector<std::vector<int> > mids = std::vector<std::vector<int> >(g->getVertexes(), std::vector<int>(g->getVertexes()));
    Floyd(g, distances, mids/*, origen, destiny*/);
    volver(1, "Presiona ENTER para pasar entrar submenú");
    cabecera();
    opcion = opciones2();
    switch (opcion) {
        case 1:
            // std::cout << "Subapartado 1" << std::endl;
            sumaDist_menorDist(g, distances);
            break;
        case 2:
            // std::cout << "Subapartado 2" << std::endl;
            mostrarMinimo(g, distances, mids);
            break;
    }
}



/**
* @brief Función para despedirse.
* @note Con el Adiós en grande mejoramos la experiencia del usuario.
* @sa cabecera()
*/
void despedida(){
    cabecera();
    std::cout << "Gracias por usar el programa, ¡hasta la próxima!\e[1m" << std::endl;
    std::cout << "              _ _   __      " << std::endl << "\
     /\\      | (_) /_/      " << std::endl << "\
    /  \\   __| |_  ___  ___ " << std::endl << "\
   / /\\ \\ / _` | |/ _ \\/ __|" << std::endl << "\
  / ____ \\ (_| | | (_) \\__ \\" << std::endl << "\
 /_/    \\_\\__,_|_|\\___/|___/" << std::endl << "\
                            " << std::endl << "\
                            \e[0m" << std::endl;
}


#endif
