#include <iostream>
#include <unistd.h>
#include <cstdio>
#include <fstream>
#include <string>
#include "donante.hpp"
#include "boundedminheap.hpp"
#define cls() system("clear");

/**
* @brief Cabecera que se mostrará durante la ejecución del programa.
*/
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

/**
* @brief Mensaje que se muestra al final de cada opción del menú.
*/
void volver(){
    std::cout << std::endl << "Presiona ENTER para volver al menú.";
    std::cin.ignore();
    std::cin.ignore();
}
/**
* @brief Muestra un error personalizado por pantalla.
* @note Con 2 segundos de sleep da tiempo a leer los errores.
* @param er Error a mostrar.
*/
void error(const std::string &er){
    std::cout << std::endl << "\e[31;1m[ERROR]\e[0m - " << er;
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
* @brief Carga los donantes pasándole lista de donantes y nombre del fichero.
* @note La finalidad de esta función es poder pasarle como argumento al programa un archivo con los donantes.
* @param lista_donantes Donantes.
* @param file_name Nombre del fichero.
* @param precarga Si es precarga de donantes o solo carga.
*/
void precargarDonantes(ed::BoundedMinHeap<ed::Donante> &monticulo_donantes, const char *file_name, const bool &precarga = true){
    if(existe(file_name)){
        if(precarga)
            cabecera();
        char linea[256];
        ed::Donante d;
        std::ifstream fichero(file_name);
        monticulo_donantes = *(new ed::BoundedMinHeap<ed::Donante>());
        while(fichero.getline(linea, 256, ',')){
            d.setNombre(linea);
            fichero.getline(linea, 256, ',');
            d.setApellidos(linea);
            fichero.getline(linea, 256, ',');
            d.setGrupoSanguineo(linea);
            fichero.getline(linea, 256, ',');
            d.setFactorRH(linea);
            fichero.getline(linea, 256);
            d.setDonaciones(atoi(linea));
            monticulo_donantes.insert(d);
        }
        fichero.close();
        if(precarga){
            std::cout << std::endl << "\e[1mDonantes precargados de \e[4mdonantes.txt\e[0m";
            fflush(stdout);
            sleep(3);
        }
    }
}
