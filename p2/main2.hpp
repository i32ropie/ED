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
    std::cout << "####                       ####" << std::endl;
    std::cout << "####   \e[96mPrograma Donantes\e[92m   ####" << std::endl;
    std::cout << "####                       ####" << std::endl;
    std::cout << "###############################" << std::endl;
    std::cout << "###############################\e[0m" << std::endl << std::endl;
}

void volver(){
    // cls();
    std::cout << std::endl << "Presiona ENTER para volver al menú.";
    getchar();
    getchar();
}

void error(const std::string er){
    std::cout << "\e[31;1m[ERROR]\e[0m - " << er << ". Volviendo al menú...";
    fflush(stdout);
    sleep(3);
}

bool existe(const std::string &fichero){
    return (access( fichero.c_str(), F_OK) != -1);
}

int opciones(){
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
            error("Opción no válida");
        }
    }while(opcion<1 || opcion>8);
    return opcion;
}

void comprobarDonantes(const ed::Donantes<ed::Donante> &lista_donantes){
    cabecera();
    if(lista_donantes.estaVacia())
        std::cout << "No hay ningún donante insertado." << std::endl;
    else
        std::cout << "Hay " << lista_donantes.getTotal() << " donantes insertados." << std::endl;
    volver();
}

void cargarDonantes(ed::Donantes<ed::Donante> &lista_donantes){
    cabecera();
    ed::Donante d;
    std::string nombre_fichero;
    char linea[256];
    std::cout << "Introduce el nombre del fichero: \e[1;4m";
    std::cin >> nombre_fichero;
    std::cout << "\e[0m";
    if(!existe(nombre_fichero)){
        error("El fichero " + nombre_fichero + " no existe");
        return;
    }
    std::ifstream fichero(nombre_fichero.c_str());
    lista_donantes = *(new ed::Donantes<ed::Donante>());
    while(fichero.getline(linea, 256, ',')){
        d.setNombre(linea);
        fichero.getline(linea, 256, ',');
        d.setApellidos(linea);
        fichero.getline(linea, 256, ',');
        d.setGrupoSanguineo(linea);
        fichero.getline(linea, 256);
        d.setFactorRH(linea);
        lista_donantes.insertarDonante(d);
    }
    std::cout << std::endl << "Donantes actualizados con éxito." << std::endl;
    volver();
}
void guardarDonantes(ed::Donantes<ed::Donante> &lista_donantes){
    cabecera();

}
void insertarDonante(ed::Donantes<ed::Donante> &lista_donantes){}
void modificarDonante(ed::Donantes<ed::Donante> &lista_donantes){}
void borrarDonante(ed::Donantes<ed::Donante> &lista_donantes){}
void mostrarDonantes(ed::Donantes<ed::Donante> &lista_donantes){
    cabecera();
    lista_donantes.mostrarDonantes();
    volver();
}
void despedida(){}
