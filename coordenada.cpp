#include "coordenada.h"

Coordenada::Coordenada(int x, int y) {
    this->coordenada_x = x;
    this->coordenada_y = y;
}

int Coordenada::x() {
    return coordenada_x;
}

int Coordenada::y() {
    return coordenada_y;
}
