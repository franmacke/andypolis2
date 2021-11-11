#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <iostream>

#include "material.h"
#include "utilidad.h"
#include "edificio.h"
#include "metal.h"
#include "madera.h"
#include "oro.h"
#include "piedra.h"

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

    void sacarMateriales(){ this->cantidad --;}

    void agregarMaterial(Material* nuevoMaterial);
    void copiarLista(Material** copiaLista);
    Material* obtenerMaterial(int posicion);
    void liberarMemoria(){delete [] materiales;
        this->materiales = nullptr;}
    Material * obtenerPorNombre(string nombre);

    int obtenerMadera() {return obtenerPorNombre(MADERA)->obtenerTotal();}
    int obtenerPiedra() {return obtenerPorNombre(PIEDRA)->obtenerTotal();}
    int obtenerMetal() {return obtenerPorNombre(METAL)->obtenerTotal();}

    void construirEdificio(Edificio * edificio);
    void demolerEdificio(Edificio * edificio);

    ~Inventario();
    /*
    MaterialInventario obtener(int posicion);
    MaterialInventario buscar(string nombre_material);
    int madera();
    int piedra();
    int metal();
*/
};


#endif