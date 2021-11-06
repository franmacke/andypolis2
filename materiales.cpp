/*
#include "materiales.h"

Materiales::Materiales() {
    cantidad = 0;
}

MaterialInventario * Materiales::lista() {
    return lista_materiales;
}

MaterialInventario Materiales::obtener(int posicion) {
    return lista_materiales[posicion];
}

MaterialInventario Materiales::buscar(string nombre) {
    int contador = 0;
    bool resultado = false;
    MaterialInventario material;

    while (contador < cantidad_materiales() && !resultado) {
        Utilidad utilidad;
        if (lista_materiales[contador].nombre() == utilidad.minuscula(nombre)) {
            resultado = true;
        } else {
            contador++;
        }
    }

    if (resultado) {
        material = lista_materiales[contador];
    } 

    //Devuelve un material si existe y si no devuelve un objeto vacio
    return material;
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
    int cantidad = cantidad_materiales();
    
    lista_copia[cantidad] = material_nuevo;
    
    if (cantidad_materiales() != 0) {
        liberar_memoria();
    }

    lista_materiales = lista_copia;
    cantidad++;
}
 */