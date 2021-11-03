#include "mapa.h"

Mapa::Mapa(int fila, int columna, string identificador) {
    this->fila = fila;
    this->columna = columna;
}

Casillero Mapa::obtener(int fila, int columna) {
    return casilleros[fila][columna];
}

void Mapa::cargar_casillero(Casillero dato, Coordenada coordenada) {
    casilleros[coordenada.x()][coordenada.y()] = dato;
}

void Mapa::mostrar() {
    for (int i = 0; i < this->fila; i++ ) {
        for (int j = 0; j < this->columna; j++) {
            cout << casilleros[i][j].obtenerId() << " ";
        }
        cout << endl;
    }
}

void Mapa::baja(int fila, int columna) {}

bool Mapa::estaVacio(int fila, int columna) {
    return obtener(fila, columna).vacio(); 
}

