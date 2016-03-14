/**
* @file polinomio.hpp
* @brief <Práctica 1> Tercera parte: Representación del TAD polinomio.
* @author Eduardo Roldán Pijuán.
* @date Marzo de 2016
*/

#ifndef __POLINOMIO_HPP__
#define __POLINOMIO_HPP__

#include <iostream>
#include <list>
#include <cassert>
#include <cstdlib>
#include "monomio.hpp"
#include "polinomiointerfaz.hpp"
#define cls() system("clear");

/**
* @brief Espacio de nombres para la asignatura Estructuras de Datos.
*/

namespace ed{

    class Polinomio:public PolinomioInterfaz{
        private:
            int _grado;
            int _nTerminos;
            std::list<Monomio> _l;
        public:
            /** @name Constructores*/
            /**
            * @brief Constructor con valores por defecto.
            * @note El valor por defecto es una lista de monomios vacía.
            * @param l Lista de monomios.
            * @sa getGrado()
            * @sa setGrado()
            * @sa setNumeroTerminos()
            * @sa setLista()
            */
            Polinomio(const std::list<Monomio> &l = *(new std::list<Monomio>)){
                int grado=0;
                for( auto it = l.cbegin() ; it != l.cend() ; ++it ){
                    if( it->getGrado() > grado)
                        grado = it->getGrado();
                }
                setGrado(grado);
                setNumeroTerminos(l.size());
                setLista(l);
            }
            /**
            * @brief Constructor de copia.
            * @param p Polinomio con el cual crear el nuevo polinomio.
            */
            Polinomio(const Polinomio &p): _grado(p.getGrado()), _nTerminos(p.getNumeroTerminos()), _l(p.getLista()){}
            /** @name Observadores */
            /**
            * @brief Devuelve el grado del polinomio.
            * @return Grado del polinomio.
            */
            int getGrado() const{
                return _grado;
            }
            /**
            * @brief Devuelve el número de términos del polinomio.
            * @return Número de términos del polinomio.
            */
            int getNumeroTerminos() const{
                return _nTerminos;
            }
            /**
            * @brief Devuelve la lista de monomios del polinomio.
            * @return Lista de monomios del polinomio.
            */
            std::list<Monomio> getLista() const{
                return _l;
            }
            /**
            * @brief Devuelve si está vacía o no la lista de monomios.
            * @return true si la lista está vacía o false si no lo está.
            */
            bool estaVacio() const{
                return _l.empty();
            }
            /** @name Modificadores */
            /**
            * @brief Establece el grado del polinomio.
            * @param grado Número entero que indica el grado del polinomio.
            * @pre grado >= 0
            * @post this->getGrado() == grado
            * @sa getGrado()
            */
            void setGrado(const int &grado){
                if(grado>=0)
                    _grado = grado;
                else
                    std::cout << std::endl << "Error. El grado del polinomio debe ser positivo." << std::endl;
                assert(_grado >= 0);
                assert(this->getGrado() == grado);
            }
            /**
            * @brief Establece el número de términos del polinomio.
            * @param nTerminos Número real que indica el número de términos del polinomio.
            * @pre nTerminos > 0
            * @post this->getNumeroTerminos() == nTerminos
            * @sa getNumeroTerminos()
            */
            void setNumeroTerminos(const int &nTerminos){
                if(nTerminos>=0)
                    _nTerminos = nTerminos;
                else
                    std::cout << std::endl << "Error. El número de términos del polinomio debe ser mayor que 0." << std::endl;
                assert(_nTerminos >= 0);
                assert(this->getNumeroTerminos() == nTerminos);
            }
            /**
            * @brief Establece la lista de monomios del polinomio.
            * @param l Lista de monomios del polinomio.
            */
            void setLista(const std::list<Monomio> &l){
                _l = l;
            }
            /** @name Input y Output */
            /**
            * @brief Lee por teclado el polinomio.
            * @note Función auxiliar para la lectura del polinomio.
            * @sa getGrado()
            * @sa setGrado()
            * @sa setNumeroTerminos()
            * @sa setLista()
            */
            void leerPolinomio(){
                int grado=0, nTerminos;
                Monomio aux;
                std::list<Monomio> lista_auxiliar;
                bool found;
                do{
                    std::cout << std::endl << "Introduce el \e[4mnúmero\e[0m de términos del polinomio: ";
                    std::cin >> nTerminos;
                    if(nTerminos<=0){
                        std::cout << std::endl << "Error, el \e[4mnúmero\e[0m de términos no puede ser menor que 0" << std::endl;
                    }
                }while(nTerminos<=0);
                for( int i = 0 ; i < nTerminos ; ++i){
                    std::cout << std::endl << "Leyendo el monomio " << i + 1 << std::endl << std::endl;
                    std::cin >> aux;
                    if(aux.getCoeficiente() == 0) continue;
                    if(aux.getGrado()<=grado){
                        found = false;
                        for( auto it = lista_auxiliar.begin() ; it != lista_auxiliar.end() && !found ; ++it ){
                            if(it->getGrado() == aux.getGrado()){
                                *it = *it + aux;
                                found = true;
                            }
                            if(it->getCoeficiente() == 0){
                                lista_auxiliar.erase(it);
                            }
                        }
                        if(!found){
                            lista_auxiliar.push_back(aux);
                        }
                    }
                    else{
                        grado = aux.getGrado();
                        lista_auxiliar.push_back(aux);
                    }
                }
                this->setGrado(grado);
                this->setNumeroTerminos(lista_auxiliar.size());
                this->setLista(lista_auxiliar);
            }
            /**
            * @brief Escribe por pantalla el polinomio.
            * @note Función auxiliar para la escritura de un polinomio por pantalla.
            * @sa getCoeficiente()
            */
            void mostrarPolinomio(){
                if(estaVacio()){
                    std::cout << std::endl << "Lista vacía";
                    return;
                }
                _l.sort();
                for( auto it = _l.cbegin() ; it != _l.cend() ; ++it ){
                    if( it != _l.begin() && it->getCoeficiente() != 0)
                        std::cout << " + ";
                    std::cout << *it;
                }
            }
            /** @name Sobrecarga de operadores */
            /**
            * @brief Sobrecarga del operador =
            * @note Con la sobrecarga de este operador podemos asignar un polinomio por igualación de un polinomio.
            * @param p Polinomio.
            * @return Polinomio.
            * @sa getGrado()
            * @sa getNumeroTerminos()
            * @sa getLista()
            * @sa setGrado()
            * @sa setNumeroTerminos()
            * @sa setLista()
            */
            Polinomio &operator =(const Polinomio &p){
                this->setGrado(p.getGrado());
                this->setNumeroTerminos(p.getNumeroTerminos());
                this->setLista(p.getLista());
                return *this;
            }
            /**
            * @brief Sobrecarga del operador =
            * @note Con la sobrecarga de este operador podemos asignar un polinomio por igualción de un monomio.
            * @param m Monomio.
            * @return Polinomio.
            * @sa getGrado()
            * @sa setGrado()
            * @sa setNumeroTerminos()
            * @sa setLista()
            */
            Polinomio &operator =(const Monomio &m){
                std::list<Monomio> aux;
                aux.push_back(m);
                this->setGrado(m.getGrado());
                this->setNumeroTerminos(aux.size());
                this->setLista(aux);
                return *this;
            }
            /**
            * @brief Sobrecarga del operador +
            * @note Con la sobrecarga de este operador podemos sumar dos polinomios con operador de suma.
            * @param p Polinomio.
            * @return Polinomio con la suma del que llama a la suma y del llamado.
            * @sa getLista()
            */
            Polinomio &operator +(const Polinomio &p){
                std::list<Monomio> aux1 = p.getLista();
                Polinomio aux2(this->getLista());
                for( auto it = aux1.cbegin() ; it != aux1.cend() ; ++it ){
                    aux2 = aux2 + *it;
                }
                return *(new Polinomio(aux2.getLista()));
            }
            /**
            * @brief Sobrecarga del operador +
            * @note Cont la sobrecarga de este operador podemos sumar un polinomio y un monomio con el operador de suma.
            * @param m Monomio.
            * @return Polinomio con la suma del que llama a la suma y del monomio llamado.
            * @sa getLista()
            * @sa getGrado()
            */
            Polinomio &operator +(const Monomio &m){
                std::list<Monomio> aux = this->getLista();
                bool encontrado;
                encontrado = false;
                for( auto it = aux.begin() ; it != aux.end() && !encontrado ; ++it ){
                    if(it->getGrado() == m.getGrado()){
                        *it = *it + m;
                        encontrado = true;
                    }
                    if(it->getCoeficiente() == 0){
                        aux.erase(it);
                    }
                }
                if(!encontrado){
                    aux.push_back(m);
                }
                return *(new Polinomio(aux));
            }
            /**
            * @brief Sobrecarga del operador *
            * @note Con la sobrecarga de este operador podemos multiplicar dos polinomios con el operador de producto.
            * @param p Polinomio.
            * @return Polinomio con el producto del que llama al producto y del llamado.
            * @sa getLista()
            * @sa setLista()
            */
            Polinomio &operator *(const Polinomio &p){
                std::list<Monomio> aux1 = this->getLista();
                std::list<Monomio> aux2 = p.getLista();
                std::list<Monomio> aux3;
                Polinomio aux4;
                Polinomio aux5;
                for( auto it1 = aux1.begin() ; it1 != aux1.end() ; ++it1 ){
                    aux4.setLista(aux3);
                    for( auto it2 = aux2.begin() ; it2 != aux2.end() ; ++it2 ){
                        aux3.push_back((*it1)*(*it2));
                    }
                    aux4.setLista(aux3);;
                    aux3.clear();
                    aux5 = aux5 + aux4;
                }
                return *(new Polinomio(aux5));
            }
            /**
            * @brief Sobrecarga del operador >>
            * @note Con la sobrecarga de este operador podemos leer un polinomio desde el flujo de entrada.
            * @param input Flujo de entrada.
            * @param p Polinomio.
            * @return Flujo de entrada con el polinomio ya leido.
            * @sa getGrado()
            * @sa setGrado()
            * @sa setNumeroTerminos()
            * @sa setLista()
            */
            friend std::istream &operator >>(std::istream &input, Polinomio &p){
                int grado=0, nTerminos;
                Monomio aux;
                std::list<Monomio> lista_auxiliar;
                bool found;
                do{
                    std::cout << std::endl << "Introduce el \e[4mnúmero\e[0m de términos del polinomio: ";
                    input >> nTerminos;
                    if(nTerminos<0){
                        std::cout << std::endl << "Error, el \e[4mnúmero\e[0m de términos no puede ser menor que 0" << std::endl;
                    }
                }while(nTerminos<0);
                for( int i = 0 ; i < nTerminos ; ++i){
                    std::cout << std::endl << "Leyendo el monomio " << i + 1 << std::endl << std::endl;
                    std::cin >> aux;
                    if(aux.getCoeficiente() == 0) continue;
                    if(aux.getGrado()<=grado){
                        found = false;
                        for( auto it = lista_auxiliar.begin() ; it != lista_auxiliar.end() && !found ; ++it ){
                            if(it->getGrado() == aux.getGrado()){
                                *it = *it + aux;
                                found = true;
                            }
                            if(it->getCoeficiente() == 0){
                                lista_auxiliar.erase(it);
                            }
                        }
                        if(!found){
                            lista_auxiliar.push_back(aux);
                        }
                    }
                    else{
                        grado = aux.getGrado();
                        lista_auxiliar.push_back(aux);
                    }
                }
                p.setGrado(grado);
                p.setNumeroTerminos(lista_auxiliar.size());
                p.setLista(lista_auxiliar);
                return input;
            }
            /**
            * @brief Sobrecarga del operador <<
            * @note Con la sobrecarga de este operador podemos mostrar un polinomio por el flujo de salida.
            * @param output Flujo de salida.
            * @param p Polinomio.
            * @return Flujo de salida con el polinomio ya impreso.
            * @sa getCoeficiente()
            * @sa getLista()
            * @sa setLista()
            */
            friend std::ostream &operator <<(std::ostream &output, const Polinomio &p){
                std::list<Monomio> aux = p.getLista();
                if(p.estaVacio()){
                    output << "Lista vacía";
                    return output;
                }
                aux.sort();
                for( auto it = aux.cbegin() ; it != aux.cend() ; ++it ){
                    if( it != aux.begin() && it->getCoeficiente() != 0)
                        output << " + ";
                    output << *it;
                }
                return output;
            }
            /** @name Extra */
            /**
            * @brief Evaluar el polinomio en un valor x.
            * @param x Número real para el cuál evaluaremos el polinomio.
            * @return Número real con el valor del polinomio evaluado en x.
            * @sa ed::Monomio::evaluar()
            */
            double evaluar(const double &x){
                double res = 0.0;
                for( auto it = _l.begin() ; it != _l.end() ; ++it )
                    res += it->evaluar(x);
                return res;
            }
    };

}

#endif
