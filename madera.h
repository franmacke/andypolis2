//
// Created by ydsas on 5/11/2021.
//

#ifndef ANDYPOLIS2_MADERA_H
#define ANDYPOLIS2_MADERA_H
#include "material.h"

class Madera : public Material{
protected:

    static int cantidadTotal;

public:
    Madera(int fila, int columna, int cantidad){this->fila = fila; this->columna = columna;
        this->cantidadTotal += cantidad;}

    Madera(int cantidad){ this->nombre = "Madera";
        this->cantidadTotal = cantidad;}

    void restarTotal(int cantidad){ this->cantidadTotal -= cantidad;}

    void aumentarTotal(int cantidad) {this->cantidadTotal += cantidad;}

    int obtenerTotal(){return cantidadTotal;}

    void mostrarEnMapa(){cout << "W";}

};


#endif //ANDYPOLIS2_MADERA_H
