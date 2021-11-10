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

    Edificio * pedirNombreEdificio(Ciudad * datosEdificios);

    bool pedirConfirmacion();

    void consultarCoordenada(Mapa& mapa);

    void demolerEdificio(Mapa &mapa, Ciudad* datosEdificios, Ciudad* edificiosConstruidos, Inventario * inventario);

    bool esCasilleroConstruible(Mapa& mapa, int fila, int columna);

    bool esCasilleroDemolible(Mapa& mapa, int fila, int columna);

    void construirEdificioPorNombre(Mapa& mapa, Ciudad* ciudad, Ciudad * edificiosConstruidos, Inventario * inventario);

    // void construirEdificio(Mapa &mapa, Ciudad* datosEdificios,Ciudad* edificiosConstruidos ,Edificio* edificio, Inventario * inventario);

    void constuirEdificio(Mapa &mapa, Edificio* datosEdificio, Ciudad* edificiosConstruidos, Inventario * inventario);

    bool comprobarMateriales(Edificio * edificio, Inventario * inventario);

    bool comprobarCantidadMaxima(Edificio * edificioParaConstruir);

    bool comprobarCantidadMinima(Edificio* edificio);

    void mostrarInventario(Inventario* inventario);

    void mostrarTodosLosEdificios(Ciudad* ciudad);

    void mostrarConstruidos(Ciudad* ciudad, Mapa &mapa);

    void mostrarDato(string nombre, int piedra, int madera, int metal, int total, int cantidadPermitida);

    void lluviaDeRecursos(Mapa& mapa);

    void lluviaDeMadera(Mapa& mapa);

    void lluviaDeMetal(Mapa& mapa);

    void lluviaDePiedra(Mapa& mapa);

    int filaAleatorio(Mapa& mapa);

    int columnaAleatorio(Mapa& mapa);

    int cantAleatoriaMadera();

    int cantAleatoriaMetal();

    int cantAleatoriaPiedra();

    // Se repite en archivos.h
    Edificio * crearEdificio(string nombre, int fila, int columna);

    void recolectarMateriales(Mapa& mapa, Inventario* inventario, Ciudad* ciudad);

    int cantProducidoPorAserradero(Ciudad* ciudad);

    int cantProducidoPorFabrica(Ciudad* ciudad);

    int cantProducidoPorMina(Ciudad* ciudad);

    void guardarYSalir(Mapa& mapa,  Ciudad* ciudad, Inventario* inventario);

    void guardarArchivoMateriales(Inventario* inventario);

    //void guardarArchivoUbicaciones(Mapa& mapa, Ciudad* ciudad);


    //void mostarEdificiosTodos(Ciudad * edificios);

    //void mostrarEdificiosConstruidos(Ciudad * edificios);




};


#endif