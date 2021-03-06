//
// Created by ydsas on 3/11/2021.
//

#ifndef ANDYPOLIS2_ESCUELA_H
#define ANDYPOLIS2_ESCUELA_H
#include "edificio.h"

class Escuela : public Edificio{
protected:
    static int cantidadTotal;

public:
    Escuela(){cantidadTotal++;}

    // PRE: -
    // POS: devuelve la cantidad total del los escopetas
    static int obtenerTotal(){return cantidadTotal;}

    // PRE: -
    // POS: resta uno a la cantidad total
    void restarTotal(){cantidadTotal--; }

    void mostrarEnMapa(){cout << "E ";}

};


#endif //ANDYPOLIS2_ESCUELA_H
