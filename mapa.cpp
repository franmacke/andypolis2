#include "mapa.h"

Mapa::Mapa(int fila, int columna) {
    this->fila = fila;
    this->columna = columna;
}

Dato Mapa::obtener(int fila, int columna) {
    return casilleros[fila][columna];
}

void Mapa::cargar_casillero(string casillero, Coordenada coordenada) {
    Parser parser = Parser(casillero);
    casilleros[coordenada.x()][coordenada.y()] = parser.procesar_entrada();
}

void Mapa::mostrar() {
    for (int i = 0; i < this->fila; i++ ) {
        for (int j = 0; j < this->columna; j++) {
            cout << casilleros[i][j]->obtenerId() << " ";
        }
        cout << endl;
    }
}

void Mapa::baja(int fila, int columna) {}

void Mapa::alta(string dato, int fila, int columna) {
    Parser parser = Parser(dato);
    Objeto * objeto = parser.crear_dato();
    casilleros[fila][columna]->cambiar_dato(objeto);
}

bool Mapa::estaVacio(int fila, int columna) {
    return obtener(fila, columna)->vacio(); 
}

