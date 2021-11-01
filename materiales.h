#ifndef MATERIALES_H
#define MATERIALES_H

#include <iostream>
#include "material.h"
#include "utilidad.h"

using namespace std;

class Materiales {
    private:
    int cantidad;
    MaterialInventario * lista_materiales;

    public:
    Materiales();
    int cantidad_materiales();
    MaterialInventario * lista();
    MaterialInventario obtener(int posicion);
    MaterialInventario buscar(string nombre);
    void cambiar(int posicion, MaterialInventario material_nuevo);
    void copiar(MaterialInventario * copia);
    void apuntar(MaterialInventario * copia);
    void agregar(MaterialInventario material_nuevo);
    void liberar_memoria();
};

#endif