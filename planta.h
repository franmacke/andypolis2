//
// Created by ydsas on 8/11/2021.
//

#ifndef ANDYPOLIS2_PLANTA_H
#define ANDYPOLIS2_PLANTA_H

#include "edificio.h"


class Planta : public Edificio {
protected:
    //string identificador = "P";

    //static  int cantNecesariaMadera, cantNecesariPiedra, cantNecesariMetal, cantPermitido;
    static int cantidadTotal;

public:
    Planta(int fila, int columna){ this->nombre = "planta electrica"; this->fila = fila; this->columna = columna; cantidadTotal++;}

    Planta(int piedra, int madera, int metal, int cantidadPermitida);

    // PRE: -
    // POS: resta uno a la cantidad total
    void restarTotal(){cantidadTotal--;};
    int obtenerTotal(){return cantidadTotal;};

    // PRE: -
    // POS: imprime por pantalla la letra "E"
    void mostrarSimbolo();

    void mostrarEnMapa(){cout << COLOR_VERDE<< EMOJI_PLANTA ;}

};


#endif //ANDYPOLIS2_PLANTA_H
