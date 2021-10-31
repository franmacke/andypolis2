#ifndef INTENTARIO_H
#define INVENTARIO_H

#include <iostream>
#include <material.h>

using namespace std;

class Intentario {
    private:
    Material * lista_materiales;
    int cantidad_materiales;

    public:
    Material * obtener_materiales();
    Material madera();
    Material piedra();
    Material metal();
};

#endif