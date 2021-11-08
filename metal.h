//
// Created by ydsas on 5/11/2021.
//

#ifndef ANDYPOLIS2_METAL_H
#define ANDYPOLIS2_METAL_H
#include "material.h"


class Metal : public Material {

protected:

    static int cantidadTotal;

public:
    Metal(int fila, int columna, int cantidad){this->fila = fila; this->columna = columna;
        this->cantidadTotal += cantidad;}

    Metal(int cantidad){ this->nombre = "Metal";
        this->cantidadTotal = cantidad;}

    void restarTotal(int cantidad){ this->cantidadTotal -= cantidad;}

    int obtenerTotal(){return cantidadTotal;}

    void mostrarEnMapa(){cout << "I";}

};


#endif //ANDYPOLIS2_METAL_H
