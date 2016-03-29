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
#define cls() system("clear");

/** Pograma principal que muestra el uso de la clase Donante */
int main() {
    ed::Donante d1;
    ed::Donante d2(d1);
    ed::Donante d3 = *(new ed::Donante());
    unsigned int opcion;
    bool salir = false;
    do{
        opcion = opciones();
        switch (opcion) {
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
