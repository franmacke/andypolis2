#ifndef ARCHIVOS_H
#define ARCHIVOS_H

#include <iostream>
#include <fstream>
#include "edificio.h"
#include "ciudad.h"
#include "material.h"
#include "materiales.h"
#include "mapa.h"
#include "interfaz.h"


using namespace std;

class Archivo {
    public:
    void abrir(fstream &archivo, string path);
    void cerrar(fstream &archivo);
    Ciudad * leer_edificios();
    Materiales * leer_materiales();
    Coordenada * leer_ubicaciones();
    Mapa leer_mapa();
};


#endif