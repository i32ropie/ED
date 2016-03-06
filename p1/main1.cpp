/**
* @file main1.cpp
* @brief <Práctica 1> Segunda parte: programa de prueba de la clase Monomio
* @author Eduardo Roldán Pijuán
* @date Marzo de 2016
*/

#include <cstdlib>
#include <cstdio>
#include <unistd.h>
#include <iostream>
#include <cassert>
#include "monomio.hpp"
#define cls() system("clear");

/** Pograma principal que muestra el uso de la clase Monomio */
int main(int argc, char const *argv[]) {
    ed::Monomio m1;
    ed::Monomio m2(m1);
    ed::Monomio m3(1,2);
    double x;
    int opcion_1, opcion_2;
    bool salir = false;
    cls();
    std::cout << "-- Primer monomio --\n";
    std::cin >> m1;
    std::cout << "\n-- Segundo monomio --\n";
    std::cin >> m2;
    std::cout << "\n-- Tercer monomio --\n";
    std::cin >> m3;
    while(!salir){
        cls();
        std::cout << "##############\n";
        std::cout << "#### Menú ####\n";
        std::cout << "##############\n";
        std::cout << std::endl;
        std::cout << "1. Valor de un monomio para un dato concreto de X" << std::endl;
        std::cout << "2. Multiplicación de dos monomios y almacenar el resultado en el tercero." << std::endl;
        std::cout << "3. Fin del programa" << std::endl;
        std::cout << std::endl;
        std::cout << "\tIntroduce tu opción: ";
        std::cin >> opcion_1;
        switch (opcion_1) {
            case 1:
                cls();
                std::cout << "Introduce el valor de X: ";
                std::cin >> x;
                std::cout << std::endl << "Estos son tus monomios:";
                std::cout << "\n1. " << m1;
                std::cout << "\n2. " << m2;
                std::cout << "\n3. " << m3;
                std::cout << "\n\n";
                std::cout << "Elige qué polinomio quieres evaluar: ";
                std::cin >> opcion_2;
                switch (opcion_2) {
                    case 1:
                        std::cout << "\nEl resultado es: " << m1.evaluar(x);
                        break;
                    case 2:
                        std::cout << "\nEl resultado es: " << m2.evaluar(x);
                        break;
                    case 3:
                        std::cout << "\nEl resultado es: " << m3.evaluar(x);
                        break;
                    default:
                        std::cout << "\nMonomio no encontrado.";
                }
                std::cout << "\n\nPresiona Enter para volver al menú.";
                getchar();
                getchar();
                // cls();
                break;
            case 2:
                cls();
                std::cout << "Estas son las posibles opciones:\n";
                std::cout << "\n1. m1 = m2 * m3";
                std::cout << "\n2. m2 = m1 * m3";
                std::cout << "\n3. m3 = m1 * m2";
                std::cout << "\n";
                std::cout << "\nIntroduce tu opción: ";
                std::cin >> opcion_2;
                cls();
                if (opcion_2 > 0 && opcion_2 < 4){
                    std::cout << "-- Valor de los monomios antes de la operación --";
                    std::cout << "\nm1 = " << m1;
                    std::cout << "\nm2 = " << m2;
                    std::cout << "\nm3 = " << m3;
                }
                switch (opcion_2) {
                    case 1:
                        m1 = m2 * m3;
                        break;
                    case 2:
                        m2 = m1 * m3;
                        break;
                    case 3:
                        m3 = m1 * m2;
                        break;
                    default:
                        std::cout << "Opción no soportada.";
                }
                if (opcion_2 > 0 && opcion_2 < 4){
                    std::cout << "\n\n-- Valor de los monomios después de la operación --";
                    std::cout << "\nm1 = " << m1;
                    std::cout << "\nm2 = " << m2;
                    std::cout << "\nm3 = " << m3;
                }
                std::cout << "\n\nPresiona Enter para volver al menú.";
                getchar();
                getchar();
                cls();
                break;
            case 3:
                cls();
                std::cout << "Gracias por usar el programa, hasta pronto." << std::endl << std::endl;
                salir = true;
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
