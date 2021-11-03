#ifndef CASILLERO_H
#define CASILLERO_H

#include <iostream>
//#include "material.h"
//#include "edificio.h"

using namespace std;

class Casillero {

protected:
    string identificador;
    string elementos;
    string nombre_casillero;

public:
    Casillero();
    Casillero(string identificador);
    void nombre();
    string obtenerId();

    virtual void mostrarEnMapa() = 0;

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