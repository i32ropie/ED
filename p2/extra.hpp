/**
* @file extra.hpp
* @brief <Práctica 2> Primera parte: Función extra para pasar un string a mayúsculas.
* @author Eduardo Roldán Pijuán
* @date Marzo de 2016
*/

#ifndef __EXTRA_HPP__
#define __EXTRA_HPP__

#include<string>
#include<algorithm>

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

#endif
