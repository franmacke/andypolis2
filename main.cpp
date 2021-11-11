#include <iostream>
#include "archivos.h"
#include "juego.h"


using namespace std;

int main() {
    Archivo datos;
    Juego juego;
    int filas, columnas;
    Ciudad * ciudad = new Ciudad;
    Ciudad * edificiosConstruidos = new Ciudad;
    Inventario* inventario = new Inventario;

    filas = datos.leerFilas();
    columnas = datos.leerColumnas();

    Mapa mapa(filas, columnas);

    datos.procesarArchivoMapa(mapa);
    datos.procesarArchivoEdificios(mapa, edificiosConstruidos);
    datos.leerArchivoEdificios(ciudad);
    datos.leerArchivosMateriales(inventario);

    juego.mostrarTodosLosEdificios(ciudad);

    juego.mostrarInventario(inventario);

    mapa.mostrar();
    juego.interfazPrincipal(mapa, ciudad, edificiosConstruidos, inventario);

    return 0;
}