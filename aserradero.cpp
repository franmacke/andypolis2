//
// Created by ydsas on 3/11/2021.
//

#include "aserradero.h"
/*
Aserradero::Aserradero() : Edificio(ASERRADERO) {
    this->cantidadTotal++;
}*/
Aserradero::Aserradero(int piedra, int madera, int metal, int cantidadPermitida) {
    this->nombre = "Aserradero";
    this->cantNecesariPiedra = piedra;
    this->cantNecesariaMadera = madera;
    this->cantNecesariMetal = metal;
    this->cantPermitido = cantidadPermitida;
}

int Aserradero::cantidadTotal = 0;