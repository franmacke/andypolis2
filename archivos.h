#ifndef ARCHIVOS_H
#define ARCHIVOS_H

#include <iostream>
#include <fstream>
#include "edificio.h"
#include "ciudad.h"
#include "material.h"
#include "materiales.h"
#include "mapa.h"
#include "casillero.h"
#include "casilleroConstruible.h"
#include "casilleroInaccesible.h"
#include "casilleroTransitable.h"
//#include "interfaz.h"
#include "parser.h"

using namespace std;

class Archivo {
    public:
    void abrir(fstream &archivo, string path);
    void cerrar(fstream &archivo);
    //Ciudad * leer_edificios();

    // PRE: -
    // POS: devuelve la cantidad de filas indicadas en el .txt
    int leerFilas();

    // PRE: -
    // POS: devuelve la cantidad de columnas indicadas en el .txt
    int leerColumnas();

    void procesarArchivoEdificios(Mapa& mapa);
    //Materiales * leer_materiales();
    Coordenada * leer_ubicaciones();
    Mapa leer_mapa();
    void leerMapa(Mapa& mapa);
    void procesarArchivoMapa(Mapa& mapa);

private:
    Edificio* crearEdificio(string& nombre);
    Dato crearCasillero(string& nombre);


};


#endif