#include "mapa.h"

Mapa::Mapa(int fila, int columna) {
    this->fila = fila;
    this->columna = columna;
}

/*Dimension Mapa::dimensiones() {
    return dimension_mapa;
}*/

void Mapa::cargar_casillero(Casillero dato, Coordenada coordenada) {
    casilleros[coordenada.x()][coordenada.y()] = dato;
}

void Mapa::mostrar() {
    for (int i = 0; i < this->fila; i++ ) {
        for (int j = 0; j < this->columna; j++) {

            cout << casilleros[i][j].id() << " ";
        }
        cout << endl;
    }
}

void Mapa::baja(int fila, int columna) {}


