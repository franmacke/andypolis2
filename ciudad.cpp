#include "ciudad.h"

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

    while (contador < cantidad_edificios() && !resultado) {
        Utilidad utilidad;
        if (obtener(contador).nombre() == utilidad.minuscula(nombre)) {
            resultado = true;
        } else {
            contador++;
        }
    }

    if (resultado) {
        edificio = obtener(contador);
    } 

    //Devuelve un edificio si existe y si no devuelve un objeto vacio
    return edificio;

}

void Ciudad::construir(Edificio edificio) {
    if (verificar_materiales(edificio) && verificar_maximo(edificio)) {
        edificio.construir();
    } else {
        // No se puede construir
    }
}

bool Ciudad::verificar_maximo(Edificio edificio) {
    return (edificio.maxima_cantidad() > edificio.cantidad());
}

bool Ciudad::verificar_materiales(Edificio edificio) {
    // Hay que pasar los materiales por parametro
}   

