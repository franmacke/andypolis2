//
// Created by ydsas on 3/11/2021.
//

#include "escuela.h"

/*
Escuela::Escuela() : Edificio(ESCUELA) {
    this->cantidadTotal++;
}*/
Escuela::Escuela(int piedra, int madera, int metal, int cantidadPermitida) {
    this->nombre = "Escuela";
    this->cantNecesariPiedra = piedra;
    this->cantNecesariaMadera = madera;
    this->cantNecesariMetal = metal;
    this->cantPermitido = cantidadPermitida;
}

int Escuela::cantidadTotal = 0;