#include "ciudad.h"

/*
int Ciudad::cantidadEdificios() {
    return cantidad;
}*/


void Ciudad::copiarLista(Edificio ** copia) {
    for (int i = 0; i < cantidadEdificios(); i++) {
        copia[i] = obtenerEdificio(i);
    }
}

Edificio * Ciudad::obtenerEdificio(int posicion) {
    return edificios[posicion];
}


void Ciudad::agregarEdificio(Edificio * edificio_nuevo) {
    Edificio ** lista_copia = new Edificio * [cantidadEdificios() + 1];
    copiarLista(lista_copia);
    lista_copia[cantidadEdificios()] = edificio_nuevo;

    if (cantidadEdificios() != 0) {
        liberarMemoria();
    }

    edificios = lista_copia;
    cantidad++;
}

void Ciudad::eliminarEdificio(int posicion) {
    // REVISAR PARA CANTIDAD 1 Y 0
    if (cantidadEdificios() != 0) {
        Edificio ** lista_copia = new Edificio * [cantidadEdificios() - 1];
        
        int contador = 0;

        for (int i = 0; i < cantidadEdificios(); i++) {
            if (i != posicion) {
                lista_copia[contador] = obtenerEdificio(i);
                contador++;
            } else {
                delete edificios[posicion];
            }
        }
        cantidad--;
        edificios = lista_copia;
    }
}

void Ciudad::eliminarPorCoordenadas(int fila, int columna) {
    int contador = 0;
    bool resultado = false;
    int posicion = -1;
    Utilidad utilidad;

    while (contador < cantidadEdificios() && !resultado) {

        if (obtenerEdificio(contador)->obtenerFila() == fila && obtenerEdificio(contador)->obtenerColumna() == columna) {
            resultado = true;
            posicion = contador;
            obtenerEdificio(contador)->restarTotal();
        } else {
            contador++;
        }
    }
    eliminarEdificio(posicion);
}

Edificio * Ciudad::buscarEdificioPorCoordenadas(int fila, int columna) {
    int contador = 0;
    bool resultado = false;
    int posicion = -1;
    Utilidad utilidad;

    while (contador < cantidadEdificios() && !resultado) {
        if (obtenerEdificio(contador)->obtenerFila() == fila && obtenerEdificio(contador)->obtenerColumna() == columna) {
            resultado = true;
            posicion = contador;
        } else {
            contador++;
        }
    }
    //Devuelve un edificio si existe y si no devuelve un nullptr
    return edificios[posicion];
}


Edificio * Ciudad::buscarEdificioPorNombre(string nombre) {
    int contador = 0;
    bool resultado = false;
    Edificio * edificio = nullptr;
    Utilidad utilidad;

    while (contador < cantidadEdificios() && !resultado) {
        if (utilidad.minuscula(obtenerEdificio(contador)->obtenerNombre()) == utilidad.minuscula(nombre)) {
            resultado = true;
            edificio = obtenerEdificio(contador);
        } else {
            contador++;
        }
    }
    //Devuelve un edificio si existe y si no devuelve un nullptr
    return edificio;
}

void Ciudad::liberarMemoria() {
    // for (int i = 0; i < cantidadEdificios(); i++) {
    //     delete edificios[i];
    // }

    delete [] edificios;
    this->edificios = nullptr;
}

/*
Ciudad::Ciudad() {
    this->cantidad = 0;
}

Ciudad::Ciudad(Inventario inventario) {
    this->inventario = inventario;
    this->cantidad = 0;
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





 */