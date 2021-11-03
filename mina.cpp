//
// Created by ydsas on 3/11/2021.
//

#include "mina.h"

Mina::Mina() {
    this->cantidadTotal++;
}

int Mina::cantidadTotal = 0;

int Mina::obtenerTotal() {
    return cantidadTotal;
}