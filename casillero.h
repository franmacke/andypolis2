#ifndef CASILLERO_H
#define CASILLERO_H

#include <iostream>
#include "objeto.h"
#include "material.h"
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

    // PRE: -
    // POS: devuelve el tipo de casillero
        string obtenerTC(); //TC: tipoCasillero

    // PRE: -
    // POS: devuelve si esta ocupado o no el casillero
        bool esVacio(){return this->vacio;}

    // PRE: -
    // POS: agrega materiales al casillero y indica q esta ocupado
        virtual void agregarMateriales(Material* material) = 0;

    // PRE: -
    // POS: agrega edificios al casillero y indica q esta ocupado
        virtual void agregarEdificio(Edificio* edificio) = 0;//virtual void es una funcion q si o si todas las hijas tienen q tener la funcion?

    // PRE: -
    // POS: elimino el edificio y desocupo el casillero.
        virtual void eliminarEdificio() = 0;

        //virtual void eliminarObjeto() = 0;

    // PRE: -
    // POS: mostrar los emojis correspondientes al mapa
        virtual void mostrarEnMapa() = 0;

    // PRE: -
    // POS: devuelve el nombre del objeto q se encuentra en el casillero
        virtual string obtenerNombre() = 0;

    // PRE: -
    // POS: libero memoria de material
        virtual void liberarMemoria() = 0;

        //virtual void cambiar_dato(Objeto * dato) = 0;

};


#endif