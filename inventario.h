#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <iostream>
#include "material.h"
#include "utilidad.h"

using namespace std;

class Inventario {
    private:
    //MaterialInventario * lista_materiales;
    Material** materiales;
    static int cantidad;

    public:
    //Inventario();
    //Inventario(MaterialInventario * lista_materiales);
    static int cantidad_materiales(){return cantidad;}

    void agregarMaterial(Material* nuevoMaterial);
    void copiarLista(Material** copiaLista);
    Material* obtenerMaterial(int posicion);
    void liberarMemoria(){delete [] materiales;}
    /*
    MaterialInventario obtener(int posicion);
    MaterialInventario buscar(string nombre_material);
    int madera();
    int piedra();
    int metal();
*/
};


#endif