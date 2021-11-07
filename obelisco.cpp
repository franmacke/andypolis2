//
// Created by ydsas on 3/11/2021.
//

#include "obelisco.h"

/*
Obelisco::Obelisco() : Edificio(OBELISCO) {
    this->cantidadTotal++;
}*/

Obelisco::Obelisco(int piedra, int madera, int metal, int cantidadPermitida) {
    this->nombre = "AObelisco";
    this->cantNecesariPiedra = piedra;
    this->cantNecesariaMadera = madera;
    this->cantNecesariMetal = metal;
    this->cantPermitido = cantidadPermitida;
}

int Obelisco::cantidadTotal = 0;

int Obelisco::obtenerTotal() {
    return cantidadTotal;
}