//
// Created by ydsas on 5/11/2021.
//

#ifndef ANDYPOLIS2_PIEDRA_H
#define ANDYPOLIS2_PIEDRA_H
#include "material.h"


class Piedra : public Material{
protected:

    static int cantidadTotal;

public:
    Piedra(int fila, int columna, int cantidad){this->fila = fila; this->columna = columna;
        this->cantidadTotal += cantidad;}

    Piedra(int cantidad){ this->nombre = "Piedra";
        this->cantidadTotal = cantidad;}

    void restarTotal(int cantidad){ this->cantidadTotal -= cantidad;}
    void aumentarTotal(int cantidad) {this->cantidadTotal += cantidad;}

    int obtenerTotal(){return cantidadTotal;}

    void mostrarEnMapa(){cout << "S";}


};


#endif //ANDYPOLIS2_PIEDRA_H
