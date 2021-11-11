#ifndef EDIFICIO_H
#define EDIFICIO_H

#include <iostream>
//#include "coordenada.h"
//#include "objeto.h"
//#include "casilleroConstruible.h"
#include "utilidad.h"

// const string OBELISCO = "O";
// const string FABRICA = "F";
// const string ASERRADERO = "A";
// const string MINA = "M";
// const string PLANTA = "P";
// const string ESCUELA = "E";

using namespace std;

class Edificio {
protected:
    string nombre;
    int cantNecesariaMadera, cantNecesariPiedra, cantNecesariMetal, cantPermitido;
    int fila, columna;
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

    // void agregarEdificio(Edificio** edificios, Edificio* nuevoEdificio, int tope);

    int obtenerMadera(){return this->cantNecesariaMadera;}

    int obtenerPiedra(){return this->cantNecesariPiedra;}

    int obtenerMetal(){return this->cantNecesariMetal;}

    int obtenerTope(){return this->cantPermitido;}

    int obtenerFila(){return this->fila;}

    int obtenerColumna(){return this->columna;}

    virtual void mostrarEnMapa() = 0;

    virtual int obtenerTotal() = 0;
    
    virtual void restarTotal() = 0;
};


#endif