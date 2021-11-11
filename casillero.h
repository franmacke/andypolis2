#ifndef CASILLERO_H
#define CASILLERO_H

#include <iostream>
#include "objeto.h"
#include "material.h"
#include "edificio.h"


using namespace std;

class Casillero {

protected:
        string tipoCasillero;//T, L o C
        bool vacio;
public:
        string obtenerTC(); 

        bool esVacio(){return this->vacio;}

        virtual void agregarMateriales(Material* material) = 0;

        virtual void agregarEdificio(Edificio* edificio) = 0;

        virtual void eliminarEdificio() = 0;

        virtual void eliminarObjeto() = 0;

        virtual void mostrarEnMapa() = 0;

        virtual string obtenerNombre() = 0;

        virtual void liberarMemoria() = 0;

        virtual ~Casillero() = default;
};


#endif