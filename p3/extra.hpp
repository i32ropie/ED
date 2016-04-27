/**
* @file extra.hpp
* @brief <Práctica 2> Primera parte: Función extra para pasar un string a mayúsculas.
* @author Eduardo Roldán Pijuán
* @date Marzo de 2016
*/

#ifndef __EXTRA_HPP__
#define __EXTRA_HPP__

#include <vector>
#include <string>
#include <algorithm>

/**
* @brief Transforma a mayúsculas una cadena.
* @param strToConvert Cadena a convertir.
* @return strToConvert en mayúsuclas.
*/
std::string toUpper(std::string strToConvert)
{
    std::transform(strToConvert.begin(), strToConvert.end(), strToConvert.begin(), ::toupper);

    return strToConvert;
}

/**
* @brief Función que intercambia dos elementos de un vector dados el vector y dos índices.
* @param v Vector.
* @param x Índice del primer elemento.
* @param y Índice del segundo elemento.
* @pre (x >= 0 && x<v.size()) && (y >= 0 && y<v.size())
*/
template <class T> void swap(std::vector<T> &v, const int &x, const int &y){
    T aux = v[x];
    v[x] = v[y];
    v[y] = aux;
}



#endif
