#ifndef EDIFICIO_H
#define EDIFICIO_H

#include <iostream>
//#include "coordenada.h"
//#include "objeto.h"
//#include "casilleroConstruible.h"
#include "utilidad.h"

const string OBELISCO = "O";
const string FABRICA = "F";
const string ASERRADERO = "A";
const string MINA = "M";
const string PLANTA = "P";
const string ESCUELA = "E";

using namespace std;

class Edificio /* : public Objeto*/ {
protected:
    string nombre;
    //int cantidad_edificios = 0;
    //int cantidad_permitidos;
    //int madera_minima;
    //int piedra_minima;
    //int metal_minimo;
    //string identificador;
    //static int cantidadTotal;

public:
    //Edificio();
    //Edificio(string identificador);
    //Edificio(string nombre, int piedra, int madera, int metal, int cantidad_permitidos);
    //string nombre();
    string obtenerNombre(){ return this->nombre;}
    int cantNecesariaMadera, cantNecesariPiedra, cantNecesariMetal;
    //int cantidad();
    virtual void mostrarEnMapa() = 0;
    virtual int obtenerTotal() = 0;   // Yo lo declararia aca


    //int maxima_cantidad();
    //int madera();
    //int piedra();
    //int metal();
    //void construir();
    //void destruir();
    //void mostrar();
    //void cambiar_dato();
    // void ubicar(Coordenada ubicacion);
    // Coordenada coordenadas();


    // Coordenada coordenadas_edificio

};


#endif