#ifndef CIUDAD_H
#define CIUDAD_H

#include <iostream>
#include "edificio.h"
#include "utilidad.h"
#include "materiales.h"

class Ciudad {
    private:
    Edificio * edificios;
    int cantidad;

    public:
    int cantidad_edificios();
    Edificio obtener(int posicion);
    Edificio buscar(string nombre);
    void cambiar(int posicion, Edificio edificio_nuevo);
    void copiar(Edificio * copia);
    void apuntar(Edificio * copia);
    void agregar(Edificio material_nuevo);
    void liberar_memoria();
    void construir(Edificio edificio);
    bool verificar_maximo(Edificio edificio);
    bool verificar_materiales(Edificio edificio);
};

#endif