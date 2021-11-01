#ifndef EDIFICIO_H
#define EDIFICIO_H

#include <iostream>
#include "coordenada.h"

using namespace std;

class Edificio {
    protected:
    string nombre_edificio;
    int cantidad_edificios = 0;
    int cantidad_permitidos;
    int madera_minima;
    int piedra_minima;
    int metal_minimo;
    // Coordenada coordenadas_edificio 

    public:
    Edificio();
    Edificio(string nombre, int piedra, int madera, int metal, int cantidad_permitidos);
    string nombre();
    int cantidad();
    int maxima_cantidad();
    int madera();
    int piedra();
    int metal();
    void construir();
    void destruir();
    void mostrar();
    // void ubicar(Coordenada ubicacion);
    // Coordenada coordenadas();
};


#endif