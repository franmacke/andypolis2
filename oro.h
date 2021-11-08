//
// Created by ydsas on 5/11/2021.
//

#ifndef ANDYPOLIS2_ORO_H
#define ANDYPOLIS2_ORO_H
#include "material.h"

class Oro : public Material{
protected:

    static int cantidadTotal;

public:
    Oro(int fila, int columna, int cantidad){this->fila = fila; this->columna = columna;
        this->cantidadTotal += cantidad;}

    Oro(int cantidad){ this->nombre = "Oro";
        this->cantidadTotal = cantidad;}

    void restarTotal(int cantidad){ this->cantidadTotal -= cantidad;}

    int obtenerTotal(){return cantidadTotal;}

    void mostrarEnMapa(){cout << "W";}

};


#endif //ANDYPOLIS2_ORO_H
