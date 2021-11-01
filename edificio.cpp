#include "edificio.h"


Edificio::Edificio() { 
    this->nombre_edificio = "";
}

Edificio::Edificio(string nombre, int piedra, int madera, int metal, int cantidad_permitidos) {
    this->nombre_edificio = nombre;
    this->madera_minima = madera;
    this->piedra_minima = piedra;
    this->metal_minimo = metal;
    this->cantidad_permitidos = cantidad_permitidos;
    this->cantidad_edificios = 0;
}

string Edificio::nombre() {
    return nombre_edificio;
}

int Edificio::cantidad() {
    return cantidad_edificios;
}

int Edificio::maxima_cantidad() {
    return cantidad_permitidos;
}

int Edificio::madera() {
    return madera_minima;
}

int Edificio::piedra() {
    return piedra_minima;
}

int Edificio::metal() {
    return metal_minimo;
}

void Edificio::construir() {
    cantidad_edificios++;
}

void Edificio::destruir() {
    cantidad_edificios--;
}

void Edificio::mostrar() {
    cout << "--------------" << endl;
    cout << "nombre: " << nombre() << endl;
    cout << "cantidad: " << cantidad() << endl;
    cout << "madera: " << madera() << endl;
    cout << "metal: " << metal() << endl;
    cout << "piedra: " << piedra() << endl;
    cout << "permitidos: " << maxima_cantidad() << endl;
}

// void Edificio::ubicar(Coordenada ubicacion) {
//     coordenadas_edificio.x() = ubicacion.x();
//     coordenadas_edificio.y() = ubicacion.y();
// }

// Coordenada Edificio::coordenadas() {
//     return coordenadas_edificio;
// }