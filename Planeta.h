//
// Created by ydsas on 3/11/2021.
//

#ifndef ANDYPOLIS2_PLANETA_H
#define ANDYPOLIS2_PLANETA_H
#include "CasilleroConstruible.h"


class Planeta : CasilleroConstruible{
protected:
    static int cantidadTotal;

public:
    Planeta(){cantidadTotal++;}

    // PRE: -
    // POS: resta uno a la cantidad total
    void restarTotal(){cantidadTotal--; }

    // PRE: -
    // POS: imprime por pantalla la letra "E"
    void mostrarSimbolo();

    void mostrarEnMapa(){cout << "P "}

};


#endif //ANDYPOLIS2_PLANETA_H
