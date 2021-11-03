#ifndef MATERIAL_H
#define MATERIAL_H

#include <iostream>

using namespace std;

class Material {
    protected:
    string nombre_material;
    int cantidad_material;

    public:
    Material();
    Material(string nombre, int cantidad);
    string nombre();
    int cantidad();
    void mostrar();
};

class MaterialRecogible : public Material {
    public: 
    MaterialRecogible();
    MaterialRecogible(string nombre, int cantidad);
    void mostrar();
};

class MaterialInventario : public Material {
    public:
    MaterialInventario();
    MaterialInventario(string nombre, int cantidad);
    void mostrar();
};


#endif