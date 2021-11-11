#include "casilleroConstruible.h"

CasilleroConstruible::~CasilleroConstruible() {
    edificio = NULL;
    delete edificio;
}

void CasilleroConstruible::mostrarEnMapa() {
    if (this->edificio == nullptr){
        cout << "T";
    } else{
        this->edificio->mostrarEnMapa();
    }
}