/**
* @file main.hpp
* @brief <Práctica 3> Tercera parte: main.
* @author Eduardo Roldán Pijuán
* @date Abril de 2016
*/

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
* @brief Carga los donantes pasándole un montículo de donantes y el nombre del fichero.
* @note La finalidad de esta función es poder pasarle como argumento al programa un archivo con los donantes.
* @param monticulo_donantes BoundedMinHeap.
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
            std::cout << std::endl << "\e[1mDonantes precargados de \e[4m" << file_name << "\e[0m";
            fflush(stdout);
            sleep(3);
        }
    }
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
        std::cout << "\t\e[33;1m[1]\e[0m - Comprobar si el montículo está vacío." << std::endl;
        std::cout << "\t\e[33;1m[2]\e[0m - Crear un montículo de donantes de sangre a partir de un fichero." << std::endl;
        std::cout << "\t\e[33;1m[3]\e[0m - Grabar un montículo de donantes de sangre en un fichero." << std::endl;
        std::cout << "\t\e[33;1m[4]\e[0m - Mostrar el donante que se encuentra en la cima del montículo." << std::endl;
        std::cout << "\t\e[33;1m[5]\e[0m - Simular la realización de uno o más donaciones." << std::endl << std::endl;
        std::cout << "\t\e[33;1m[0]\e[0m - Salir del programa." << std::endl;
        std::cout << "Introduce tu opción: \e[33;1m";
        std::cin >> opcion;
        std::cout << "\e[0m";
        if(opcion<0 || opcion>5){
            error("Opción no válida. Volviendo al menú principal...");
        }
    }while(opcion<0 || opcion>5);
    return opcion;
}
/**
* @brief Función para comprobar si hay donantes insertados en el montículo.
* @param monticulo_donantes BoundedMinHeap.
* @sa cabecera()
* @sa volver()
*/
void comprobarDonantes(const ed::BoundedMinHeap<ed::Donante> &monticulo_donantes){
    cabecera();
    if(monticulo_donantes.isEmpty())
        std::cout << "\e[31;1;4mNO\e[m hay ningún donante en el montículo." << std::endl;
    else
        std::cout << "\e[31;1;4mSI\e[m hay donantes en el montículo." << std::endl;
    volver();
}
/**
* @brief Función para cargar los donantes desde un fichero.
* @param monticulo_donantes BoundedMinHeap.
* @sa cabecera()
* @sa error()
* @sa volver()
*/
void cargarDonantes(ed::BoundedMinHeap<ed::Donante> &monticulo_donantes){
    cabecera();
    ed::Donante d;
    std::string nombre_fichero;
    std::cout << "Introduce el nombre del fichero: \e[1;4m";
    std::cin >> nombre_fichero;
    std::cout << "\e[0m";
    if(!existe(nombre_fichero.c_str())){
        error("El fichero " + nombre_fichero + " no existe");
        return;
    }
    precargarDonantes(monticulo_donantes, nombre_fichero.c_str(), false);
    std::cout << std::endl << "Donantes actualizados con éxito." << std::endl;
    volver();
}
/**
* @brief Función para guardar los donantes en un fichero.
* @param monticulo_donantes BoundedMinHeap.
* @sa cabecera()
* @sa error()
* @sa volver()
*/
void guardarDonantes(const ed::BoundedMinHeap<ed::Donante> &monticulo_donantes){
    cabecera();
    if(monticulo_donantes.isEmpty()){
        std::cout << "No hay ningún donante para guardar." << std::endl;
        volver();
        return;
    }
    bool escribir = true;
    uint opcion;
    ed::Donante d;
    std::string nombre_fichero;
    std::cout << "Introduce el nombre del fichero: \e[1;4m";
    std::cin >> nombre_fichero;
    std::cout << "\e[0m";
    if(existe(nombre_fichero.c_str())){
        do{
            cabecera();
            std::cout << "Ya existe un fichero con ese nombre." << std::endl;
            std::cout << "\t\e[33;1m[1]\e[0m - Sobreescribir el fichero." << std::endl;
            std::cout << "\t\e[33;1m[2]\e[0m - Volver al menú." << std::endl;
            std::cout << "Introduce tu opción: \e[33;1m";
            std::cin >> opcion;
            std::cout << "\e[0m";
            if(opcion < 1 || opcion > 2){
                error("Opción no válida.");
            }
        }while(opcion < 1 || opcion > 2);
        switch (opcion) {
            case 1:
                escribir = true;
                break;
            case 2:
                escribir = false;
                break;
        }
    }
    if(escribir){
        std::ofstream fichero(nombre_fichero.c_str());
        ed::BoundedMinHeap<ed::Donante> aux = monticulo_donantes;
        while(!aux.isEmpty()){
            d = aux.top();
            fichero << d.getNombre();
            fichero << ',';
            fichero << d.getApellidos();
            fichero << ',';
            fichero << d.getGrupoSanguineo();
            fichero << ',';
            fichero << d.getFactorRH();
            fichero << ',';
            fichero << d.getDonaciones();
            fichero << std::endl;
            aux.remove();
        }
        fichero.close();
        std::cout << "Donantes guardados en \e[1;4m" << nombre_fichero << "\e[0m." << std::endl;
    }
    volver();
}
/**
* @brief Muestra información del donante que se encuentra en la cima del montículo.
* @param monticulo_donantes BoundedMinHeap.
* @sa cabecera()
* @sa volver()
*/
void mostrarDonanteTop(const ed::BoundedMinHeap<ed::Donante> &monticulo_donantes){
    cabecera();
    if(monticulo_donantes.isEmpty()){
        std::cout << "No hay ningún donante para mostrar." << std::endl;
        volver();
        return;
    }
    monticulo_donantes.top().mostrarDonante();
    volver();
}
/**
* @brief Simula donaciones.
* @note Dentro de la función, se preguntará cuantas donaciones se quieren simular.
* @sa cabecera()
* @sa volver()
*/
void simularDonaciones(ed::BoundedMinHeap<ed::Donante> &monticulo_donantes){
    cabecera();
    int n;
    ed::Donante d;
    std::cout << "Introduce el número de donaciones a simular: ";
    std::cin >> n;
    for( int i = 0 ; i < n ; ++i ){
        d = monticulo_donantes.top();
        d.setDonaciones(d.getDonaciones()+1);
        monticulo_donantes.remove();
        monticulo_donantes.insert(d);
    }
    std::cout << std::endl << "Donaciones simuladas correctamente." << std::endl;
    volver();
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
