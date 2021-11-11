#ifndef CIUDAD_H
#define CIUDAD_H

#include <iostream>
#include "edificio.h"
#include "utilidad.h"
#include "materiales.h"
#include "inventario.h"

class Ciudad {
    private:
    Edificio ** edificios;
    int cantidad = 0;
    int cantidadConstruidos = 0;

    public:
    int cantidadEdificios(){return this->cantidad;};

    void sacarEdificio(){ this->cantidad --;}

    int cantidadEdificiosConstruidos();
    void agregarEdificio(Edificio * nuevo_edificio);
    void eliminarEdificio(int posicion);
    void copiarLista(Edificio ** copia_lista);
    Edificio * obtenerEdificio(int posicion);
    Edificio * buscarEdificioPorNombre(string nombre);
    Edificio * buscarEdificioPorCoordenadas(int fila, int columna);
    void eliminarPorCoordenadas(int fila, int columna);

    void liberarMemoria();
    ~Ciudad();    
};

#endif