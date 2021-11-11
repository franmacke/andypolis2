#include "casilleroTransitable.h"

CasilleroTransitable::~CasilleroTransitable() {
    delete material;
}

void CasilleroTransitable::mostrarEnMapa() {
    if (this->material == nullptr){
        cout << COLOR_BLANCO << EMOJI_CALLE;
    } else{
        this->material->mostrarEnMapa();
    }
}
