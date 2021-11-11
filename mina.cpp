#include "mina.h"

Mina::Mina(int piedra, int madera, int metal, int cantidadPermitida) {
    this->nombre = "mina";
    this->cantNecesariPiedra = piedra;
    this->cantNecesariaMadera = madera;
    this->cantNecesariMetal = metal;
    this->cantPermitido = cantidadPermitida;
}

int Mina::cantidadTotal = 0;
