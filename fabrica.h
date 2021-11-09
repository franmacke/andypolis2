
#ifndef ANDYPOLIS2_FABRICA_H
#define ANDYPOLIS2_FABRICA_H

#include "edificio.h"


class Fabrica : public Edificio {
protected:
    //string identificador = "A";

    static int cantidadTotal;

public:
    Fabrica(int fila, int columna){ 
        this->nombre = "Fabrica";
        this->fila = fila;
        this->columna = columna; cantidadTotal++;}

    Fabrica(int piedra, int madera, int metal, int cantidadPermitida);

    // PRE: -
    // POS: devuelve la cantidad total del los escopetas
    /*static*/   int obtenerTotal(){return cantidadTotal;}

    // PRE: -
    // POS: resta uno a la cantidad total
    void restarTotal(){cantidadTotal--; }

    void mostrarEnMapa(){cout << "F";}

};


#endif //ANDYPOLIS2_FABRICA_H
