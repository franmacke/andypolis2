#include <iostream>
#include "archivos.h"


using namespace std;

int main() {
    Archivo datos;
    // Materiales * lista_materiales = datos.leer_materiales();
    // Mapa mapa = datos.leer_mapa();
    // Ciudad * edificios = datos.leer_edificios();
    Coordenada * coordeada = datos.leer_ubicaciones();

    // DESCOMENTAR PARA PROBAR

    // PARA PROBAR SI LEE BIEN LOS MATERIALES
    // for (int i = 0; i < lista_materiales->cantidad_materiales(); i++) {
    //     MaterialInventario nuevo = lista_materiales->obtener(i);
    //     nuevo.mostrar();
    // } 

    // PARA PROBAR SI LEE BIEN LOS EDIFICIOS
    // for (int i = 0; i < edificios->cantidad_edificios(); i++) {
    //     edificios->obtener(i).mostrar();
    // } 

    // PARA PROBAR SI LEE BIEN EL MAPA
    // mapa.mostrar();

    return 0;
}