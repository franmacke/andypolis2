#ifndef CASILLERO_H
#define CASILLERO_H

#include <iostream>
#include "material.h"
#include "edificio.h"

using namespace std;

class Casillero {
    protected:
    string identificador;
    string nombre_casillero;

    public:
    Casillero();
    Casillero(string identificador);
    void nombre();
    string id();
    void dibujar();
};


//separar en otros archivos

// class CasilleroTransitable : public Casillero {
//     public:
//     CasilleroTransitable();
//     MaterialRecogible material;
// };


// class CasilleroInstransitable : public Casillero {

// };


// class CasilleroInaccesible : public Casillero {

// };

#endif