#include <string>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <unistd.h>
#include "donante.hpp"
#include "donantes.hpp"
#define cls() system("clear");

void cabecera(){
    cls();
    std::cout << "\e[1;92m###############################" << std::endl;
    std::cout << "###############################" << std::endl;
    std::cout << "####   \e[96mPrograma Donantes\e[92m   ####" << std::endl;
    std::cout << "###############################" << std::endl;
    std::cout << "###############################\e[0m" << std::endl << std::endl;
}

int opciones() /*const*/{
    unsigned int opcion;
    do{
        cabecera();
        std::cout << "Estas son las opciones disponibles:" << std::endl;
        std::cout << "\t\e[33;1m[1]\e[0m - Comprobar si hay donantes." << std::endl;
        std::cout << "\t\e[33;1m[2]\e[0m - Cargar una lista de donantes desde un fichero." << std::endl;
        std::cout << "\t\e[33;1m[3]\e[0m - Grabar una lista de donantes en un fichero." << std::endl;
        std::cout << "\t\e[33;1m[4]\e[0m - Insertar un nuevo donante en la lista." << std::endl;
        std::cout << "\t\e[33;1m[5]\e[0m - Modificar la información de un donante." << std::endl;
        std::cout << "\t\e[33;1m[6]\e[0m - Borrar un donante de la lista." << std::endl;
        std::cout << "\t\e[33;1m[7]\e[0m - Mostrar por pantalla los donantes de sangre." << std::endl;
        std::cout << "\t\e[33;1m[8]\e[0m - Fin del programa." << std::endl;
        std::cout << "Introduce tu opción: \e[33;1m";
        std::cin >> opcion;
        std::cout << "\e[0m" << std::endl;
        if(opcion<1 || opcion>8){
            std::cout << "\e[31;1m[ERROR]\e[0m - Opción no válida. Volviendo al menú...";
            fflush(stdout);
            sleep(3);
        }
    }while(opcion<1 || opcion>8);
    return opcion;
}

void comprobarDonantes(const ed::Donantes<ed::Donante> &lista_donantes){}
void cargarDonantes(const ed::Donantes<ed::Donante> &lista_donantes){}
void guardarDonantes(const ed::Donantes<ed::Donante> &lista_donantes){}
void insertarDonante(const ed::Donantes<ed::Donante> &lista_donantes){}
void modificarDonante(const ed::Donantes<ed::Donante> &lista_donantes){}
void borrarDonante(const ed::Donantes<ed::Donante> &lista_donantes){}
void mostrarDonantes(const ed::Donantes<ed::Donante> &lista_donantes){}
void despedida(){}
