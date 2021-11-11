#include "casilleroTransitable.h"

CasilleroTransitable::~CasilleroTransitable() {
    delete material;
}

void CasilleroTransitable::mostrarEnMapa() {
    if (this->material == nullptr){
        cout << "C";
    } else{
        this->material->mostrarEnMapa();
    }
}
