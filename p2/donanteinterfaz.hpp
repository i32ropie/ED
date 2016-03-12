#ifndef __DONANTEINTERFAZ_HPP__
#define __DONANTEINTERFAZ_HPP__

#include <string>

namespace ed{
    class DonanteInterfaz{
        public:
            virtual void setNombre(const std::string &nombre) = 0;
            virtual void setApellidos(const std::string &apellidos) = 0;
            virtual void setGrupoSanguineo(const std::string &gSanguineo) = 0;
            virtual void setFactorRH(const std::string &factorRH) = 0;
            virtual std::string getNombre() const = 0;
            virtual std::string getApellidos() const = 0;
            virtual std::string getGrupoSanguineo() const = 0;
            virtual std::string getFactorRH() const = 0;
    };
}

#endif
