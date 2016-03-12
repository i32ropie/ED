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
                    std::cout << "\t1. 0" << std::endl;
                    std::cout << "\t2. A" << std::endl;
                    std::cout << "\t3. B" << std::endl;
                    std::cout << "\t4. AB" << std::endl;
                    std::cout << "Introduce el número del grupo sanguíneo: ";
                    std::cin >> opcion1;
                    if(opcion1 < 1 || opcion1 > 4)
                        std::cout << "Error. Debes introducir un grupo sanguíneo válido." << std::endl;
                }while(opcion1 < 1 || opcion1 > 4);
                do{
                    std::cout << "Estos son los factores RH posibles:" << std::endl;
                    std::cout << "\t1. Positivo" << std::endl;
                    std::cout << "\t2. Negativo" << std::endl;
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

            void mostrarDonante(){
                // std::cout << "Información del donante:" << std::endl;
                // std::cout << "\tNombre: " << this->getNombre() << std::endl;
                // std::cout << "\tApellidos: " << this->getApellidos() << std::endl;
                // std::cout << "\tGrupo sanguíneo: " << this->getGrupoSanguineo() << this->getFactorRH() << std::endl;
                std::cout << this->getApellidos() << ", " << this->getNombre() << " ( " << this->getGrupoSanguineo() << this->getFactorRH() << " )" << std::endl;
            }

            Donante &operator =(const Donante &d){
                this->setNombre(d.getNombre());
                this->setApellidos(d.getApellidos());
                this->setGrupoSanguineo(d.getGrupoSanguineo());
                this->setFactorRH(d.getFactorRH());
            }
    };
}

#endif
