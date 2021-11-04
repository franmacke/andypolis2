#include "casillero.h"

Casillero::Casillero() {
    this->identificador = " ";
}

bool Casillero::vacio() {
    return (obtenerId() == "");
}


Casillero::Casillero(string idenficador) {
    this->identificador = idenficador;
}

string Casillero::obtenerId() {
    if (dato != 0) {
        string datost = dato->id();
        return datost;
    } else {
        return identificador;
    }
}


