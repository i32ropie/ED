#ifndef __DONANTE_HPP__
#define __DONANTE_HPP__

#include <iostream>
#include <string>
#include <cassert>
#include <cstdlib>
#include "donanteinterfaz.hpp"
#define cls() system("clear");

namespace ed{
    class Donante:public DonanteInterfaz{
        private:
            std::string _nombre;
            std::string _apellidos;
            std::string _gSanguineo;
            std::string _factorRH;
        public:
            Donante(const std::string &nombre="", const std::string &apellidos="", const std::string &gSanguineo="", const std::string &factorRH=""): _nombre(nombre), _apellidos(apellidos), _gSanguineo(gSanguineo), _factorRH(factorRH){}

            Donante(const Donante &d): _nombre(d.getNombre()), _apellidos(d.getApellidos()), _gSanguineo(d.getGrupoSanguineo()), _factorRH(d.getFactorRH()){}

            std::string getNombre() const{
                return _nombre;
            }

            std::string getApellidos() const{
                return _apellidos;
            }

            std::string getGrupoSanguineo() const{
                return _gSanguineo;
            }

            std::string getFactorRH() const{
                return _factorRH;
            }

            void setNombre(const std::string &nombre){
                _nombre = nombre;
            }

            void setApellidos(const std::string &apellidos){
                _apellidos = apellidos;
            }

            void setGrupoSanguineo(const std::string &gSanguineo){
                _gSanguineo = gSanguineo;
            }

            void setFactorRH(const std::string &factorRH){
                _factorRH = factorRH;
            }

            void leerDonante(){
                std::string nombre, apellidos, gSanguineo[] = {"0", "A", "B", "AB"}, factorRH[] = {"+", "-"};
                unsigned int opcion1, opcion2;
                do{
                    std::cout << "Introduce el nombre: ";
                    std::getline(std::cin, nombre);
                    if(nombre.empty())
                        std::cout << "Error. Debes introducir un nombre." << std::endl;
                }while(nombre.empty());
                do{
                    std::cout << "Introduce los apellidos: ";
                    std::getline(std::cin, apellidos);
                    if(apellidos.empty())
                        std::cout << "Error. Debes introducir unos apellidos." << std::endl;
                }while(apellidos.empty());
                do{
                    std::cout << "Estos son los grupos sanguíneos posibles:" << std::endl;
                    std::cout << "\t\e[33;1m[1]\e[0m - 0" << std::endl;
                    std::cout << "\t\e[33;1m[2]\e[0m - A" << std::endl;
                    std::cout << "\t\e[33;1m[3]\e[0m - B" << std::endl;
                    std::cout << "\t\e[33;1m[4]\e[0m - AB" << std::endl;
                    std::cout << "Introduce el número del grupo sanguíneo: ";
                    std::cin >> opcion1;
                    if(opcion1 < 1 || opcion1 > 4)
                        std::cout << "Error. Debes introducir un grupo sanguíneo válido." << std::endl;
                }while(opcion1 < 1 || opcion1 > 4);
                do{
                    std::cout << "Estos son los factores RH posibles:" << std::endl;
                    std::cout << "\t\e[33;1m[1]\e[0m - Positivo" << std::endl;
                    std::cout << "\t\e[33;1m[2]\e[0m - Negativo" << std::endl;
                    std::cout << "Introduce el número del factor RH: ";
                    std::cin >> opcion2;
                    if(opcion2 < 1 || opcion2 > 2)
                        std::cout << "Error. Debes introducir un factor RH válido." << std::endl;
                }while(opcion2 < 1 || opcion2 > 2);
                this->setNombre(nombre);
                this->setApellidos(apellidos);
                this->setGrupoSanguineo(gSanguineo[opcion1-1]);
                this->setFactorRH(factorRH[opcion2-1]);
            }

            void mostrarDonante() const {
                if(this->getNombre() == "" || this->getApellidos() == ""){
                    std::cout << "Donante vacío." << std::endl;
                }
                else{
                    std::cout << "Información del donante:" << std::endl;
                    std::cout << "\t\e[1;4mNombre\e[0m: " << this->getNombre() << std::endl;
                    std::cout << "\t\e[1;4mApellidos\e[0m: " << this->getApellidos() << std::endl;
                    std::cout << "\t\e[1;4mGrupo sanguíneo\e[0m: " << this->getGrupoSanguineo() << std::endl;
                    std::cout << "\t\e[1;4mFactor RH\e[0m: " << this->getFactorRH() << std::endl;
                }
                // std::cout << this->getApellidos() << ", " << this->getNombre() << " ( " << this->getGrupoSanguineo() << this->getFactorRH() << " )" << std::endl;
            }

            Donante &operator =(const Donante &d){
                this->setNombre(d.getNombre());
                this->setApellidos(d.getApellidos());
                this->setGrupoSanguineo(d.getGrupoSanguineo());
                this->setFactorRH(d.getFactorRH());
                assert(*this == d);
                return *this;
            }

            bool operator ==(const Donante &d){
                return this->getApellidos() == d.getApellidos() && this->getNombre() == d.getNombre();
            }

            bool operator < (const Donante &d){
                if(this->getApellidos() < d.getApellidos()){
                    return true;
                }
                else{
                    return false;
                }
            }

