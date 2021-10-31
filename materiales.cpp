#include "materiales.h"

MaterialInventario Materiales::obtener(int posicion) {
    return lista_materiales[posicion];
}

void Materiales::cambiar(int posicion, MaterialInventario nuevo_material) {
    lista_materiales[posicion] = nuevo_material;
}

void Materiales::copiar(MaterialInventario * copia) {
    for (int i = 0; i < cantidad_materiales(); i++) {
        copia[i] = obtener(i);
    }
}

void Materiales::apuntar(MaterialInventario * copia) {
    lista_materiales = copia;
}

int Materiales::cantidad_materiales() {
    return cantidad;
}

void Materiales::liberar_memoria() {
    delete [] lista_materiales;
}

void Materiales::agregar(MaterialInventario material_nuevo) {
    MaterialInventario * lista_copia = new MaterialInventario [cantidad_materiales() + 1];
    copiar(lista_copia);
    lista_copia[cantidad_materiales()] = material_nuevo;

    if (cantidad_materiales() != 0) {
        liberar_memoria();
    }

    lista_materiales = lista_copia;
    cantidad++;
}