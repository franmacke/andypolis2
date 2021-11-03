#ifndef CASILLERO_H
#define CASILLERO_H

#include <iostream>
#include "material.h"
#include "edificio.h"
#include "parser.h"

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
    bool vacio();
    void mostrarEnMapa();
    void cambiar_dato(string dato);
};


#endif