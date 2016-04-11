/**
* @file donante.hpp
* @brief <Práctica 2> Primera parte: Representación del TAD donante.
* @author Eduardo Roldán Pijuán
* @date Marzo de 2016
*/

#ifndef __DONANTE_HPP__
#define __DONANTE_HPP__

#include <iostream>
#include <string>
#include <cassert>
#include <cstdlib>
#include "extra.hpp"
#include "donanteinterfaz.hpp"

/**
* @brief Espacio de nombres para la asignatura Estructuras de Datos.
*/

namespace ed{
    /// Clase Donante. Hereda de DonanteInterfaz.
    class Donante:public DonanteInterfaz{
        private:
            /// Nombre del donante.
            std::string _nombre;
            /// Apellidos del donante.
            std::string _apellidos;
            /// Grupo sanguíneo del donante.
            std::string _gSanguineo;
            /// Factor RH del donante.
            std::string _factorRH;
        public:
            /** @name Constructores. */
            /*
            * @brief Constructor con valores por defecto.
            * @param nombre Nombre del donante (string).
            * @param apellidos Apellidos del donante (string).
            * @param gSanguineo Grupo sanguíneo del donante (string).
            * @param factorRH Factor RH del donante (string).
            */
            Donante(const std::string &nombre="", const std::string &apellidos="", const std::string &gSanguineo="", const std::string &factorRH=""): _nombre(nombre), _apellidos(apellidos), _gSanguineo(gSanguineo), _factorRH(factorRH){}
            /*
            * @brief Constructor de copia.
            * @param d Donante del que crear el nuevo donante.
            */
            Donante(const Donante &d): _nombre(d.getNombre()), _apellidos(d.getApellidos()), _gSanguineo(d.getGrupoSanguineo()), _factorRH(d.getFactorRH()){}
            /** @name Observadores. */
            /*
            * @brief Devuelve el nombre del donante.
            * @return Nombre del donante.
            */
            std::string getNombre() const{
                return _nombre;
            }
            /*
            * @brief Devuelve los apellidos del donante.
            * @return Apellidos del donante.
            */
            std::string getApellidos() const{
                return _apellidos;
            }
            /*
            * @brief Devuelve el grupo sanguíneo del donante.
            * @return Grupo sanguíneo del donante.
            */
            std::string getGrupoSanguineo() const{
                return _gSanguineo;
            }
            /*
            * @brief Devuelve el factor RH del donante.
            * @return Factor RH del donante.
            */
            std::string getFactorRH() const{
                return _factorRH;
            }
            /** @name Modificadores. */
            /*
            * @brief Establece el nombre del donante.
            * @param nombre Nombre del donante (string).
            */
            void setNombre(const std::string &nombre){
                _nombre = nombre;
            }
            /*
            * @brief Establece los apellidos del donante.
            * @param apellidos Apellidos del donante (string).
            */
            void setApellidos(const std::string &apellidos){
                _apellidos = apellidos;
            }
            /*
            * @brief Establece el grupos sanguíneo del donante.
            * @param gSanguineo Grupo sanguíneo del donante (string).
            */
            void setGrupoSanguineo(const std::string &gSanguineo){
                _gSanguineo = gSanguineo;
            }
            /*
            * @brief Establece el factor RH del donante.
            * @param factorRH Factor RH del donante (string).
            */
            void setFactorRH(const std::string &factorRH){
                _factorRH = factorRH;
            }
            /** @name Input y Output. */
            /*
            * @brief Lee por teclado los datos del donante.
            * @note La función tiene control de errores por dentro.
            * @sa setNombre()
            * @sa setApellidos()
            * @sa setGrupoSanguineo()
            * @sa setFactorRH()
            */
            void leerDonante(){
                std::string nombre, apellidos, gSanguineo[] = {"0", "A", "B", "AB"}, factorRH[] = {"+", "-"};
                uint opcion1, opcion2;
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
            /*
            * @brief Escribe por pantalla el donante.
            * @note Imprime detalladamente los datos del donante.
            * @sa getNombre()
            * @sa getApellidos()
            * @sa getGrupoSanguineo()
            * @sa getFactorRH()
            */
            void mostrarDonante() const {
                if(this->getNombre() == "" || this->getApellidos() == ""){
                    std::cout << "Donante vacío." << std::endl;
                }
                else{
                    std::cout << "Información del donante:" << std::endl;
                    std::cout << "\t\e[1;4mNombre\e[0m          : " << this->getNombre() << std::endl;
                    std::cout << "\t\e[1;4mApellidos\e[0m       : " << this->getApellidos() << std::endl;
                    std::cout << "\t\e[1;4mGrupo sanguíneo\e[0m : " << this->getGrupoSanguineo() << std::endl;
                    std::cout << "\t\e[1;4mFactor RH\e[0m       : " << this->getFactorRH() << std::endl;
                }
            }
            /** @name Sobrecarga de operadores. */
            /**
            * @brief Sobrecarga del operador =
            * @param d Donante.
            * @return Donante.
            * @sa getNombre()
            * @sa getApellidos()
            * @sa getGrupoSanguineo()
            * @sa getFactorRH()
            * @sa setNombre()
            * @sa setApellidos()
            * @sa setGrupoSanguineo()
            * @sa setFactorRH()
            */
            Donante &operator =(const Donante &d){
                this->setNombre(d.getNombre());
                this->setApellidos(d.getApellidos());
                this->setGrupoSanguineo(d.getGrupoSanguineo());
                this->setFactorRH(d.getFactorRH());
                assert(*this == d);
                return *this;
            }
            /**
            * @brief Sobrecarga del operador ==
            * @param d Donante.
            * @return true si *this == d, false si *this != d
            * @sa getApellidos()
            * @sa getNombre()
            */
            bool operator ==(const Donante &d){
                return toUpper(this->getApellidos()) == toUpper(d.getApellidos()) && toUpper(this->getNombre()) == toUpper(d.getNombre());
            }
            /**
            * @brief Sobrecarga del operador <
            * @param d Donante.
            * @return true si *this < d, false si *this > d
            * @sa getApellidos()
            * @sa getNombre()
            */
            bool operator < (const Donante &d){
                if(toUpper(this->getApellidos()) < toUpper(d.getApellidos())){
                    return true;
                }
                else if(toUpper(this->getApellidos()) > toUpper(d.getApellidos())){
                    return false;
                }
                else{
                    return toUpper(this->getNombre()) < toUpper(d.getNombre());
                }
            }
            /**
            * @brief Sobrecarga del operador >
            * @param d Donante.
            * @return true si *this > d, false si *this < d
            * @sa getApellidos()
            * @sa getNombre()
            */
            bool operator > (const Donante &d){
                if(toUpper(this->getApellidos()) > toUpper(d.getApellidos())){
                    return true;
                }
                else if(toUpper(this->getApellidos()) < toUpper(d.getApellidos())){
                    return false;
                }
                else{
                    return toUpper(this->getNombre()) > toUpper(d.getNombre());
                }
            }
            /**
            * @brief Sobrecarga del operador <=
            * @param d Donante.
            * @return true si *this <= d, false si *this > d
            * @sa getApellidos()
            * @sa getNombre()
            */
            bool operator <=(const Donante &d){
                if(toUpper(this->getApellidos()) < toUpper(d.getApellidos()))
                    return true;
                if(toUpper(this->getApellidos()) > toUpper(d.getApellidos()))
                    return false;
                return toUpper(this->getNombre()) <= toUpper(d.getNombre());
                // return this->getApellidos() <= d.getApellidos() && this->getNombre() <= d.getNombre();
            }
            /**
            * @brief Sobrecarga del operador >>
            * @param input Flujo de entrada.
            * @param d Donante.
            * @return Flujo de entrada con el donante ya leido.
            * @sa setNombre()
            * @sa setApellidos()
            * @sa setGrupoSanguineo()
            * @sa setFactorRH()
            */
            friend std::istream &operator >>(std::istream &input, Donante &d){
                std::string nombre, apellidos, gSanguineo[] = {"0", "A", "B", "AB"}, factorRH[] = {"+", "-"};
                uint opcion1, opcion2;
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
            /**
            * @brief Sobrecarga del operador <<
            * @param output Flujo de salida.
            * @param d Donante.
            * @return Flujo de salido con el polinomio ya impreso.
            * @sa getNombre()
            * @sa getApellidos()
            * @sa getGrupoSanguineo()
            * @sa getFactorRH()
            */
            friend std::ostream &operator <<(std::ostream &output, const Donante &d){
                if(d.getNombre() == "" || d.getApellidos() == ""){
                    output << "Donante vacío." << std::endl;
                    return output;
                }
                output << d.getApellidos() << ", " << d.getNombre() << " ( " << d.getGrupoSanguineo() << d.getFactorRH() << " )" << std::endl;
                return output;
            }
            /**
            * @brief Función para modificar un donante.
            * @note La función tiene un submenú donde pregunta al usuario qué modificar.
            * @sa getNombre()
            * @sa getApellidos()
            * @sa getGrupoSanguineo()
            * @sa getFactorRH()
            * @sa setNombre()
            * @sa setApellidos()
            * @sa setGrupoSanguineo()
            * @sa setFactorRH()
            */
            void modificarDonante(){
                uint opcion_1, opcion_2;
                std::string nombre, apellidos, gSanguineo[] = {"0", "A", "B", "AB"}, factorRH[] = {"+", "-"};
                std::cout << std::endl << "Estos son los atributos del donante:";
                std::cout << std::endl << "\t\e[33;1m[1]\e[0m - Nombre          : " << this->getNombre();
                std::cout << std::endl << "\t\e[33;1m[2]\e[0m - Apellidos       : " << this->getApellidos();
                std::cout << std::endl << "\t\e[33;1m[3]\e[0m - Grupo sanguíneo : " << this->getGrupoSanguineo();
                std::cout << std::endl << "\t\e[33;1m[4]\e[0m - Factor RH       : " << this->getFactorRH();
                do{
                    std::cout << std::endl << "Introduce qué atributo quieres modificar: ";
                    std::cin >> opcion_1;
                    if(opcion_1 < 1 || opcion_1 > 4)
                        std::cout << std::endl << "Error. Debes introducir un número entre 1 y 4." << std::endl;
                }while(opcion_1 < 1 || opcion_1 > 4);
                std::cin.ignore();
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
                        this->setApellidos(apellidos);
                        break;
                    case 3:
                        do{
                            std::cout << "Estos son los grupos sanguíneos posibles:" << std::endl;
                            std::cout << "\t\e[33;1m[1]\e[0m - 0" << std::endl;
                            std::cout << "\t\e[33;1m[2]\e[0m - A" << std::endl;
                            std::cout << "\t\e[33;1m[3]\e[0m - B" << std::endl;
                            std::cout << "\t\e[33;1m[4]\e[0m - AB" << std::endl;
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
                            std::cout << "\t\e[33;1m[1]\e[0m - Positivo" << std::endl;
                            std::cout << "\t\e[33;1m[2]\e[0m - Negativo" << std::endl;
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
