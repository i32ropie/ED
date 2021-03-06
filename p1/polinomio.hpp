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
            * @sa setGrado()
            * @sa setNumeroTerminos()
            */
            Polinomio(){
                setGrado(0);
                setNumeroTerminos(0);
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
            * @brief Devuelve el monomio i-ésimo.
            * @return Monomio i-ésimo.
            */
            Monomio getMonomio(const int &i) const{
                assert(i<=nTerminos);
                bool encontrado=false;
                int aux = 0;
                Monomio aux2;
                for( auto it = _l.begin(); it != _l.end() && !encontrado ; ++it, ++aux){
                    if(aux==i){
                        aux2 = *it;
                        encontrado = true;
                    }
                }
                return aux2;
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
            * @brief Inserta un monomio en el polinomio.
            * @note Se hace uso de la sobrecarga del operador + recibiendo un polinomio.
            * @param m Monomio a insertar.
            */
            void setMonomio(const Monomio &m){
                *this = *this + m;
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
                if(this->estaVacio()){
                    std::cout << std::endl << "Polinomio vacío.";
                    return;
                }
                _l.sort();
                for( int i = 0 ; i < this->getNumeroTerminos() ; ++i ){
                    if( i != 0 && this->getMonomio(i).getCoeficiente() != 0)
                        std::cout << " + ";
                    std::cout << this->getMonomio(i);
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
            Polinomio operator +(const Polinomio &p){
                Polinomio aux = *this;
                for( int i = 0; i < p.getNumeroTerminos() ; ++i){
                    aux = aux + p.getMonomio(i);
                }
                return *(new Polinomio(aux));
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
                Polinomio aux2;
                std::list<Monomio> aux = this->getLista();
                int grado = this->getGrado();
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
                    if(it->getGrado() > grado){
                        grado = it->getGrado();
                    }
                }
                if(!encontrado){
                    aux.push_back(m);
                }
                aux2.setGrado(grado);
                aux2.setNumeroTerminos(aux.size());
                aux2.setLista(aux);
                return *(new Polinomio(aux2));
            }
            /**
            * @brief Sobrecarga del operador *
            * @note Con la sobrecarga de este operador podemos multiplicar dos polinomios con el operador de producto.
            * @param p Polinomio.
            * @return Polinomio con el producto del que llama al producto y del llamado.
            * @sa getLista()
            * @sa setLista()
            */
            Polinomio operator *(const Polinomio &p){
                Polinomio aux;
                for( int i = 0 ; i < this->getNumeroTerminos() ; ++i ){
                    for( int j = 0 ; j < p.getNumeroTerminos() ; ++j ){
                        aux.setMonomio(this->getMonomio(i)*p.getMonomio(j));
                    }
                }
                return aux;
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
            friend std::ostream &operator <<(std::ostream &output, Polinomio &p){
                if(p.estaVacio()){
                    output << "Polinomio vacío.";
                    return output;
                }
                p._l.sort();
                for( int i = 0 ; i < p.getNumeroTerminos() ; ++i ){
                    if( i != 0 )
                        output << " + ";
                    output << p.getMonomio(i);
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
                // for( auto it = _l.begin() ; it != _l.end() ; ++it )
                //     res += it->evaluar(x);
                for( int i = 0 ; i < this->getNumeroTerminos() ; ++i )
                    res += this->getMonomio(i).evaluar(x);
                return res;
            }
    };

}

#endif
