#include "dimension.h"

Dimension::Dimension() {}

Dimension::Dimension(int alto, int ancho) {
    this->alto = alto;
    this->ancho = ancho;
} 


int Dimension::obtener_alto() {
    return alto;
}

int Dimension::obtener_ancho() {
    return ancho;
}

void Dimension::setear_alto(int nuevo_alto) {
    alto = nuevo_alto;
}

void Dimension::setear_ancho(int nuevo_ancho) {
    ancho = nuevo_ancho;
}

bool Dimension::es_valida() {
    return (alto > 0 && ancho > 0);
}