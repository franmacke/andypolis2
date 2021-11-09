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
    //Materiales * materiales;
    //Inventario inventario;

    public:
    //void cargar_archivos();
    void jugar();
    void mostrarOpciones();
    void pedirOpcion();
    void interfazPrincipal(Mapa& mapa, Ciudad* ciudad, Ciudad* edificiosConstruidos ,Inventario* inventario);

    int pedirFila(Mapa& mapa);

    int pedirColumna(Mapa& mapa);

    void pedirNombreEdificio(string &nombre);

    bool pedirConfirmacion();

    void consultarCoordenada(Mapa& mapa);

    void demolerEdificio(Mapa& mapa, Ciudad * edificiosConstruidos);

    bool esCasilleroConstruible(Mapa& mapa, int fila, int columna);

    bool esCasilleroDemolible(Mapa& mapa, int fila, int columna);

    void construirEdificioPorNombre(Mapa& mapa, Ciudad* ciudad, Ciudad * edificiosConstruidos, Inventario * inventario);

    void construirEdificio(Mapa &mapa, Ciudad* edificiosConstruidos ,Edificio* edificio);

    bool comprobarMateriales(Edificio * edificio, Inventario * inventario);

    void mostrarInventario(Inventario* inventario);

    void mostrarTodosLosEdificios(Ciudad* ciudad);

    void mostrarConstruidos(Ciudad* ciudad, Mapa &mapa);

    void mostrarDato(string nombre, int piedra, int madera, int metal, int total, int cantidadPermitida);

    void lluviaDeRecursos(Mapa& mapa, Inventario* inventario);

    void lluviaDeMadera(Mapa& mapa, Inventario* inventario);

    void lluviaDeMetal(Mapa& mapa, Inventario* inventario);

    void lluviaDePiedra(Mapa& mapa, Inventario* inventario);

    int filaAleatorio(Mapa& mapa);

    int columnaAleatorio(Mapa& mapa);

    int cantAleatoriaMadera();

    int cantAleatoriaMetal();

    int cantAleatoriaPiedra();

    // Se repite en archivos.h
    Edificio * crearEdificio(string nombre, int fila, int columna);


    //void mostarEdificiosTodos(Ciudad * edificios);

    //void mostrarEdificiosConstruidos(Ciudad * edificios);




};


#endif