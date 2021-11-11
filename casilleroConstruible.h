#ifndef CASILLERO_CONSTRUIBLE_H
#define CASILLERO_CONSTRUIBLE_H

#include <iostream>
#include "casillero.h"
#include "edificio.h"

const string CONSTRUIBLE = "construible";

using namespace std;

class CasilleroConstruible : public Casillero {

private:
    Edificio* edificio;

public:
    CasilleroConstruible(){ this->tipoCasillero = CONSTRUIBLE; this->edificio = nullptr;
        this->vacio = true;}

    void agregarEdificio(Edificio* edificio){ this->edificio = edificio; this->vacio = false;}

    void eliminarEdificio() { this->edificio = nullptr; this->vacio = true;}

    void eliminarObjeto() { this->edificio = nullptr; this->vacio = true;}

    void agregarMateriales(Material* material){}

    void mostrarEnMapa();

    string obtenerNombre(){return this->edificio->obtenerNombre();}

    void liberarMemoria() {}

    ~CasilleroConstruible();

};


#endif