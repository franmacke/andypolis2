
#include "escuela.h"

Escuela::Escuela(int piedra, int madera, int metal, int cantidadPermitida) {
    this->nombre = ESCUELA;
    this->cantNecesariPiedra = piedra;
    this->cantNecesariaMadera = madera;
    this->cantNecesariMetal = metal;
    this->cantPermitido = cantidadPermitida;
}

int Escuela::cantidadTotal = 0;