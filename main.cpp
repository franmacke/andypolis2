#include <iostream>
#include "archivos.h"


using namespace std;

int main() {
    Archivo datos;
    Materiales * lista_materiales = datos.leer_materiales();
    Mapa mapa = datos.leer_mapa();

    // for (int i = 0; i < lista_materiales->cantidad_materiales(); i++) {
    //     MaterialInventario nuevo = lista_materiales->obtener(i);
    //     nuevo.mostrar();
    // } 

    mapa.mostrar();

    return 0;
}