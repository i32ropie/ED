/**
* @file main1.hpp
* @brief <Práctica 2> Segunda parte: Funciones para el main.
* @author Eduardo Roldán Pijuán
* @date Marzo de 2016
*/

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <unistd.h>
#include "donante.hpp"
#define cls() system("clear");

/**
* @brief Cabecera que se mostrará durante la ejecución del programa.
*/
void cabecera(){
    cls();
    std::cout << "\e[1;92m##############################" << std::endl;
    std::cout << "##############################" << std::endl;
    std::cout << "####                      ####" << std::endl;
    std::cout << "####   \e[96mPrograma Donante\e[92m   ####" << std::endl;
    std::cout << "####                      ####" << std::endl;
    std::cout << "##############################" << std::endl;
    std::cout << "##############################\e[0m" << std::endl << std::endl;
}
/**
* @brief Mensaje que se muestra al final de cada opción del menú.
* @note Algunas veces con 1 solo getchar() es suficiente, por eso puede variar.
* @param nChar Número de veces que se ejecuta getchar()
*/
void volver(const uint &nChar = 2){
    std::cout << std::endl << "Presiona ENTER para volver al menú.";
    for( uint i = 0 ; i < nChar ; ++i )
        getchar();
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
* @brief Muestra las opciones del menú e interactua con el usuario.
* @return Opción del menú a ejecutar.
* @sa error()
*/
uint opciones(){
    uint opcion;
    do{
        cabecera();
        std::cout << "Estas son las opciones disponibles:" << std::endl;
        std::cout << "\t\e[33;1m[1]\e[0m - Leer un donante desde el teclado." << std::endl;
        std::cout << "\t\e[33;1m[2]\e[0m - Escribir un donante por pantalla." << std::endl;
        std::cout << "\t\e[33;1m[3]\e[0m - Modificar los datos de un donante." << std::endl;
        std::cout << "\t\e[33;1m[4]\e[0m - Comparar lexicográficamente dos donantes." << std::endl;
        std::cout << "\t\e[33;1m[5]\e[0m - Fin del programa." << std::endl;
        std::cout << "Introduce tu opción: \e[33;1m";
        std::cin >> opcion;
        std::cout << "\e[0m";
        if(opcion<1 || opcion>5){
            error("Opción no válida. Volviendo al menú principal...");
        }
    }while(opcion<1 || opcion>5);
    return opcion;
}
/**
* @brief Función para leer un donante por teclado.
* @note Se muestran los donantes y se pregunta cuál se quiere escribir.
* @param d1 Donante 1.
* @param d2 Donante 2.
* @param d3 Donante 3.
* @sa cabecera()
* @sa error()
* @sa volver()
*/
void leerDonante(ed::Donante &d1, ed::Donante &d2, ed::Donante &d3){
    uint opcion;
    do{
        cabecera();
        std::cout << "Estos son tus donantes:" << std::endl;
        std::cout << "\t\e[33;1m[1]\e[0m - " << d1;
        std::cout << "\t\e[33;1m[2]\e[0m - " << d2;
        std::cout << "\t\e[33;1m[3]\e[0m - " << d3;
        std::cout << "Introduce qué donante vas a escribir: \e[33;1m";
        std::cin >> opcion;
        std::cout << "\e[0m";
        if(opcion < 1 || opcion > 3){
            error("Opción no válida. Debe ser un número entre 1 y 3.");
        }
    }while(opcion < 1 || opcion > 3);
    std::cout << std::endl;
    getchar();
    switch (opcion) {
        case 1:
            std::cin >> d1;
            break;
        case 2:
            std::cin >> d2;
            break;
        case 3:
            std::cin >> d3;
            break;
    }
    std::cout << std::endl << "Donante guardado con éxito." << std::endl;
    volver();
}
/**
* @brief Función para escribir un donante por pantalla.
* @note Se muestran los donantes y se pregunta cuál se quiere mostrar más detalladamente.
* @param d1 Donante 1.
* @param d2 Donante 2.
* @param d3 Donante 3.
* @sa cabecera()
* @sa error()
* @sa volver()
*/
void escribirDonante(const ed::Donante &d1, const ed::Donante &d2, const ed::Donante &d3){
    uint opcion;
    do{
        cabecera();
        std::cout << "Estos son tus donantes:" << std::endl;
        std::cout << "\t\e[33;1m[1]\e[0m - " << d1;
        std::cout << "\t\e[33;1m[2]\e[0m - " << d2;
        std::cout << "\t\e[33;1m[3]\e[0m - " << d3;
        std::cout << "Introduce qué donante quieres ver más detalladamente: \e[33;1m";
        std::cin >> opcion;
        std::cout << "\e[0m";
        if(opcion < 1 || opcion > 3){
            error("Opción no válida. Debe ser un número entre 1 y 3.");
        }
    }while(opcion < 1 || opcion > 3);
    std::cout << std::endl;
    getchar();
    switch (opcion) {
        case 1:
            d1.mostrarDonante();
            break;
        case 2:
            d2.mostrarDonante();
            break;
        case 3:
            d3.mostrarDonante();
            break;
    }
    volver(1);
}
/**
* @brief Función para modificar un donante.
* @note Se muestran los donantes y se pregunta cuál se quiere modificar.
* @param d1 Donante 1.
* @param d2 Donante 2.
* @param d3 Donante 3.
* @sa cabecera()
* @sa error()
* @sa volver()
*/
void modificarDonante(ed::Donante &d1, ed::Donante &d2, ed::Donante &d3){
    uint opcion;
    do{
        cabecera();
        std::cout << "Estos son tus donantes:" << std::endl;
        std::cout << "\t\e[33;1m[1]\e[0m - " << d1;
        std::cout << "\t\e[33;1m[2]\e[0m - " << d2;
        std::cout << "\t\e[33;1m[3]\e[0m - " << d3;
        std::cout << "Introduce qué donante vas a modificar: \e[33;1m";
        std::cin >> opcion;
        std::cout << "\e[0m";
        if(opcion < 1 || opcion > 3){
            error("Opción no válida. Debe ser un número entre 1 y 3.");
        }
    }while(opcion < 1 || opcion > 3);
    std::cout << std::endl;
    getchar();
    switch (opcion) {
        case 1:
            d1.modificarDonante();
            break;
        case 2:
            d2.modificarDonante();
            break;
        case 3:
            d3.modificarDonante();
            break;
    }
    std::cout << std::endl << "Donante modificado con éxito." << std::endl;
    volver(1);
}
/**
* @brief Función para comparar lexicográficamente dos donantes.
* @note Se muestran los donantes y se pregunta cuáles se quieren comparar.
* @param d1 Donante 1.
* @param d2 Donante 2.
* @param d3 Donante 3.
* @sa cabecera()
* @sa error()
* @sa volver()
*/
void compararDonantes(ed::Donante &d1, ed::Donante &d2, ed::Donante &d3){
    uint opcion_1, opcion_2;
    std::vector<ed::Donante> v = {d1, d2, d3};
    do{
        cabecera();
        std::cout << "Estos son tus donantes:" << std::endl;
        std::cout << "\t\e[33;1m[1]\e[0m - " << d1;
        std::cout << "\t\e[33;1m[2]\e[0m - " << d2;
        std::cout << "\t\e[33;1m[3]\e[0m - " << d3;
        std::cout << "Introduce el primer donante a comparar: \e[33;1m";
        std::cin >> opcion_1;
        std::cout << "\e[0m";
        if(opcion_1 < 1 || opcion_1 > 3){
            error("Opción no válida. Debe ser un número entre 1 y 3.");
        }
    }while(opcion_1 < 1 || opcion_1 > 3);
    do{
        cabecera();
        std::cout << "Estos son tus donantes:" << std::endl;
        std::cout << "\t\e[33;1m[1]\e[0m - " << d1;
        std::cout << "\t\e[33;1m[2]\e[0m - " << d2;
        std::cout << "\t\e[33;1m[3]\e[0m - " << d3;
        std::cout << "Introduce el primer donante a comparar: \e[33;1m" << opcion_1 << "\e[0m" << std::endl;
        std::cout << "Introduce el segundo donante a comparar: \e[33;1m";
        std::cin >> opcion_2;
        std::cout << "\e[0m";
        if(opcion_2 == opcion_1){
            error("Opción no válida. No debes elegir el mismo donante.");
        }
        else if(opcion_2 < 1 || opcion_2 > 3){
            error("Opción no válida. Debe ser un número entre 1 y 3.");
        }
    }while(opcion_2 == opcion_1 || opcion_2 < 1 || opcion_2 > 3);
    if(v[opcion_1-1] == v[opcion_2-1]){
        std::cout << std::endl << "Los dos donantes son iguales." << std::endl;
    }
    else if(v[opcion_1-1] < v[opcion_2-1]){
        std::cout << std::endl << "Donantes ordenados lexicográficamente:" << std::endl;
        std::cout << "\t\e[33;1m[1]\e[0m - " << v[opcion_1-1];
        std::cout << "\t\e[33;1m[2]\e[0m - " << v[opcion_2-1];
    }
    else if(v[opcion_1-1] > v[opcion_2-1]){
        std::cout << std::endl << "Donantes ordenados lexicográficamente:" << std::endl;
        std::cout << "\t\e[33;1m[1]\e[0m - " << v[opcion_2-1];
        std::cout << "\t\e[33;1m[2]\e[0m - " << v[opcion_1-1];
    }
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
