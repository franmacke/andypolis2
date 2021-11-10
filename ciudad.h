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
    // static int cantidad;
    int cantidad = 0;
    int cantidadConstruidos = 0;

    public:
    int cantidadEdificios(){return this->cantidad;};
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

/*
class Ciudad {
    private:
    Edificio * edificios;
    int cantidad;
    Inventario inventario;

    public:
    Ciudad();
    Ciudad(Inventario inventario);
    int cantidad_edificios();
    Edificio obtener(int posicion);
    Edificio buscar(string nombre);
    void cambiar(int posicion, Edificio edificio_nuevo);
    void copiar(Edificio * copia);
    void apuntar(Edificio * copia);
    void agregar(Edificio edificio_nuevo);
    void construir(Edificio edificio);
    bool verificar_maximo(Edificio edificio);
    bool verificar_materiales(Edificio edificio);
    void constuir_por_nombre();
    string ingresar_nombre();
    void liberar_memoria();
};
*/
#endif