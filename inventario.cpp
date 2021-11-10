#include "inventario.h"

Inventario::~Inventario() {
    for (int i = 0; i < cantidad_materiales(); i++) {
        delete [] materiales[i];
    } 

    delete [] materiales;
    delete this;
}


int Inventario::cantidad = 0;

void Inventario::copiarLista(Material **copiaLista) {
    for (int i = 0; i < cantidad_materiales(); ++i) {
        copiaLista[i] = obtenerMaterial(i);
    }
}

Material* Inventario::obtenerMaterial(int posicion) {
    // cout << materiales[posicion]->obtenerNombre() << " ";
    return materiales[posicion];
}

void Inventario::agregarMaterial(Material *nuevoMaterial) {
    Material** listaCopia = new Material* [cantidad_materiales() + 1];
    copiarLista(listaCopia);
    listaCopia[cantidad_materiales()] = nuevoMaterial;

    if (cantidad_materiales() != 0){
        liberarMemoria();
    }

    materiales = listaCopia;
    cantidad++;
}

Material* Inventario::obtenerPorNombre(string nombre) {
    Utilidad utilidad;
    Material * material;
    
    for (int i = 0; i < cantidad_materiales(); i++) {
        if (nombre == utilidad.minuscula(obtenerMaterial(i)->obtenerNombre())) {
            material = obtenerMaterial(i);
        }
    }

    return material;
}

void Inventario::construirEdificio(Edificio * edificio) {
    obtenerPorNombre("madera")->restarTotal(edificio->obtenerMadera());
    obtenerPorNombre("piedra")->restarTotal(edificio->obtenerPiedra());
    obtenerPorNombre("metal")->restarTotal(edificio->obtenerMetal());
}

void Inventario::demolerEdificio(Edificio * edificio) {
    obtenerPorNombre("madera")->aumentarTotal(edificio->obtenerMadera() / 2);
    obtenerPorNombre("piedra")->aumentarTotal(edificio->obtenerPiedra() / 2);
    obtenerPorNombre("metal")->aumentarTotal(edificio->obtenerMetal() / 2);
}


/*
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
 */