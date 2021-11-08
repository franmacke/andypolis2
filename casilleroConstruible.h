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
    CasilleroConstruible(){ this->tipoCasillero = "Construible"; this->edificio = nullptr;
        this->vacio = true;}

    void agregarEdificio(Edificio* edificio){ this->edificio = edificio; this->vacio = false;}

    void agregarMateriales(Material* material){}

    void mostrarEnMapa();

    string obtenerNombre(){return this->edificio->obtenerNombre();}

    //void cambiar_dato(Objeto * dato);
    //void convertir(string dato);

};


#endif