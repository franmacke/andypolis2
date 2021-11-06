#ifndef MATERIAL_H
#define MATERIAL_H

#include <iostream>
#include "objeto.h"
#include "utilidad.h"

using namespace std;

class Material /*: public Objeto*/ {
protected:
    string nombre_material;
    //int cantidad_material;

public:
    //Material();
    //Material(string nombre, int cantidad);
    //string nombre();
    //int cantidad();
    string obtenerNombre(){return this->nombre_material;}

    virtual void mostrarEnMapa() = 0;
};

    /*
class MaterialRecogible : public Material {
    public: 
    MaterialRecogible();
    MaterialRecogible(string nombre, int cantidad);
    string identificador() {return "ZS";};
    void mostrar();
};

class MaterialInventario : public Material {
    public:
    MaterialInventario();
    MaterialInventario(string nombre, int cantidad);
    void mostrar();
    string identificador() {return "X";};

};

     */

#endif