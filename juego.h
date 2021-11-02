#ifndef JUEGO_H
#define JUEGO_H

#include <iostream>
#include "interfaz.h"
#include "archivos.h"
#include "inventario.h"

class Juego {
    private:
    int opcion = 0;
    bool partida;
    Interfaz interfaz;
    Materiales * materiales;
    Inventario inventario;

    public:
    void cargar_archivos();
    void jugar();
    void mostrarOpciones();
    void pedirOpcion();
    void interfazPrincipal(Mapa& mapa);

    void consultarCoordenada(Mapa& mapa);



};


#endif