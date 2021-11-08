#ifndef MAPA_H
#define MAPA_H

#include <iostream>
#include "coordenada.h"
#include "parser.h"
#include "casillero.h"
#include "casilleroConstruible.h"
#include "casilleroInaccesible.h"
#include "casilleroTransitable.h"

using namespace std;

typedef Casillero* Dato;

class Mapa {
    private:
    int fila, columna;
    //Dato casilleros[8][10]; //FALTA HACER DINAMICO
    Dato **mapa;


    public:
    Mapa(int fila, int columna);
    //void cargar_casillero(string dato, Coordenada coordenada);

    void alta(Dato dato, int fila, int columna);

    //void altaEdificio(Edificio* edificio, int fila, int columna);

    void mostrar();

    Dato obtener(int x, int y);

    Dato obtenerDato(int fila, int columna);

    string buscarCoordenadasPorNombre(string nombre);

    //bool estaVacio(int fila, int columna);

    void baja(int fila, int columna);

    //void alta(string dato, int fila, int columna);

    //void setearMapa(string dato, int fila, int columna);

    int filaMapa(){return fila;}

    int columnaMapa(){return columna;}

};


#endif