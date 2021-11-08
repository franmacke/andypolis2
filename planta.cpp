//
// Created by ydsas on 8/11/2021.
//

#include "planta.h"
Planta::Planta(int piedra, int madera, int metal, int cantidadPermitida) {
    this->nombre = "Planta";
    this->cantNecesariPiedra = piedra;
    this->cantNecesariaMadera = madera;
    this->cantNecesariMetal = metal;
    this->cantPermitido = cantidadPermitida;
}

int Planta::cantidadTotal = 0;
