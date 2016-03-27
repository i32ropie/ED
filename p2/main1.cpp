#include <cstdlib>
#include <cstdio>
#include <unistd.h>
#include <iostream>
#include <cassert>
#include <string>
#include "donante.hpp"
// #include "main1.hpp"
#define cls() system("clear");

/** Pograma principal que muestra el uso de la clase Donante */
int main() {
    ed::Donante d1;
    ed::Donante d2(d1);
    ed::Donante d3 = *(new ed::Donante());
    std::string nombre, apellidos, gSanguineo[] = {"0", "A", "B", "AB"}, factorRH[] = {"+", "-"};
    unsigned int opcion_1, opcion_2;
    bool salir = false;
    cls();
    std::cout << "-- Primer donante --" << std::endl;
    std::cin >> d1;
    getchar();
    std::cout << std::endl << "-- Segundo donante --" << std::endl;
    std::cin >> d2;
    getchar();
    std::cout << std::endl << "-- Tercer donante --" << std::endl;
    std::cin >> d3;
    getchar();
    while(!salir){
        cls();
        std::cout << "##############" << std::endl;
        std::cout << "#### Menú ####" << std::endl;
        std::cout << "##############" << std::endl;
        std::cout << std::endl;
        std::cout << "\t1. Leer un donante desde el teclado." << std::endl;
        std::cout << "\t2. Escribir un donante por pantalla." << std::endl;
        std::cout << "\t3. Modificar los datos de un donante." << std::endl;
        std::cout << "\t4. Comparar lexicográficamente dos donantes." << std::endl;
        std::cout << "\t5. Fin del programa" << std::endl;
        std::cout << std::endl;
        std::cout << "Introduce tu opción: ";
        std::cin >> opcion_1;
        switch (opcion_1) {
            case 1:
                cls();
                std::cout << "Estos son tus donantes:";
                std::cout << std::endl << std::endl << "\t1. " << d1;
                std::cout << "\t2. " << d2;
                std::cout << "\t3. " << d3;
                do{
                    std::cout << std::endl << "Introduce qué donante quieres reescribir: ";
                    std::cin >> opcion_2;
                    if(opcion_2 < 1 || opcion_2 > 3)
                        std::cout << std::endl << "Error. Debes introducir un número entre 1 y 3." << std::endl;
                }while(opcion_2 < 1 || opcion_2 > 3);
                std::cout << std::endl;
                getchar();
                switch (opcion_2) {
                    case 1:
                        std::cin >> d1;
                        break;
                    case 2:
                        std::cin >> d2;
                        break;
                    case 3:
                        std::cin >> d3;
                        break;
                    default:
                        fprintf(stderr, "[ERROR]:\n\tExiting... Error at line 61.\n\n[DEBUG_INFO]:\n\topcion_2 = %d", opcion_2);
                        exit(1);
                }
                std::cout << std::endl << "Donante guardado con éxito.";
                std::cout << std::endl << "Presiona Enter para volver al menú.";
                getchar();
                getchar();
                break;
            case 2:
                cls();
                std::cout << "Estos son tus donantes:";
                std::cout << std::endl << "\t1. " << d1;
                std::cout << "\t2. " << d2;
                std::cout << "\t3. " << d3;
                do{
                    std::cout << "Introduce qué donante quieres ver más detalladamente: ";
                    std::cin >> opcion_2;
                    if(opcion_2 < 1 || opcion_2 > 3)
                        std::cout << std::endl << "Error. Debes introducir un número entre 1 y 3." << std::endl;
                }while(opcion_2 < 1 || opcion_2 > 3);
                std::cout << std::endl;
                switch (opcion_2) {
                    case 1:
                        d1.mostrarDonante();
                        break;
                    case 2:
                        d2.mostrarDonante();
                        break;
                    case 3:
                        d3.mostrarDonante();
                        break;
                    default:
                        fprintf(stderr, "[ERROR]:\n\tExiting... Error at line 61.\n\n[DEBUG_INFO]:\n\topcion_2 = %d", opcion_2);
                        exit(1);
                }
                std::cout << std::endl << "Presiona Enter para volver al menú.";
                getchar();
                getchar();
                break;
            case 3:
                cls();
                std::cout << "Estos son tus donantes:";
                std::cout << std::endl << "\t1. " << d1;
                std::cout << std::endl << "\t2. " << d2;
                std::cout << std::endl << "\t3. " << d3;
                do{
                    std::cout << "Introduce qué donante quieres modificar: ";
                    std::cin >> opcion_2;
                    if(opcion_2 < 1 || opcion_2 > 3)
                        std::cout << std::endl << "Error. Debes introducir un número entre 1 y 3." << std::endl;
                }while(opcion_2 < 1 || opcion_2 > 3);
                getchar();
                switch (opcion_2) {
                    case 1:
                        // modificarDonante(d1);
                        d1.modificarDonante();
                        break;
                    case 2:
                        // modificarDonante(d2);
                        d2.modificarDonante();
                        break;
                    case 3:
                        // modificarDonante(d3);
                        d3.modificarDonante();
                        break;
                }
                std::cout << std::endl << "El donante ha sido modificado correctamente.";
                std::cout << std::endl << std::endl << "Presiona Enter para volver al menú.";
                getchar();
                break;
            default:
                cls();
                std::cout << "Opción no reconocida, presiona Enter para volver al menú.";
                getchar();
                getchar();;
        }
    }
    return 0;
}
