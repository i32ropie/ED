/**
* @file main1.cpp
* @brief <Práctica 2> Segunda parte: main1.
* @author Eduardo Roldán Pijuán
* @date Marzo de 2016
*/

#include <cstdlib>
#include <cstdio>
#include <unistd.h>
#include <iostream>
#include <cassert>
#include <string>
#include "donante.hpp"
#include "main1.hpp"

/** @name Main
* Programa principal.
*/

int main() {
    ed::Donante d1;
    ed::Donante d2(d1);
    ed::Donante d3 = *(new ed::Donante());
    uint opcion;                                                                // Declaramos variable para movernos por el menú.
    bool salir = false;                                                         // Declaramos variable que indica cuando salir.
    do{                                                                         // Ejecutamos el menú hasta que se seleccione la opción de salir.
        opcion = opciones();                                                    // Aquí mostramos las opciones y preguntamos qué hacer.
        switch (opcion) {                                                       // Dependiendo de la opción hacemos una cosa u otra.
            case 1:
                leerDonante(d1, d2, d3);
                break;
            case 2:
                escribirDonante(d1, d2, d3);
                break;
            case 3:
                modificarDonante(d1, d2, d3);
                break;
            case 4:
                compararDonantes(d1, d2, d3);
                break;
            case 5:
                despedida();
                salir = true;
                break;
        }
    }while(!salir);
    return 0;
}
