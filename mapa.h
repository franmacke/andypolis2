#ifndef MAPA_H
#define MAPA_H

#include <iostream>
#include "coordenada.h"
#include "parser.h"

using namespace std;

typedef Casillero* Dato;

class Mapa {
    private:
    int fila, columna;
    Dato casilleros[8][10]; //FALTA HACER DINAMICO
    // Dato **mapa;


    public:
    Mapa(int fila, int columna);
    void cargar_casillero(string dato, Coordenada coordenada);
    void mostrar();

    Dato obtener(int x, int y);

    bool estaVacio(int fila, int columna);

    void baja(int fila, int columna);

    void alta(string dato, int fila, int columna);

    int filaMapa(){return fila;}

    int columnaMapa(){return columna;}

};


#endif