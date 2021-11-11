#include "ciudad.h"

Ciudad::~Ciudad() {
    for (int i = 0; i < cantidadEdificios(); i++) {
        cout << i <<": Descturctor edificio" << endl;
        delete edificios[i];
    }

    delete [] edificios;
}


void Ciudad::copiarLista(Edificio ** copia) {
    for (int i = 0; i < cantidadEdificios(); i++) {
        copia[i] = edificios[i];
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
    if (cantidadEdificios() != 1) {
        Edificio ** lista_copia = new Edificio * [cantidadEdificios() - 1];
        
        int contador = 0;

        for (int i = 0; i < cantidadEdificios(); i++) {
            if (i != posicion) {
                lista_copia[contador] = edificios[i];
                contador++;
            } else {
                delete edificios[posicion];
            }
        }

        delete [] edificios;
        edificios = lista_copia;
    } else {
        Edificio ** lista_copia = new Edificio *;
        delete edificios[0];

        delete [] edificios;

        edificios = lista_copia;
    }
    cantidad--;
}

void Ciudad::eliminarPorCoordenadas(int fila, int columna) {
    int contador = 0;
    bool resultado = false;
    int posicion = -1;

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
    
    delete [] edificios;
    this->edificios = nullptr;
}

