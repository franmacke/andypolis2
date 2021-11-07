//
// Created by ydsas on 3/11/2021.
//

#include "fabrica.h"

/*
Fabrica::Fabrica() : Edificio(FABRICA) {
    this->cantidadTotal++;
}*/
Fabrica::Fabrica(int piedra, int madera, int metal, int cantidadPermitida) {
    this->nombre = "Fabrica";
    this->cantNecesariPiedra = piedra;
    this->cantNecesariaMadera = madera;
    this->cantNecesariMetal = metal;
    this->cantPermitido = cantidadPermitida;
}

int Fabrica::cantidadTotal = 0;