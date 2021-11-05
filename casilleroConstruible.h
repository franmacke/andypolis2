#ifndef CASILLERO_CONSTRUIBLE_H
#define CASILLERO_CONSTRUIBLE_H

#include <iostream>
#include "casillero.h"
#include "edificio.h"


using namespace std;

class CasilleroConstruible : public Casillero {

private:
    Edificio* edificio;


public:
    CasilleroConstruible(){ this->tipoCasillero = "construible"; this->edificio = nullptr;}

    void agregarEdificio(Edificio* edificio){ this->edificio = edificio;}

    void mostrarEnMapa();

    //void cambiar_dato(Objeto * dato);
    //void convertir(string dato);

};


#endif