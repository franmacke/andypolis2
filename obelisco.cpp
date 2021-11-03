//
// Created by ydsas on 3/11/2021.
//

#include "obelisco.h"

Obelisco::Obelisco() {
    this->cantidadTotal++;
}

int Obelisco::cantidadTotal = 0;

int Obelisco::obtenerTotal() {
    return cantidadTotal;
}