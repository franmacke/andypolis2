#include "casillero.h"


Casillero::Casillero() {
    
}

Casillero::Casillero(string idenficador) {
    this->identificador = idenficador;
}

string Casillero::id() {
    return identificador;
}
