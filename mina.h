//
// Created by ydsas on 3/11/2021.
//

#ifndef ANDYPOLIS2_MINA_H
#define ANDYPOLIS2_MINA_H

#include "edificio.h"

class Mina : public Edificio {
protected:
    static int cantidadTotal;

public:
    Mina();

    // PRE: -
    // POS: devuelve la cantidad total del los escopetas
    static int obtenerTotal();

    // PRE: -
    // POS: resta uno a la cantidad total
    void restarTotal(){cantidadTotal--; }

    void mostrarEnMapa(){cout << "M ";}

};


#endif //ANDYPOLIS2_MINA_H
