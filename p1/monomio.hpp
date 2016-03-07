/**
* @file monomio.hpp
* @brief <Práctica 1> Primera parte: Representación del TAD monomio.
* @author Eduardo Roldán Pijuán
* @date Marzo de 2016
*/

#ifndef __MONOMIO_HPP__
#define __MONOMIO_HPP__

#include <iostream>
#include <cassert>
#include <cmath>
#include "monomiointerfaz.hpp"

/**
* @brief Espacio de nombres para la asignatura Estructuras de Datos.
*/

namespace ed{

    class Monomio:public MonomioInterfaz{
        private:
            int _grado;
            double _coeficiente;
        public:
            /** @name Constructores */
            /**
            * @brief Constructor con valores por defecto.
            * @note El valor por defecto de grado es 0, y el de coeficiente es 1.
            * @param grado Número entero que indica el grado del monomio.
            * @param coeficiente Número real que indica el coeficiente del monomio.
            */
            Monomio(const int &grado=0, const double &coeficiente=1): _grado(grado), _coeficiente(coeficiente){}
            /**
            * @brief Constructor de copia.
            * @param m Monomio con el cuál crear el nuevo monomio.
            */
            Monomio(const Monomio &m): _grado(m.getGrado()), _coeficiente(m.getCoeficiente()){}
            /** @name Observadores. */
            /**
            * @brief Devuelve el grado del monomio.
            * @return Grado del monomio.
            */
            int getGrado() const{
                return _grado;
            }
            /**
            * @brief Devuelve el coeficiente del monomio.
            * @return Coeficiente del monomio.
            */
            double getCoeficiente() const{
                return _coeficiente;
            }
            /** @name Modificadores */
            /**
            * @brief Establece el grado del monomio.
            * @param grado Número entero que indica el grando del monomio.
            * @pre grado >= 0
            * @post this->getGrado() == grando
            * @sa getGrado()
            */
            void setGrado(const int &grado){
                if(grado>=0)
                    _grado = grado;
                else
                    std::cout << std::endl << "Error. El grado del monomio debe ser positivo." << std::endl;
                assert(_grado >= 0);
                assert(this->getGrado() == grado);
            }
            /**
            * @brief Establece el coeficiente del monomio.
            * @param coeficiente Número real que indica el coeficiente del monomio.
            * @post this->getCoeficiente() == coeficiente
            * @sa getCoeficiente()
            */
            void setCoeficiente(const double &coeficiente){
                _coeficiente = coeficiente;
                assert(this->getCoeficiente() == coeficiente);
            }
            /** @name Input y Output */
            /**
            * @brief Lee por teclado el monomio.
            * @note Función auxiliar para la lectura del monomio.
            * @sa setGrado()
            * @sa setCoeficiente()
            */
            void leer(){
                int aux_grado;
                double aux_coeficiente;
                std::cout << "Introduce el coeficiente: ";
                std::cin >> aux_coeficiente;
                do{
                    std::cout << "Introduce el grado: ";
                    std::cin >> aux_grado;
                    if(aux_grado<0)
                        std::cout << std::endl << std::endl << "Error, el grado del polinomio no puede ser negativo." << std::endl;
                }while(aux_grado<0);
                setGrado(aux_grado);
                setCoeficiente(aux_coeficiente);
            }
            /**
            * @brief Escribe por pantalla el monomio.
            * @note Función auxiliar para la escritura del monomio por pantalla.
            * @sa getCoeficiente()
            * @sa getGrado()
            */
            void escribir(){
                switch (int(getCoeficiente())) {
                    case 0:
                        break;
                    case 1:
                        switch (getGrado()) {
                            case 0:
                                std::cout << getCoeficiente();
                                break;
                            case 1:
                                std::cout << "x";
                                break;
                            default:
                                std::cout << "x" << getGrado();
                        }
                    default:
                        switch (getGrado()) {
                            case 0:
                                std::cout << getCoeficiente();
                                break;
                            case 1:
                                std::cout << getCoeficiente() << "x";
                                break;
                            default:
                                std::cout << getCoeficiente() << "x^" << getGrado();
                        }
                }
            }
            /** @name Sobrecarga de operadores */
            /**
            * @brief Sobrecarga del operador =
            * @note Con la sobrecarga de este operador podemos asignar un monomio por igualación.
            * @param m Monomio.
            * @return Monomio.
            * @sa setGrado()
            * @sa setCoeficiente()
            * @sa getGrado()
            * @sa getCoeficiente()
            */
            Monomio &operator =(const Monomio &m){
                this->setGrado(m.getGrado());
                this->setCoeficiente(m.getCoeficiente());
                assert(this->getGrado() == m.getGrado());
                assert(this->getCoeficiente() == m.getCoeficiente());
                return *this;
            }
            /**
            * @brief Sobrecarga del operador *
            * @note Con la sobrecarga de este operador podemos multiplicar dos monomios con el operador de producto.
            * @param m Monomio.
            * @return Monomio con el producto del que llama al producto y del llamado.
            * @sa getGrado()
            * @sa getCoeficiente()
            */
            Monomio &operator *(const Monomio &m){
                return *(new Monomio(this->getGrado()+m.getGrado(), this->getCoeficiente()*m.getCoeficiente()));
            }
            /**
            * @brief Sobrecarga del operador >>
            * @note Con la sobrecarga de este operador podemos leer un monomio desde el flujo de entrada.
            * @param input Flujo de entrada.
            * @param m Monomio.
            * @return Flujo de entrada con el monomio ya leido.
            * @sa setGrado()
            * @sa setCoeficiente()
            */
            friend std::istream &operator >>(std::istream &input, Monomio &m){
                int aux_grado;
                double aux_coeficiente;
                std::cout << "Introduce el coeficiente: ";
                input >> aux_coeficiente;
                std::cout << "Introduce el grado: ";
                input >> aux_grado;
                m.setGrado(aux_grado);
                m.setCoeficiente(aux_coeficiente);
                return input;
            }
            /**
            * @brief Sobrecarga del operador <<
            * @note Con la sobrecarga de este operador podemos mostrar un monomio por el flujo de salida.
            * @param output Flujo de salida.
            * @param m Monomio.
            * @return Flujo de salida con el polinomio ya impreso.
            * @sa getGrado()
            * @sa getCoeficiente()
            */
            friend std::ostream &operator <<(std::ostream &output, const Monomio &m){
                if(m.getCoeficiente() != 0){
                    if(m.getCoeficiente() == 1){
                        if(m.getGrado() == 0)
                            output << m.getCoeficiente();
                        else if(m.getGrado() == 1)
                            output << "x";
                        else
                            output << "x^" << m.getGrado();
                    }
                    else{
                        if(m.getGrado() == 0)
                            output << m.getCoeficiente();
                        else if(m.getGrado() == 1)
                            output << m.getCoeficiente() << "x";
                        else
                            output << m.getCoeficiente() << "x^" << m.getGrado();
                    }
                }
                return output;
            }
            /**
            * @brief Sobrecarga del operador +
            * @note Con la sobrecarga de este operador podemos sumar dos monomios.
            * @param m Monomio.
            * @return Monomio con la suma del que llama a la suma y del llamado.
            * @pre El grado de los monomios a sumar debe ser el mismo, ya que si no la suma sería un polinomio y no un monomio.
            * @sa getGrado()
            * @sa getCoeficiente()
            */
            Monomio &operator +(const Monomio &m){
                assert(this->getGrado() == m.getGrado());
                return *(new Monomio(this->getGrado(), this->getCoeficiente()+m.getCoeficiente()));
            }
            /**
            * @brief Sobrecarga del operador <
            * @note Con la sobrecarga de este operador podemos usar la función sort() en la lista de monomios de la clase Polinomio.
            * @param m1 Monomio.
            * @param m2 Monomio.
            * @return true si el grado de m1 es mayor que el de m2 y false si ocurre al contrario.
            * @sa getGrado()
            */
            bool operator <(const Monomio &m){
                return this->getGrado() > m.getGrado();
            }
            /** @name Extra */
            /**
            * @brief Evaluar el monomio en un valor x.
            * @param x Número real para el cuál evaluaremos el monomio.
            * @return Número real con el valor del monomio evaluado en x.
            * @sa getGrado()
            * @sa getCoeficiente()
            */
            double evaluar(const double &x){
                return getCoeficiente()*pow(x, getGrado());
            }
    };

}



#endif
