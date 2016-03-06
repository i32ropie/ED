/**
* @file main2.cpp
* @brief <Práctica 1> Cuarta parte: programa de prueba de la clase Polinomio.
* @author Eduardo Roldán Pijuán
* @date Marzo de 2016
*/

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "polinomio.hpp"
#include "monomio.hpp"
#define cls() system("clear");

/** Pograma principal que muestra el uso de la clase Polinomio */
int main(int argc, char const *argv[]) {
    ed::Polinomio p1;
    ed::Polinomio p2(p1);
    ed::Polinomio p3(*new(std::list<ed::Monomio>));
    double x;
    int opcion_1, opcion_2;
    bool salir = false;
    cls();
    std::cout << "-- f(x) --" << std::endl;
    std::cin >> p1;
    std::cout << std::endl << "-- g(x) --" << std::endl;
    std::cin >> p2;
    std::cout << std::endl << "-- t(x) --" << std::endl;
    std::cin >> p3;
    std::cout << std::endl << "Los polinomios han sido guardados con éxito, presiona Enter para ir al menú." << std::endl;
    getchar();
    getchar();
    while(!salir){
        cls();
        std::cout << "##############" << std::endl;
        std::cout << "#### Menú ####" << std::endl;
        std::cout << "##############" << std::endl << std::endl;
        std::cout << "1. Valor de un polinomio para un dato concreto de X." << std::endl;
        std::cout << "2. Suma de dos polinomios y almacenar el resultado en el tercero." << std::endl;
        std::cout << "3. Multiplicación de dos polinomios y almacenar el resultado en el tercero." << std::endl;
        std::cout << "4. Lectura y escritura de un monomio haciendo uso de los los operadores “<<” y ”>>”" << std::endl;
        std::cout << "5. Fin del programa." << std::endl << std::endl;
        std::cout << "\tIntroduce tu opción: ";
        std::cin >> opcion_1;
        switch (opcion_1) {
            case 1:
                cls();
                std::cout << "Introduce el valor de X: ";
                std::cin >> x;
                std::cout << std::endl << "Estos son tus polinomios:";
                std::cout << std::endl << "1. f(x) = " << p1;
                std::cout << std::endl << "2. g(x) = " << p2;
                std::cout << std::endl << "3. t(x) = " << p3 << std::endl;
                std::cout << std::endl << "\tElige  qué polinomio quieres evaluar: ";
                std::cin >> opcion_2;
                switch (opcion_2) {
                    case 1:
                        std::cout << std::endl << "f(" << x << ") = " << p1.evaluar(x);
                        break;
                    case 2:
                        std::cout << std::endl << "g(" << x << ") = " << p2.evaluar(x);
                        break;
                    case 3:
                        std::cout << std::endl << "t(" << x << ") = " << p3.evaluar(x);
                        break;
                    default:
                        std::cout << std::endl << "Polinomio no encontrado.";
                }
                std::cout << std::endl << std::endl << "Presiona Enter para volver al menú.";
                getchar();
                getchar();
                break;
            case 2:
                cls();
                std::cout << "Estas son las posibles opciones:" << std::endl;
                std::cout << std::endl << "1. f(x) = g(x) + t(x)";
                std::cout << std::endl << "2. g(x) = f(x) + t(x)";
                std::cout << std::endl << "3. t(x) = f(x) + g(x)" << std::endl;
                std::cout << std::endl << "\tIntroduce tu opción: ";
                std::cin >> opcion_2;
                cls();
                if (opcion_2 > 0 && opcion_2 < 4){
                    std::cout << "-- Valor de los polinomios antes de la opración --";
                    std::cout << std::endl << "f(x) = " << p1;
                    std::cout << std::endl << "g(x) = " << p2;
                    std::cout << std::endl << "t(x) = " << p3;
                }
                switch (opcion_2) {
                    case 1:
                        p1 = p2 + p3;
                        break;
                    case 2:
                        p2 = p1 + p3;
                        break;
                    case 3:
                        p3 = p1 + p2;
                        break;
                    default:
                        std::cout << std::endl << "Opción no soportada.";
                }
                if (opcion_2 > 0 && opcion_2 < 4) {
                    std::cout << std::endl << std::endl << "-- Valor de los polinomios después de la operación --";
                    std::cout << std::endl << "f(x) = " << p1;
                    std::cout << std::endl << "g(x) = " << p2;
                    std::cout << std::endl << "t(x) = " << p3;
                }
                std::cout << std::endl << std::endl << "Presiona Enter para volver al menú.";
                getchar();
                getchar();
                break;
            case 3:
                cls();
                std::cout << "Estas son las posibles opciones:" << std::endl;
                std::cout << std::endl << "1. f(x) = g(x) * t(x)";
                std::cout << std::endl << "2. g(x) = f(x) * t(x)";
                std::cout << std::endl << "3. t(x) = f(x) * g(x)" << std::endl;
                std::cout << std::endl << "\tIntroduce tu opción: ";
                std::cin >> opcion_2;
                cls();
                if (opcion_2 > 0 && opcion_2 < 4){
                    std::cout << "-- Valor de los polinomios antes de la opración --";
                    std::cout << std::endl << "f(x) = " << p1;
                    std::cout << std::endl << "g(x) = " << p2;
                    std::cout << std::endl << "t(x) = " << p3;
                }
                switch (opcion_2) {
                    case 1:
                        p1 = p2 * p3;
                        break;
                    case 2:
                        p2 = p1 * p3;
                        break;
                    case 3:
                        p3 = p1 * p2;
                        break;
                    default:
                        std::cout << std::endl << "Opción no soportada.";
                }
                if (opcion_2 > 0 && opcion_2 < 4) {
                    std::cout << std::endl << std::endl << "-- Valor de los polinomios después de la operación --";
                    std::cout << std::endl << "f(x) = " << p1;
                    std::cout << std::endl << "g(x) = " << p2;
                    std::cout << std::endl << "t(x) = " << p3;
                }
                std::cout << std::endl << std::endl << "Presiona Enter para volver al menú.";
                getchar();
                getchar();
                break;
            case 4:
                cls();
                std::cout << "Estos son tus polinomios";
                std::cout << std::endl << "1. f(x) = " << p1;
                std::cout << std::endl << "2. g(x) = " << p2;
                std::cout << std::endl << "3. t(x) = " << p3;
                std::cout << std::endl << std::endl << "\tIntroduce qué polinomio quieres sobreescribir: ";
                do{
                    std::cin >> opcion_2;
                    std::cout << std::endl;
                    switch (opcion_2) {
                        case 1:
                            std::cin >> p1;
                            break;
                        case 2:
                            std::cin >> p2;
                            break;
                        case 3:
                            std::cin >> p3;
                            break;
                        default:
                            std::cout << std::endl << "Error. La debes elegir un valor entre 1-3: ";
                    }
                }while(opcion_2<1 || opcion_2 > 3);
                std::cout << std::endl << std::endl << "-- Valor de los polinomios después de la operación --";
                std::cout << std::endl << "f(x) = " << p1;
                std::cout << std::endl << "g(x) = " << p2;
                std::cout << std::endl << "t(x) = " << p3;
                std::cout << std::endl << "Presiona Enter para volver al menú.";
                getchar();
                getchar();
                break;
            case 5:
                cls();
                std::cout << "Gracias por usar el programa, hasta pronto." << std::endl << std::endl;
                salir = true;
                break;
            default:
                cls();
                std::cout << "Opción no reconocida, presiona Enter para volver al menú.";
                getchar();
                getchar();
        }
    }
    return 0;
}
