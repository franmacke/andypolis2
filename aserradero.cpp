#include "aserradero.h"

Aserradero::Aserradero(int piedra, int madera, int metal, int cantidadPermitida) {
    this->nombre = ASERRADERO;
    this->cantNecesariPiedra = piedra;
    this->cantNecesariaMadera = madera;
    this->cantNecesariMetal = metal;
    this->cantPermitido = cantidadPermitida;
}

int Aserradero::cantidadTotal = 0;