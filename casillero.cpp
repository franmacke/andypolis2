#include "casillero.h"

Casillero::Casillero() {
    this->identificador = " ";
    this->tipoCasillero = " ";
    this->dato = 0;
}

bool Casillero::vacio() {
    return (obtenerId() == "");
}


Casillero::Casillero(string idenficador) {
    this->identificador = idenficador;
    this->tipoCasillero = idenficador;
}

string Casillero::obtenerId() {
    if (dato != 0) {
        string datost = dato->id();
        return datost;
    } else {
        return identificador;
    }
}

string Casillero::obtenerTC() {
    return this->tipoCasillero;
}


