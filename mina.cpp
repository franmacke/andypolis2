//
// Created by ydsas on 3/11/2021.
//

#include "mina.h"
/*
Mina::Mina() : Edificio(MINA) {
    this->cantidadTotal++;
}*/
Mina::Mina(int piedra, int madera, int metal, int cantidadPermitida) {
    this->nombre = "Mina";
    this->cantNecesariPiedra = piedra;
    this->cantNecesariaMadera = madera;
    this->cantNecesariMetal = metal;
    this->cantPermitido = cantidadPermitida;
}

int Mina::cantidadTotal = 0;

/*
int Mina::obtenerTotal() {
    return cantidadTotal;
}*/