#include "inventario.h"

Inventario::Inventario() {
    this->cantidad = 0;
}


int Inventario::cantidad_materiales() {
    return cantidad;
}

MaterialInventario Inventario::obtener(int posicion) {
    return lista_materiales[posicion];
}

MaterialInventario Inventario::buscar(string nombre_material) {
    bool resultado = false;
    int contador = 0;
    MaterialInventario material_buscado;
    Utilidad utilidad;

    while (!resultado && contador < cantidad_materiales()) {
        if (obtener(contador).nombre() == utilidad.minuscula(nombre_material)) {
            material_buscado = obtener(contador);
        }
    }

    return material_buscado;
}

int Inventario::madera() {
    return buscar("madera").cantidad();
}

int Inventario::piedra() {
    return buscar("piedra").cantidad();
}

int Inventario::metal() {
    return buscar("metal").cantidad();
}