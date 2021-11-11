//
// Created by ydsas on 3/11/2021.
//

#ifndef ANDYPOLIS2_ESCUELA_H
#define ANDYPOLIS2_ESCUELA_H

#include "edificio.h"

const string ESCUELA = "escuela";

class Escuela : public Edificio {
private:
    //string identificador;
    static int cantidadTotal;

public:
    Escuela(int fila, int columna){ 
        this->nombre = ESCUELA;
        this->fila = fila;
        this->columna = columna; cantidadTotal++;}

    Escuela(int piedra, int madera, int metal, int cantidadPermitida);

    // PRE: -
    // POS: devuelve la cantidad total del los escopetas
    /*static*/  int obtenerTotal(){return cantidadTotal;}

    // PRE: -
    // POS: resta uno a la cantidad total
    void restarTotal(){cantidadTotal--; }

    void mostrarEnMapa(){cout << COLOR_VERDE<< EMOJI_ESCUELA ;}

};


#endif //ANDYPOLIS2_ESCUELA_H
