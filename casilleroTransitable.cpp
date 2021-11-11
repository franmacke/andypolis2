//
// Created by ydsas on 3/11/2021.
//

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

/*
CasilleroTransitable::CasilleroTransitable() {
    this->identificador = "C";
    this->dato = 0;
}



void CasilleroTransitable::cambiar_dato(Objeto * material) {
    this->dato = material;
}*/