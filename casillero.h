#ifndef CASILLERO_H
#define CASILLERO_H

#include <iostream>
#include "objeto.h"

using namespace std;

class Casillero {

    protected:
        string identificador;
        string elementos;//los iniciales de los elementos(edificios y materiales)
        string tipoCasillero;//T, L o C

        Objeto * dato;
    public:
        Casillero();
        Casillero(string identificador);
        void nombre();
        string obtenerId();
        string obtenerTC(); //TC: tipoCasillero
        bool vacio();
        virtual void mostrarEnMapa() = 0;
        virtual void cambiar_dato(Objeto * dato) = 0;

};


#endif