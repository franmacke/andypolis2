//
// Created by ydsas on 3/11/2021.
//

#include "escuela.h"

Escuela::Escuela() : Edificio(ESCUELA) {
    this->cantidadTotal++;
}

int Escuela::cantidadTotal = 0;