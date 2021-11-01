#include "ciudad.h"


Ciudad::Ciudad() {
    this->cantidad = 0;
}

Ciudad::Ciudad(Inventario inventario) {
    this->inventario = inventario;
    this->cantidad = 0;
}


int Ciudad::cantidad_edificios() {
    return cantidad;
}

Edificio Ciudad::obtener(int posicion) {
    return edificios[posicion];
}

Edificio Ciudad::buscar(string nombre) {
    int contador = 0;
    bool resultado = false;
    Edificio edificio;
    Utilidad utilidad;

    while (contador < cantidad_edificios() && !resultado) {
        if (obtener(contador).nombre() == utilidad.minuscula(nombre)) {
            resultado = true;
            edificio = obtener(contador);
        } else {
            contador++;
        }
    }
    //Devuelve un edificio si existe y si no devuelve un objeto vacio
    return edificio;

}

void Ciudad::construir(Edificio edificio) {
    if (verificar_materiales(edificio) && verificar_maximo(edificio)) {
        edificio.construir();
    }
}

bool Ciudad::verificar_maximo(Edificio edificio) {
    bool es_construible = false;
    if (edificio.maxima_cantidad() > edificio.cantidad()) {
        es_construible = true;
    } else {
        cout << "Ya tenes el maximo de este edificio" << endl;
    }
    return es_construible;
}

bool Ciudad::verificar_materiales(Edificio edificio) {
    bool hay_madera = false;
    bool hay_piedra = false;
    bool hay_metal = false;

    if (edificio.madera() >= inventario.madera()) {
        hay_madera = true;
    } else {
        cout << "Falta madera" << endl;
    }

    if (edificio.metal() >= inventario.metal()) {
        hay_metal = true;
    } else {
        cout << "Falta metal" << endl;
    }

    if (edificio.piedra() >= inventario.piedra()) {
        hay_piedra = true;
    } else {
        cout << "Falta piedra" << endl;
    }

    return (hay_madera && hay_metal && hay_piedra);
}   

void Ciudad::constuir_por_nombre() {
    string nombre = ingresar_nombre();
    Edificio edificio_buscado = buscar(nombre);

    if (edificio_buscado.nombre() != "") {
        construir(edificio_buscado);
    }
    
}

string Ciudad::ingresar_nombre() {
    cout << "Ingrese nombre del edificio: " << endl;
    string nombre;
    cin >> nombre;

    return nombre;
}

void Ciudad::copiar(Edificio * copia) {
    for (int i = 0; i < cantidad_edificios(); i++) {
        copia[i] = obtener(i);
    }
}

void Ciudad::agregar(Edificio edificio_nuevo) {
    Edificio * lista_copia = new Edificio [cantidad_edificios() + 1];
    copiar(lista_copia);
    lista_copia[cantidad_edificios()] = edificio_nuevo;

    if (cantidad_edificios() != 0) {
        liberar_memoria();
    }

    edificios = lista_copia;
    cantidad++;
}

void Ciudad::liberar_memoria() {
    delete [] edificios;
}