#ifndef ANDYPOLIS2_YACIMIENTO_H
#define ANDYPOLIS2_YACIMIENTO_H
#include "edificio.h"

const string YACIMIENTO = "yacimiento";

class Yacimiento : public Edificio {
protected:
    static int cantidadTotal;

public:
    Yacimiento(int fila, int columna){ 
        this->nombre = YACIMIENTO;
        this->fila = fila;
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

    ~Yacimiento() {};
};


#endif //ANDYPOLIS2_YACIMIENTO_H
