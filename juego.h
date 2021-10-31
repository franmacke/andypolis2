#ifndef JUEGO_H
#define JUEGO_H

#include <iostream>
#include <interfaz.h>
#include <archivos.h>

class Juego {
    private:
    bool partida;

    public:
    void cargar_archivos();
    void jugar();

};


#endif