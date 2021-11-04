#ifndef CASILLERO_H
#define CASILLERO_H

#include <iostream>
#include "objeto.h"

using namespace std;

class Casillero {

    protected:
        string identificador;
        string elementos;
        string nombre_casillero;
        Objeto * dato;
    public:
        Casillero();
        Casillero(string identificador);
        void nombre();
        string obtenerId();
        bool vacio();
        void mostrarEnMapa();
        virtual void cambiar_dato(Objeto * dato) = 0;

};


#endif