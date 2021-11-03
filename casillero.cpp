#include "casillero.h"


Casillero::Casillero() {
    this->identificador = "";
}

bool Casillero::vacio() {
    return (obtenerId() == "");
}


Casillero::Casillero(string idenficador) {
    this->identificador = idenficador;
}

string Casillero::obtenerId() {
    return identificador;
}


