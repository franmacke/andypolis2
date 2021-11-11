#ifndef ANDYPOLIS2_ASERRADERO_H
#define ANDYPOLIS2_ASERRADERO_H

#include "edificio.h"

const string ASERRADERO = "aserradero";

class Aserradero : public Edificio {
protected:
    static int cantidadTotal;


public:

    Aserradero(int fila, int columna){ 
        this->nombre = ASERRADERO;
        this->fila = fila;
        this->columna = columna; cantidadTotal++;}

    Aserradero(int piedra, int madera, int metal, int cantidadPermitida);
    int obtenerTotal(){return cantidadTotal;} 

    // PRE: -
    // POS: resta uno a la cantidad total
    void restarTotal(){cantidadTotal--; }

    // PRE: -
    // POS: imprime por pantalla la letra "A"
    void mostrarEnMapa(){cout << COLOR_VERDE<< EMOJI_ASERRADERO ;}

    ~Aserradero() {};
};


#endif 
