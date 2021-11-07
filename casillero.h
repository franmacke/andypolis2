#ifndef CASILLERO_H
#define CASILLERO_H

#include <iostream>
#include "objeto.h"
#include "edificio.h"

using namespace std;

class Casillero {

protected:
        //string identificador;
        //string nombre;
        //string elementos;//los iniciales de los elementos(edificios y materiales)
        string tipoCasillero;//T, L o C
        bool vacio;

        //Objeto * dato;
public:
        //Casillero(){ this->vacio = true;};
        //Casillero(string identificador);
        //void nombre();
        //string obtenerId();
        string obtenerTC(); //TC: tipoCasillero

        bool esVacio(){return this->vacio;}

        virtual void agregarEdificio(Edificio* edificio) = 0;//virtual void es una funcion q si o si todas las hijas tienen q tener la funcion?

        virtual void mostrarEnMapa() = 0;

        virtual string obtenerNombre() = 0;

        //virtual void cambiar_dato(Objeto * dato) = 0;

};


#endif