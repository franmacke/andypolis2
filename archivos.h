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
//#include "interfaz.h"
#include "parser.h"
#include "edificio.h"

using namespace std;

const string PATH_MATERIALES = "materiales.txt";
const string PATH_UBICACIONES = "ubicaciones.txt";
const string PATH_MAPA = "mapa.txt";
const string PATH_EDIFICIOS = "edificios.txt";

class Archivo {
    public:
    // PRE: -
    // POS: abre el archivo con PATH_ARCHIVO
    void abrir(fstream &archivo, string path);

    // PRE: -
    // POS: cierra el archivo
    void cerrar(fstream &archivo);
    //Ciudad * leer_edificios();

    // PRE: -
    // POS: devuelve la cantidad de filas indicadas en el .txt
    int leerFilas();

    // PRE: -
    // POS: devuelve la cantidad de columnas indicadas en el .txt
    int leerColumnas();

    // PRE: abre ubicacio.txt vienen los edificios y las coordenadas bien cargadas
    // POS: lee y carga los edificios en la mapa y en la ciudad
    void procesarArchivoEdificios(Mapa& mapa, Ciudad * edificiosConstruidos);
    //Materiales * leer_materiales();
    Coordenada * leer_ubicaciones();
    Mapa leer_mapa();
    void leerMapa(Mapa& mapa);
    void procesarArchivoMapa(Mapa& mapa);

    // PRE: abre materiales.txt vienen los datos bien cargados
    // POS: crea y carga los datos de materiales a inventario
    void leerArchivosMateriales(Inventario* materiales);
    //void procesarArchivoDatosEdificios(Edificio** edificios);
    void procesarArchivoDatosEdificios(Edificio** edificios);

private:

    // PRE: -
    // POS: reserva espacio para el edificio correspondiente en el heap y lo devuelve como puntero a Edificio para cargarlo en la mapa
    Edificio* crearEdificio(string& nombre, int fila, int columna);

    // PRE: -
    // POS: reserva espacio para el edificio correspondiente en el heap y lo devuelve como puntero a Edificio para cargarlo en la ciudad
    Edificio* setearEdificio(string nombre, int piedra, int madera, int metal, int tope);

    // PRE: -
    // POS: reserva espacio para el material correspondiente en el heap y lo devuelve como puntero a Material
    Material* setearMaterial(string nombre, int cantidad);

    // PRE: -
    // POS: reserva espacio para el casillero correspondiente en el heap y lo devuelve como puntero a Casillero
    Dato crearCasillero(string& nombre);


};


#endif