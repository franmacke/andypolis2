
#ifndef ANDYPOLIS2_FABRICA_H
#define ANDYPOLIS2_FABRICA_H

#include "edificio.h"


class Fabrica : public Edificio {
protected:
    static int cantidadTotal;

public:
    Fabrica(){cantidadTotal++;}

    // PRE: -
    // POS: devuelve la cantidad total del los escopetas
    static int obtenerTotal(){return cantidadTotal;}

    // PRE: -
    // POS: resta uno a la cantidad total
    void restarTotal(){cantidadTotal--; }

    void mostrarEnMapa(){cout << "F ";}

};


#endif //ANDYPOLIS2_FABRICA_H