            bool operator > (const Donante &d){
                if(this->getApellidos() > d.getApellidos()){
                    return true;
                }
                else{
                    return false;
                }
            }

            bool operator <=(const Donante &d){
                if(this->getApellidos() < d.getApellidos())
                    return true;
                if(this->getApellidos() > d.getApellidos())
                    return false;
                return this->getNombre() <= d.getNombre();
                // return this->getApellidos() <= d.getApellidos() && this->getNombre() <= d.getNombre();
            }

            friend std::istream &operator >>(std::istream &input, Donante &d){
                std::string nombre, apellidos, gSanguineo[] = {"0", "A", "B", "AB"}, factorRH[] = {"+", "-"};
                unsigned int opcion1, opcion2;
                do{
                    std::cout << "Introduce el nombre: ";
                    std::getline(std::cin, nombre);
                    if(nombre.empty())
                        std::cout << "Error. Debes introducir un nombre." << std::endl;
                }while(nombre.empty());
                do{
                    std::cout << "Introduce los apellidos: ";
                    std::getline(std::cin, apellidos);
                    if(apellidos.empty())
                        std::cout << "Error. Debes introducir unos apellidos." << std::endl;
                }while(apellidos.empty());
                do{
                    std::cout << "Estos son los grupos sanguíneos posibles:" << std::endl;
                    std::cout << "\t\e[33;1m[1]\e[0m - 0" << std::endl;
                    std::cout << "\t\e[33;1m[2]\e[0m - A" << std::endl;
                    std::cout << "\t\e[33;1m[3]\e[0m - B" << std::endl;
                    std::cout << "\t\e[33;1m[4]\e[0m - AB" << std::endl;
                    std::cout << "Introduce el número del grupo sanguíneo: ";
                    std::cin >> opcion1;
                    if(opcion1 < 1 || opcion1 > 4)
                        std::cout << "Error. Debes introducir un grupo sanguíneo válido." << std::endl;
                }while(opcion1 < 1 || opcion1 > 4);
                do{
                    std::cout << "Estos son los factores RH posibles:" << std::endl;
                    std::cout << "\t\e[33;1m[1]\e[0m - Positivo" << std::endl;
                    std::cout << "\t\e[33;1m[2]\e[0m - Negativo" << std::endl;
                    std::cout << "Introduce el número del factor RH: ";
                    std::cin >> opcion2;
                    if(opcion2 < 1 || opcion2 > 2)
                        std::cout << "Error. Debes introducir un factor RH válido." << std::endl;
                }while(opcion2 < 1 || opcion2 > 2);
                d.setNombre(nombre);
                d.setApellidos(apellidos);
                d.setGrupoSanguineo(gSanguineo[opcion1-1]);
                d.setFactorRH(factorRH[opcion2-1]);
                return input;
            }

            friend std::ostream &operator <<(std::ostream &output, const Donante &d){
                if(d.getNombre() == "" || d.getApellidos() == ""){
                    output << "Donante vacío." << std::endl;
                    return output;
                }
                output << d.getApellidos() << ", " << d.getNombre() << " ( " << d.getGrupoSanguineo() << d.getFactorRH() << " )" << std::endl;
                return output;
            }

            void modificarDonante(){
                unsigned int opcion_1, opcion_2;
                std::string nombre, apellidos, gSanguineo[] = {"0", "A", "B", "AB"}, factorRH[] = {"+", "-"};
                std::cout << std::endl << "Estos son los atributos del donante:";
                std::cout << std::endl << "\t\e[33;1m[1]\e[0m - Nombre: " << this->getNombre();
                std::cout << std::endl << "\t\e[33;1m[2]\e[0m - Apellidos: " << this->getApellidos();
                std::cout << std::endl << "\t\e[33;1m[3]\e[0m - Grupo sanguíneo: " << this->getGrupoSanguineo();
                std::cout << std::endl << "\t\e[33;1m[4]\e[0m - Factor RH: " << this->getFactorRH();
                do{
                    std::cout << std::endl << "Introduce qué atributo quieres modificar: ";
                    std::cin >> opcion_1;
                    if(opcion_1 < 1 || opcion_1 > 4)
                        std::cout << std::endl << "Error. Debes introducir un número entre 1 y 4." << std::endl;
                }while(opcion_1 < 1 || opcion_1 > 4);
                getchar();
                switch (opcion_1) {
                    case 1:
                        do{
                            std::cout << "Introduce el nombre: ";
                            std::getline(std::cin, nombre);
                            if(nombre.empty())
                                std::cout << "Error. Debes introducir un nombre." << std::endl;
                        }while(nombre.empty());
                        this->setNombre(nombre);
                        break;
                    case 2:
                        do{
                            std::cout << "Introduce los apellidos: ";
                            std::getline(std::cin, apellidos);
                            if(apellidos.empty())
                                std::cout << "Error. Debes introducir unos apellidos." << std::endl;
                        }while(apellidos.empty());
                        this->setNombre(apellidos);
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
                        this->setGrupoSanguineo(gSanguineo[opcion_2-1]);
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
                        this->setFactorRH(factorRH[opcion_2-1]);
                        break;
                }

            }
    };
}

#endif
