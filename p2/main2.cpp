#include <iostream>
#include <cstdio>
#include <string>
#include "donante.hpp"
#include "main2.hpp"
#include "donantes.hpp"
// #define cls() system("clear");

int main() {
    ed::Donantes<ed::Donante> lista_donantes;
    unsigned int opcion_1;
    bool salir = false;
    do{
        cabecera();
        opcion_1 = opciones();
        switch (opcion_1) {
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
