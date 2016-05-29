/**
* @file main.hpp
* @brief <Práctica 4> Tercera parte: main.
* @author Eduardo Roldán Pijuán
* @date Mayo de 2016
*/

#ifndef __MAIN_HPP__
#define __MAIN_HPP__

#include <fstream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <unistd.h>
#include <iostream>
#include "graph.hpp"
#include "functions.hpp"
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
* @note En la función aplicarFloyd() se llama también para dar paso al submenú.
* @param count Número de veces a ejecutar std::cin.ignore()
* @param mensaje Mensaje a mostar. Por defecto mostrará: "Presiona ENTER para volver al menú."
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
* @sa cabecera()
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
/**
* @brief Muestra las opciones del submenú del apartado 3 e interactua con el usuario.
* @return Opción del submenú a ejecutar.
* @sa cabecera()
* @sa error()
*/
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
/**
* @brief Función que carga un grafo a partir de un archivo.
* @param file_name Nombre del archivo del que cargar el grafo.
* @return Puntero a grafo cargado.
*/
ed::Graph *cargarGrafo1(std::string &file_name){
    ed::Graph *g;
    std::ifstream f(file_name.c_str());
    bool dir;
    int n, d;
    double dist;
    std::string c, c2;
    ed::Vertex<std::string> v1, v2;
    f >> n;                                                                     // Leemos el número de vértices del grafo...
    f >> d;                                                                     // ... y si es dirigido o no.
    if(d)
        dir = true;
    else
        dir = false;
    g = new ed::Graph(n,dir);                                                   // Creamos el grafo con las dimensiones especificadas en el fichero.
    for( int i = 0 ; i < n ; ++i ){                                             // Cargamos los vértices.
        f >> c;
        g->addVertex(c);
    }
    while(f >> c >> c2 >> dist){                                                // Una vez cargados los vértices, cargamos los lados.
        g->searchVertex(c);                                                     // Para ello, movemos el cursor de vértices para obtener ambos vértices...
        v1 = g->curVertex();
        g->searchVertex(c2);
        v2 = g->curVertex();
        g->addEdge(dist, v1, v2);                                               // ... y añadimos el lado pasándole ambos vértices y la distancia entre ambos.
    }
    return g;
}
/**
* @brief Función para cargar un grafo de un fichero.
* @note Esta función actua como interfaz de cargarGrafo1(). Se podría controlar que el grafo se cargara incorrectamente (Por ejemplo indicando un archivo con una sintaxis incorrecta).
* @param g Puntero a puntero de un grafo.
* @return true si el archivo del que se intenta carga existe, false si no.
* @sa cabecera()
* @sa existe()
* @sa error()
* @sa volver()
*/
bool cargarGrafo2(ed::Graph **g){
    cabecera();
    std::string nombre_fichero;
    std::cout << "Introduce el nombre del fichero: \e[1;33m";
    std::cin >> nombre_fichero;
    std::cout << "\e[0m";
    if(!existe(nombre_fichero.c_str())){
        error("El fichero " + nombre_fichero + " no existe");
        return false;
    }
    *g=cargarGrafo1(nombre_fichero);
    std::cout << std::endl << "Grafo actualizado con éxito." << std::endl;
    volver();
    return true;
}
/**
* @brief Función que muestra por pantalla un grafo.
* @param g Puntero a grafo.
* @param cargado Variable que indica si el grafo está cargado o no.
* @sa cabecera()
* @sa error()
* @sa volver()
*/
void mostrarGrafo(ed::Graph *g, const bool &cargado){
    cabecera();
    if(!cargado){
        error("Debes cargar un grafo antes de usar esta opción.");
        return;
    }
    ed::Vertex<std::string> v, u;
    ed::Edge<double> e;
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
            e = g->curEdge();
            std::cout << e.getFirst().getData() << " -> " << e.getSecond().getData() << " : " << e.getData() << std::endl;
            g->nextEdge();
        }
        g->nextVertex();
    }while(!g->afterEndVertex());
    volver();
}
/**
* @brief Función que suma las filas de una matriz y las alamacena en un vector.
* @param vertexes Número de vértices.
* @param distances Matriz de distancias.
* @param sum Vector con la suma de distancias.
*/
void sumaDist(const uint &vertexes, const std::vector<std::vector<double> > &distances, std::vector<int> &sum){
    double total;
    for( uint i = 0 ; i < vertexes ; ++i ){
        total = 0;
        for( uint j = 0 ; j < vertexes ; ++ j)
            total += distances[i][j];
        sum[i] = total;
    }
}
/**
* @brief Función que devuelve la posición del elemento menor en un vector de enteros.
* @param sum Vector de enteros.
* @return min_pos Posición del elemento menor.
*/
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
/**
* @brief Función que imprime una cadena poco a poco.
* @note Su uso principal es que al mostrar la suma de distancias cuando cada vértice es usado como origen sea un poco más legible.
*/
void pprint(const std::string &cad, const uint &speed = 5000){
    for(auto i = cad.begin() ; i != cad.end() ; ++i){
        std::cout << *i;
        usleep(speed);
        fflush(stdout);
    }
}
/**
* @brief Función que muestra el vértice que tiene la menor suma de distancias a los demás vértices y la suma de distancias cuando cada vértice es usado como origen.
* @param g Puntero a grafo.
* @param distances Matriz de distancias.
* @sa cabecera()
* @sa sumaDist()
* @sa menorDist()
* @sa pprint()
* @sa volver()
*/
void sumaDist_menorDist(ed::Graph *g, std::vector<std::vector<double> > &distances){
    cabecera();
    ed::Vertex<std::string> v;
    std::vector<int> sum = std::vector<int>(g->getVertexes());
    sumaDist(g->getVertexes(), distances, sum);
    g->goTo(menorDist(sum));
    v = g->curVertex();
    std::cout << std::endl << "El \e[1mvértice\e[m que tiene la menor suma de distancias a los demás vértices es \e[1;4;92m" << v.getData() << "\e[m" << std::endl;
    volver(2,"Presiona ENTER para continuar.");
    cabecera();
    std::cout << std::endl << "Suma de distancias cuando cada \e[1mvértice\e[m es usado como origen:" << std::endl << std::endl;
    for( uint i = 0 ; i < sum.size() ; ++i ){
        g->goTo(i);
        v = g->curVertex();
        pprint(("\e[1;4;92m" + v.getData() + "\e[m \e[1m->\e[m \e[1;4;33m" + std::to_string(sum[i]) + "\e[m\n"));
    }
    volver(1);
}
/**
* @brief Función que muestra la distancia mínima entre dos ciudades y el camino mínimo entre ambas.
* @param g Puntero a grafo.
* @param distances Matriz de distancias.
* @param mids Matriz de intermedios.
* @sa cabecera()
* @sa error()
* @sa volver()
*/
void mostrarMinimo(ed::Graph *g, std::vector<std::vector<double> > &distances, std::vector<std::vector<int> > &mids){
    cabecera();
    std::string origen, destiny;
    std::cin.ignore();
    do{
        std::cout << "Introduce la ciudad de origen: \e[33;1m";
        std::getline(std::cin, origen);
        std::cout << "\e[0m";
        origen = toUpper(origen);
        if(origen.empty() or !g->searchVertex(origen))
            error("Debes introducir una ciudad válida.");
    }while(origen.empty() or !g->searchVertex(origen));
    do{
        std::cout << "Introduce la ciudad de destino: \e[33;1m";
        std::getline(std::cin, destiny);
        std::cout << "\e[0m";
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
    std::cout << std::endl << "La distancia mínima entre \e[1;4;92m" << u.getData() << "\e[m y \e[1;4;92m" << v.getData() << "\e[m es: \e[1;4;33m" << distances[u.getLabel()][v.getLabel()] << "\e[m" << std::endl << std::endl;
    std::cout << "El camino mínimo es: \e[1;4;92m" << origen << "\e[m \e[1;33m->\e[m ";
    Path(g,u,v,mids);
    std::cout << "\e[1;4;92m" << destiny << "\e[m" << std::endl;
    volver(1);
}
/**
* @brief Función que aplica el algoritmo de Floyd y después muestra un submenú.
* @param g Puntero a grafo.
* @param cargado Variable que indica si el grafo está cargado o no.
* @sa cabecera()
* @sa error()
* @sa opciones2()
* @sa sumaDist_menorDist()
* @sa mostrarMinimo()
* @sa volver()
*/
void aplicarFloyd(ed::Graph * g, const bool &cargado){
    cabecera();
    if(!cargado){
        error("Debes cargar un grafo antes para usar esta opción.");
        return;
    }
    uint opcion;
    std::vector<std::vector<double> > distances = std::vector<std::vector<double> >(g->getVertexes(), std::vector<double>(g->getVertexes()));
    std::vector<std::vector<int> > mids = std::vector<std::vector<int> >(g->getVertexes(), std::vector<int>(g->getVertexes()));
    Floyd(g, distances, mids);
    volver(1, "Presiona ENTER para pasar entrar submenú");
    cabecera();
    opcion = opciones2();
    switch (opcion) {
        case 1:
            sumaDist_menorDist(g, distances);
            break;
        case 2:
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
