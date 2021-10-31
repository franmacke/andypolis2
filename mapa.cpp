#include "mapa.h"

Mapa::Mapa(Dimension dimensiones) {
    this->dimension_mapa.setear_alto(dimensiones.obtener_alto());
    this->dimension_mapa.setear_ancho(dimensiones.obtener_ancho());
}

Dimension Mapa::dimensiones() {
    return dimension_mapa;
}

void Mapa::cargar_casillero(Casillero dato, Coordenada coordenada) {
    casilleros[coordenada.x()][coordenada.y()] = dato;
}

void Mapa::mostrar() {
    for (int i = 0; i < dimension_mapa.obtener_alto(); i++ ) {
        for (int j = 0; j < dimension_mapa.obtener_ancho(); j++) {
            cout << casilleros[i][j].id() << " ";
        }
        cout << endl;
    }
}


