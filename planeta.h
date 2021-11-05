//
// Created by ydsas on 3/11/2021.
//

#ifndef ANDYPOLIS2_PLANETA_H
#define ANDYPOLIS2_PLANETA_H
#include "edificio.h"


class Planeta : public Edificio {
protected:
    //string identificador = "P";

    static int cantidadTotal;

public:
    Planeta(){ this->nombre = "planta";};

    // PRE: -
    // POS: resta uno a la cantidad total
    void restarTotal();
    int obtenerTotal();

    // PRE: -
    // POS: imprime por pantalla la letra "E"
    void mostrarSimbolo();

    void mostrarEnMapa(){cout << "P";}

};


#endif //ANDYPOLIS2_PLANETA_H
