#include "casilleroConstruible.h"

/*
CasilleroConstruible::CasilleroConstruible() {
    this->identificador = "T";
    this->dato = 0;
    //this->edificio =
}
*/
/*
void CasilleroConstruible::cambiar_dato(Objeto * dato) {
    this->dato = dato;
    // this->identificador = dato->id();
}
*/

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