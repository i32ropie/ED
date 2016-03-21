#include <iostream>
#include "donante.hpp"
#include "donantes.hpp"

int main() {
    ed::Donantes<ed::Donante> l;
    l.leerDonantes();
    l.mostrarDonantes();
    return 0;
}
