#include <iostream>
#include "archivos.h"
#include "juego.h"


using namespace std;

int main() {
    Archivo datos;
    Juego juego;
    Materiales * lista_materiales = datos.leer_materiales();
    Mapa mapa = datos.leer_mapa();

    datos.procesarArchivoEdificios(mapa);
    // Ciudad * edificios = datos.leer_edificios();

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
    mapa.mostrar();
    // juego.interfazPrincipal(mapa);

    return 0;
}