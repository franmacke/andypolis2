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
    Mina(int fila, int columna){ 
        this->nombre = "mina";
        this->fila = fila;
        this->columna = columna; cantidadTotal++;}

    Mina(int piedra, int madera, int metal, int cantidadPermitida);

    // PRE: -
    // POS: devuelve la cantidad total del los escopetas
    /*static*/   int obtenerTotal(){return cantidadTotal;};

    // PRE: -
    // POS: resta uno a la cantidad total
    void restarTotal(){cantidadTotal--; }

    void mostrarEnMapa(){cout << COLOR_VERDE<< EMOJI_MINA ;}

};


#endif //ANDYPOLIS2_MINA_H
