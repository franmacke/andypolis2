//
// Created by ydsas on 3/11/2021.
//

#include "casilleroTransitable.h"

CasilleroTransitable::~CasilleroTransitable() {
    material = NULL;
    delete [] material;
}

void CasilleroTransitable::mostrarEnMapa() {
    if (this->material == nullptr){
        cout << "C";
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