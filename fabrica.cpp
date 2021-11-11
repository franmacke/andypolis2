#include "fabrica.h"

Fabrica::Fabrica(int piedra, int madera, int metal, int cantidadPermitida) {
    this->nombre = "fabrica";
    this->cantNecesariPiedra = piedra;
    this->cantNecesariaMadera = madera;
    this->cantNecesariMetal = metal;
    this->cantPermitido = cantidadPermitida;
}

int Fabrica::cantidadTotal = 0;