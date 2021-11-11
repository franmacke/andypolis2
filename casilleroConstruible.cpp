#include "casilleroConstruible.h"

CasilleroConstruible::~CasilleroConstruible() {
    edificio = NULL;
    delete edificio;
}

void CasilleroConstruible::mostrarEnMapa() {
    if (this->edificio == nullptr){
        cout << COLOR_VERDE<< EMOJI_TERRENO ;
    } else{
        this->edificio->mostrarEnMapa();
    }
}