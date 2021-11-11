#ifndef MATERIAL_H
#define MATERIAL_H

#include <iostream>
//#include "objeto.h"
#include "utilidad.h"

using namespace std;

class Material /*: public Objeto*/ {
protected:
    string nombre;
    int fila, columna;
    //static int cantidadTotal;
    //int cantidad_material;

public:
    Material() {};
    Material(int cantidad) {};
    Material(int fila, int columna, int cantidad) {};

    string obtenerNombre(){ return this->nombre;}

    int obtenerFila(){return this->fila;}

    int obtenerColumna(){return this->columna;}

    //virtual void sumarCantidad(int cantidad) = 0;

    virtual void mostrarEnMapa() = 0;

    virtual void restarTotal(int cantidad) = 0;

    virtual void aumentarTotal(int cantidad) = 0;

    virtual int obtenerTotal() = 0;

    virtual ~Material() {};
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