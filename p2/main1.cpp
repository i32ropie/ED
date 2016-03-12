#include <iostream>
#include "donante.hpp"

int main(int argc, char const *argv[]) {
    ed::Donante d1;
    ed::Donante d2(d1);
    std::cin >> d1;
    std::cout << d1;
    d2 = d1;
    std::cout << d2;
    std::cout << "d1 == d2 -> " << (d1 == d2) << std::endl;
    return 0;
}
