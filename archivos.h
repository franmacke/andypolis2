#ifndef ARCHIVOS_H
#define ARCHIVOS_H

#include <iostream>
#include <fstream>
#include "edificio.h"
#include "ciudad.h"
#include "inventario.h"
#include "material.h"
#include "materiales.h"
#include "mapa.h"
#include "casillero.h"
#include "casilleroConstruible.h"
#include "casilleroInaccesible.h"
#include "casilleroTransitable.h"
#include "parser.h"
#include "edificio.h"

using namespace std;

const string PATH_MATERIALES = "materiales.txt";
const string PATH_UBICACIONES = "ubicaciones.txt";
const string PATH_MAPA = "mapa.txt";
const string PATH_EDIFICIOS = "edificios.txt";

class Archivo {
    public:
    void abrir(fstream &archivo, string path);
    void cerrar(fstream &archivo);

    // PRE: -
    // POS: devuelve la cantidad de filas indicadas en el .txt
    int leerFilas();

    // PRE: -
    // POS: devuelve la cantidad de columnas indicadas en el .txt
    int leerColumnas();

    void procesarArchivoEdificios(Mapa& mapa, Ciudad * edificiosConstruidos);
    Coordenada * leer_ubicaciones();
    Mapa leer_mapa();
    void leerMapa(Mapa& mapa);
    void procesarArchivoMapa(Mapa& mapa);
    void leerArchivoEdificios(Ciudad * edificios);
    void leerArchivosMateriales(Inventario* materiales);
    void procesarArchivoDatosEdificios(Edificio** edificios); // NO VA

private:
    Edificio* crearEdificio(string& nombre, int fila, int columna);
    Edificio* setearEdificio(string nombre, int piedra, int madera, int metal, int tope);
    Material* setearMaterial(string nombre, int cantidad);
    Dato crearCasillero(string& nombre);


};


#endif