#ifndef ANDYPOLIS2_ORO_H
#define ANDYPOLIS2_ORO_H
#include "material.h"

const string ORO = "oro";


class Oro : public Material{
protected:

    static int cantidadTotal;
    int cantidad;

public:
    Oro(int fila, int columna, int cantidad){this->nombre = ORO; this->fila = fila; this->columna = columna;
        this->cantidad = cantidad;}

    Oro(int cantidad){ this->nombre = ORO;
        this->cantidadTotal += cantidad;}

    void restarTotal(int cantidad){ this->cantidadTotal -= cantidad;}
    void aumentarTotal(int cantidad) {this->cantidadTotal += cantidad;}

    int obtenerTotal(){return cantidadTotal;}

    void mostrarEnMapa(){cout << "W";}

};


#endif //ANDYPOLIS2_ORO_H
