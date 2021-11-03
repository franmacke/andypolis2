//
// Created by ydsas on 3/11/2021.
//

#ifndef ANDYPOLIS2_OBELISCO_H
#define ANDYPOLIS2_OBELISCO_H
#include "edificio.h"


class Obelisco : public Edificio {
protected:
    static int cantidadTotal;

public:
    Obelisco(){cantidadTotal++;}

    // PRE: -
    // POS: devuelve la cantidad total del los escopetas
    static int obtenerTotal(){return cantidadTotal;}

    // PRE: -
    // POS: resta uno a la cantidad total
    void restarTotal(){cantidadTotal--; }

    void mostrarEnMapa(){cout << "O ";}

};


#endif //ANDYPOLIS2_OBELISCO_H
