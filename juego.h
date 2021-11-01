#ifndef JUEGO_H
#define JUEGO_H

#include <iostream>
#include "interfaz.h"
#include "archivos.h"
#include "inventario.h"

class Juego {
    private:
    bool partida;
    Interfaz interfaz;
    Materiales * materiales;
    Inventario inventario;

    public:
    void cargar_archivos();
    void jugar();

};


#endif