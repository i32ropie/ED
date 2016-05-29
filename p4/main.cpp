/**
* @file main.cpp
* @brief <Práctica 4> Tercera parte: main.
* @author Eduardo Roldán Pijuán
* @date Mayo de 2016
*/

#include "main.hpp"
#include "graph.hpp"

/**
* @name Main
* Programa principal.
*/
int main() {
    ed::Graph *g;
    unsigned int opcion;
    bool salir, cargado = false;
    do{
        opcion = opciones();
        switch (opcion) {
            case 0:
                despedida();
                salir = true;
                break;
            case 1:
                cargado = cargarGrafo2(&g);
                break;
            case 2:
                mostrarGrafo(g, cargado);
                break;
            case 3:
                aplicarFloyd(g, cargado);
                break;
        }
    }while(!salir);
    return 0;
}
