#include "objeto.h"

string Objeto::id() {
    return identificador;
}

Objeto::Objeto() {
    this->identificador = "F";
}

void Objeto::setear_id(string id) {
    this->identificador = id;
}

Objeto::Objeto(string identificador) {
    this->identificador = identificador;
}