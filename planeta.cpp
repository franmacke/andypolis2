//
// Created by ydsas on 3/11/2021.
//

#include "planeta.h"

Planeta::Planeta() {
    this->cantidadTotal++;
}

int Planeta::cantidadTotal = 0;

int Planeta::obtenerTotal() {
    return cantidadTotal;
}