#ifndef MAPA_H
#define MAPA_H

#include <iostream>
#include <dimension.h>
#include <coordenada.h>
#include <casillero.h>

using namespace std;

class Mapa {
    private:
    Dimension dimension_mapa;
    Casillero casilleros[8][10];

    public:
    Mapa(Dimension dimension_mapa);
    Dimension dimensiones();
    void cargar_casillero(Casillero dato, Coordenada coordenada);
    void mostrar();

};


#endif