#ifndef ANDYPOLIS2_OBELISCO_H
#define ANDYPOLIS2_OBELISCO_H
#include "edificio.h"

const string OBELISCO = "obelisco";

class Obelisco : public Edificio {
protected:
    static int cantidadTotal;

public:
    Obelisco(int fila, int columna){
        this->nombre = OBELISCO;
        this->fila = fila;
        this->columna = columna; cantidadTotal++;}

    Obelisco(int piedra, int madera, int metal, int cantidadPermitida);

    // PRE: -
    // POS: devuelve la cantidad total del los escopetas
    int obtenerTotal(){return cantidadTotal;}

    // PRE: -
    // POS: resta uno a la cantidad total
    void restarTotal(){cantidadTotal--; }

    void mostrarEnMapa(){cout << COLOR_VERDE<< EMOJI_OBELISCO ;}

};


#endif //ANDYPOLIS2_OBELISCO_H
