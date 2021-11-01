#include "material.h"


Material::Material() { }

Material::Material(string nombre, int cantidad) {
    this->nombre_material = nombre;
    this->cantidad_material = cantidad;
}

string Material::nombre() {
    return nombre_material;
}

int Material::cantidad() {
    return cantidad_material;
}

MaterialInventario::MaterialInventario() { 
    this->nombre_material = "";
}

MaterialInventario::MaterialInventario(string nombre, int cantidad) {
    this->nombre_material = nombre;
    this->cantidad_material = cantidad;
}

void MaterialInventario::mostrar() {
    cout << nombre() << ": " << cantidad() << endl;
}

