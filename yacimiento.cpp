#include "yacimiento.h"

Yacimiento::Yacimiento(int piedra, int madera, int metal, int cantidadPermitida) {
    this->nombre = "yacimiento";
    this->cantNecesariPiedra = piedra;
    this->cantNecesariaMadera = madera;
    this->cantNecesariMetal = metal;
    this->cantPermitido = cantidadPermitida;
}

int Yacimiento::cantidadTotal = 0;