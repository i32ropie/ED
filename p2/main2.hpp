/**
* @file main2.hpp
* @brief <Práctica 2> Cuarta parte: main2.
* @author Eduardo Roldán Pijuán
* @date Marzo de 2016
*/

#include <string>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <unistd.h>
#include "donante.hpp"
#include "donantes.hpp"
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
void precargarDonantes(ed::Donantes &lista_donantes, const char *file_name, const bool &precarga = true){
    if(existe(file_name)){
        if(precarga)
            cabecera();
        char linea[256];
        ed::Donante d;
        std::ifstream fichero(file_name);
        lista_donantes = *(new ed::Donantes());
        while(fichero.getline(linea, 256, ',')){
            d.setNombre(linea);
            fichero.getline(linea, 256, ',');
            d.setApellidos(linea);
            fichero.getline(linea, 256, ',');
            d.setGrupoSanguineo(linea);
            fichero.getline(linea, 256);
            d.setFactorRH(linea);
            if(lista_donantes.getIndice(d) == -1){
                lista_donantes.insertarDonante(d);
            }
        }
        fichero.close();
        if(precarga){
            std::cout << std::endl << "\e[1mDonantes precargados de \e[4mdonantes.txt\e[0m";
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
    uint opcion;
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
        std::cout << "\e[1m<Opciones extra>\e[0m" << std::endl,
        std::cout << "\t\e[33;1m[9]\e[0m - Borrar todos los donantes." << std::endl;
        std::cout << "\t\e[33;1m[10]\e[0m - Leer múltiples donantes." << std::endl;
        std::cout << "Introduce tu opción: \e[33;1m";
        std::cin >> opcion;
        std::cout << "\e[0m";
        if(opcion<1 || opcion>10){
            error("Opción no válida. Volviendo al menú principal...");
        }
    }while(opcion<1 || opcion>10);
    return opcion;
}
/**
* @brief Función para comprobar si hay donantes insertados.
* @note En el caso de que haya, mostrará cuantos hay.
* @param lista_donantes Donantes.
* @sa cabecera()
* @sa volver()
*/
void comprobarDonantes(const ed::Donantes &lista_donantes){
    cabecera();
    if(lista_donantes.estaVacia())
        std::cout << "No hay ningún donante insertado." << std::endl;
    else
        std::cout << "Hay " << lista_donantes.getTotal() << " donantes insertados." << std::endl;
    volver();
}
/**
* @brief Función para cargar los donantes desde un fichero.
* @param lista_donantes Donantes.
* @sa cabecera()
* @sa error()
* @sa volver()
*/
void cargarDonantes(ed::Donantes &lista_donantes){
    cabecera();
    ed::Donante d;
    std::string nombre_fichero;
    // char linea[256];
    std::cout << "Introduce el nombre del fichero: \e[1;4m";
    std::cin >> nombre_fichero;
    std::cout << "\e[0m";
    if(!existe(nombre_fichero.c_str())){
        error("El fichero " + nombre_fichero + " no existe");
        return;
    }
    precargarDonantes(lista_donantes, nombre_fichero.c_str(), false);
    std::cout << std::endl << "Donantes actualizados con éxito." << std::endl;
    volver();
}
/**
* @brief Función para guardar los donantes en un fichero.
* @param lista_donantes Donantes.
* @sa cabecera()
* @sa error()
* @sa volver()
*/
void guardarDonantes(ed::Donantes &lista_donantes){
    cabecera();
    if(lista_donantes.estaVacia()){
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
        for( uint i = 1 ; i <= lista_donantes.getTotal() ; ++i ){
            d = lista_donantes.getDonante(i);
            fichero << d.getNombre();
            fichero << ',';
            fichero << d.getApellidos();
            fichero << ',';
            fichero << d.getGrupoSanguineo();
            fichero << ',';
            fichero << d.getFactorRH();
            fichero << std::endl;
        }
        fichero.close();
        std::cout << "Donantes guardados en \e[1;4m" << nombre_fichero << "\e[0m." << std::endl;
    }
    volver();
}
/**
* @brief Función para insertar un donante.
* @param lista_donantes Donantes.
* @sa cabecera()
* @sa error()
* @sa volver()
*/
void insertarDonante(ed::Donantes &lista_donantes){
    bool encontrado;
    ed::Donante d;
    do{
        cabecera();
        std::cin.ignore();
        std::cin >> d;
        encontrado = lista_donantes.existeDonante(d);
        if(encontrado)
            error("Ya exisitía un donante con esos datos. Donante no insertado.");
    }while(encontrado);
    lista_donantes.insertarDonante(d);
    std::cout << std::endl << "Donante insertado con éxito.";
    volver();
}
/**
* @brief Función para modificar un donante.
* @param lista_donantes Donantes.
* @sa cabecera()
* @sa volver()
*/
void modificarDonante(ed::Donantes &lista_donantes){
    uint opcion;
    if(!lista_donantes.estaVacia()){
        do{
            cabecera();
            lista_donantes.mostrarDonantes();
            std::cout << "Introduce el donante a modificar: ";
            std::cin >> opcion;
            if(opcion < 1 || opcion > lista_donantes.getTotal())
            error("Debes introducir un número entre 1 y " + std::to_string(lista_donantes.getTotal()));
        }while(opcion < 1 || opcion > lista_donantes.getTotal());
        cabecera();
        lista_donantes.modificarDonante(opcion);
    }
    else{
        cabecera();
        std::cout << "No hay ningún donante para modificar." << std::endl;
    }
    volver();
}
/**
* @brief Función para borrar un donante.
* @param lista_donantes Donantes.
* @sa cabecera()
* @sa error()
* @sa volver()
*/
void borrarDonante(ed::Donantes &lista_donantes){
    uint opcion;
    bool borrado;
    if(!lista_donantes.estaVacia()){
        do{
            cabecera();
            lista_donantes.mostrarDonantes();
            std::cout << "Introduce el donante a eliminar: ";
            std::cin >> opcion;
            if(opcion < 1 || opcion > lista_donantes.getTotal())
            error("Debes introducir un número entre 1 y " + std::to_string(lista_donantes.getTotal()));
        }while(opcion < 1 || opcion > lista_donantes.getTotal());
        borrado = lista_donantes.borrarDonante(lista_donantes.getDonante(opcion));
        if(borrado)
            std::cout << std::endl << "Donante borrado con éxito.";
        else
            error("Linea 201. Mirar importante, aquí no debería entrar nunca el programa.");
    }
    else{
        cabecera();
        std::cout << "No hay ningún donante para borrar." << std::endl;
    }
    volver();
}
/**
* @brief Función para mostrar los donantes.
* @param lista_donantes Donantes.
* @sa cabecera()
* @sa volver()
*/
void mostrarDonantes(ed::Donantes &lista_donantes){
    cabecera();
    lista_donantes.mostrarDonantes();
    volver();
}
void borrarLista(ed::Donantes &lista_donantes){
    cabecera();
    if(lista_donantes.estaVacia()){
        std::cout << "No hay ningún donante para borrar." << std::endl;
    }
    else{
        lista_donantes.limpiarLista();
        std::cout << "Lista de donantes borrada con éxito." << std::endl;
    }
    volver();
}
void insertarMultiplesDonantes(ed::Donantes &lista_donantes){
    cabecera();
    std::cin.ignore();
    lista_donantes.leerDonantes();
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
