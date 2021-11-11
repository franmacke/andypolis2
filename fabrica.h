
#ifndef ANDYPOLIS2_FABRICA_H
#define ANDYPOLIS2_FABRICA_H

#include "edificio.h"

const string FABRICA = "fabrica";

class Fabrica : public Edificio {
protected:
    static int cantidadTotal;

public:
    Fabrica(int fila, int columna){ 
        this->nombre = "fabrica";
        this->fila = fila;
        this->columna = columna; cantidadTotal++;}

    Fabrica(int piedra, int madera, int metal, int cantidadPermitida);

    // PRE: -
    // POS: devuelve la cantidad total del los escopetas
    int obtenerTotal(){return cantidadTotal;}

    // PRE: -
    // POS: resta uno a la cantidad total
    void restarTotal(){cantidadTotal--; }

    void mostrarEnMapa(){cout << "F";}

};


#endif //ANDYPOLIS2_FABRICA_H
