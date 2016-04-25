#include "main.hpp"
#include "donante.hpp"
#include "boundedminheap.hpp"

int main(int argc, const char *argv[]){
    ed::BoundedMinHeap<ed::Donante> monticulo_donantes;
    uint opcion;
    bool salir = false;
    if(argc == 2)
        precargarDonantes(monticulo_donantes, argv[1]);
    do{
        opcion = opciones();
        switch (opcion) {
            case 0:
                despedida();
                salir = true;
                break;
            case 1:
                comprobarDonantes(monticulo_donantes);
                break;
            case 2:
                cargarDonantes(monticulo_donantes);
                break;
            case 3:
                guardarDonantes(monticulo_donantes);
                break;
            case 4:
                mostrarDonanteTop(monticulo_donantes);
                break;
            case 5:
                simularDonaciones(monticulo_donantes);
                break;
        }
    }while(!salir);
    return 0;
}
