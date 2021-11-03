#ifndef MAPA_H
#define MAPA_H

#include <iostream>
#include "dimension.h"
#include "coordenada.h"
#include "casillero.h"

using namespace std;

typedef Casillero* Dato;

class Mapa {
    private:
    int fila, columna;
    Casillero casilleros[8][10]; //FALTA HACER DINAMICO
    // Dato **mapa;


    public:
    Mapa(int fila, int columna);
    void cargar_casillero(Casillero dato, Coordenada coordenada);
    void cambiar_edificio(Edificio, int x, int y);
    void mostrar();

    Casillero obtener(int x, int y);

    bool estaVacio(int fila, int columna);

    void baja(int fila, int columna);

    void alta(Dato dato, int fila, int columna);

    int filaMapa(){return fila;}

    int columnaMapa(){return columna;}

};


#endif