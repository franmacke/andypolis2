//
// Created by ydsas on 5/11/2021.
//

#ifndef ANDYPOLIS2_PIEDRA_H
#define ANDYPOLIS2_PIEDRA_H
#include "material.h"


class Piedra : public Material{
protected:

    static int cantidadTotal;
    int cantidad;

public:
    Piedra(int fila, int columna, int cantidad){this->nombre = "Piedra"; this->fila = fila; this->columna = columna;
        this->cantidad = cantidad;}

    Piedra(int cantidad){ this->nombre = "Piedra";
        this->cantidadTotal += cantidad;}

    void restarTotal(int cantidad){ this->cantidadTotal -= cantidad;}
    void aumentarTotal(int cantidad) {this->cantidadTotal += cantidad;}

    //virtual void sumarCantidad(int cantidad){ this->cantidadTotal += cantidad;}

    int obtenerTotal(){return this->cantidadTotal;}

    void mostrarEnMapa(){cout << "S";}


};


#endif //ANDYPOLIS2_PIEDRA_H
