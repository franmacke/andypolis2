//
// Created by ydsas on 7/11/2021.
//

#ifndef ANDYPOLIS2_YACIMIENTO_H
#define ANDYPOLIS2_YACIMIENTO_H
#include "edificio.h"

class Yacimiento : public Edificio {
protected:

    //static  int cantNecesariaMadera, cantNecesariPiedra, cantNecesariMetal, cantPermitido;
    static int cantidadTotal;

public:
    Yacimiento(int fila, int columna){ this->fila = fila;
        this->columna = columna; cantidadTotal++;}

    Yacimiento(int piedra, int madera, int metal, int cantidadPermitida);

    // PRE: -
    // POS: resta uno a la cantidad total
    void restarTotal(){cantidadTotal --;};
    int obtenerTotal(){return cantidadTotal;};

    // PRE: -
    // POS: imprime por pantalla la letra "E"
    void mostrarSimbolo();

    void mostrarEnMapa(){cout << "Y";}

};


#endif //ANDYPOLIS2_YACIMIENTO_H
