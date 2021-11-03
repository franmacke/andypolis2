//
// Created by ydsas on 3/11/2021.
//

#ifndef ANDYPOLIS2_ASERRADERO_H
#define ANDYPOLIS2_ASERRADERO_H
#include "edificio.h"

class Aserradero : public Edificio{
protected:
    static int cantidadTotal;

public:
    Aserradero(){ cantidadTotal++;}//yo creo q aca es donde hay q inicializar el nombre(uso de polimorfismo)

    static int obtenerTotal(){return cantidadTotal;} //aca obtengo la cantidad total de aserradero

    // PRE: -
    // POS: resta uno a la cantidad total
    void restarTotal(){cantidadTotal--; }

    // PRE: -
    // POS: imprime por pantalla la letra "A"
    void mostrarEnMapa(){cout << "A ";}
};


#endif //ANDYPOLIS2_ASERRADERO_H
