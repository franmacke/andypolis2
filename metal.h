//
// Created by ydsas on 5/11/2021.
//

#ifndef ANDYPOLIS2_METAL_H
#define ANDYPOLIS2_METAL_H
#include "material.h"

const string METAL = "metal";


class Metal : public Material {

protected:

    static int cantidadTotal;
    int cantidad;

public:
    Metal() {};
    Metal(int fila, int columna, int cantidad){this->nombre = METAL; this->fila = fila; this->columna = columna;
        this->cantidad = cantidad;}

    Metal(int cantidad){ this->nombre = METAL;
        this->cantidadTotal += cantidad;}

    void restarTotal(int cantidad){ this->cantidadTotal -= cantidad;}
    void aumentarTotal(int cantidad) {this->cantidadTotal += cantidad;}

    //virtual void sumarCantidad(int cantidad){ this->cantidadTotal += cantidad;}

    int obtenerTotal(){return cantidadTotal;}

    void mostrarEnMapa(){cout << COLOR_BLANCO << EMOJI_METAL;}

    ~Metal() {};
};


#endif //ANDYPOLIS2_METAL_H
