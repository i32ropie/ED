#include <string>
#include <iostream>
#include "donante.hpp"

void modificarDonante(ed::Donante &d){
    unsigned int opcion_1, opcion_2;
    std::string nombre, apellidos, gSanguineo[] = {"0", "A", "B", "AB"}, factorRH[] = {"+", "-"};
    std::cout << std::endl << "Estos son los atributos del donante:";
    std::cout << std::endl << "\t1. Nombre: " << d.getNombre();
    std::cout << std::endl << "\t2. Apellidos: " << d.getApellidos();
    std::cout << std::endl << "\t3. Grupo sanguíneo: " << d.getGrupoSanguineo();
    std::cout << std::endl << "\t4. Factor RH: " << d.getFactorRH();
    do{
        std::cout << std::endl << "Introduce qué atributo quieres modificar: ";
        std::cin >> opcion_1;
        if(opcion_1 < 1 || opcion_1 > 4)
            std::cout << std::endl << "Error. Debes introducir un número entre 1 y 4." << std::endl;
    }while(opcion_1 < 1 || opcion_1 > 4);
    switch (opcion_1) {
        case 1:
            do{
                std::cout << "Introduce el nombre: ";
                std::getline(std::cin, nombre);
                if(nombre.empty())
                    std::cout << "Error. Debes introducir un nombre." << std::endl;
            }while(nombre.empty());
            d.setNombre(nombre);
            break;
        case 2:
            do{
                std::cout << "Introduce los apellidos: ";
                std::getline(std::cin, apellidos);
                if(apellidos.empty())
                    std::cout << "Error. Debes introducir unos apellidos." << std::endl;
            }while(apellidos.empty());
            d.setNombre(apellidos);
            break;
        case 3:
            do{
                std::cout << "Estos son los grupos sanguíneos posibles:" << std::endl;
                std::cout << "\t1. 0" << std::endl;
                std::cout << "\t2. A" << std::endl;
                std::cout << "\t3. B" << std::endl;
                std::cout << "\t4. AB" << std::endl;
                std::cout << "Introduce el número del nuevo grupo sanguíneo: ";
                std::cin >> opcion_2;
                if(opcion_2 < 1 || opcion_2 > 4)
                    std::cout << "Error. Debes introducir un grupo sanguíneo válido." << std::endl;
            }while(opcion_2 < 1 || opcion_2 > 4);
            d.setGrupoSanguineo(gSanguineo[opcion_2-1]);
            break;
        case 4:
            do{
                std::cout << "Estos son los factores RH posibles:" << std::endl;
                std::cout << "\t1. Positivo" << std::endl;
                std::cout << "\t2. Negativo" << std::endl;
                std::cout << "Introduce el número del factor RH: ";
                std::cin >> opcion_2;
                if(opcion_2 < 1 || opcion_2 > 2)
                    std::cout << "Error. Debes introducir un factor RH válido." << std::endl;
            }while(opcion_2 < 1 || opcion_2 > 2);
            d.setFactorRH(factorRH[opcion_2-1]);
            break;
    }
}
