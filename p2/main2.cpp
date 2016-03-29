/**
* @file main2.cpp
* @brief <Práctica 2> Cuarta parte: main2.
* @author Eduardo Roldán Pijuán
* @date Marzo de 2016
*/

#include <iostream>
#include <cstdio>
#include <string>
#include "donante.hpp"
#include "main2.hpp"
#include "donantes.hpp"

/** @name Main
* Programa principal.
*/

int main() {
    ed::Donantes lista_donantes;                                                // Declaramos la lista de donantes.
    uint opcion;                                                                // Declaramos variable para movernos por el menú.
    bool salir = false;                                                         // Declaramos variable que indica cuando salir.
    do{                                                                         // Ejecutamos el menú hasta que se seleccione la opción de salir.
        opcion = opciones();                                                    // Aquí mostramos las opciones y preguntamos qué hacer.
        switch (opcion) {                                                       // Dependiendo de la opción hacemos una cosa u otra.
            case 1:
                comprobarDonantes(lista_donantes);
                break;
            case 2:
                cargarDonantes(lista_donantes);
                break;
            case 3:
                guardarDonantes(lista_donantes);
                break;
            case 4:
                insertarDonante(lista_donantes);
                break;
            case 5:
                modificarDonante(lista_donantes);
                break;
            case 6:
                borrarDonante(lista_donantes);
                break;
            case 7:
                mostrarDonantes(lista_donantes);
                break;
            case 8:
                despedida();
                salir = true;
                break;
        }
    }while(!salir);
    return 0;
}
