#include "mapa.h"

Mapa::Mapa(int fila, int columna) {
    this->fila = fila;
    this->columna = columna;
    mapa = new Dato* [fila];
    for (int i = 0; i < fila; ++i) {
        mapa[i] = new Dato[columna];
        for (int j = 0; j < columna; ++j) {
            mapa[i][j] = nullptr;
        }
    }
}

Dato Mapa::obtener(int fila, int columna) {
    return casilleros[fila][columna];
}

Dato Mapa::obtenerDato(int fila, int columna) {
    return (mapa[fila][columna]);
}
/*
void Mapa::cargar_casillero(string casillero, Coordenada coordenada) {
    Parser parser = Parser(casillero);
    casilleros[coordenada.x()][coordenada.y()] = parser.procesar_entrada();
}
*/
void Mapa::alta(Dato dato, int fila, int columna) {

    mapa[fila][columna] = dato;

}

void Mapa::altaEdificio(Edificio *edificio, int fila, int columna) {

}

/*
void Mapa::setearMapa(string dato, int fila, int columna) {
    //for (int i = 0; i < this->fila; ++i) {
      //  for (int j = 0; j < this->columna; ++j) {

            Parser parser = Parser(dato);
            mapa[fila][columna] = parser.procesar_entrada();
        //}

    //}
}
*/

void Mapa::mostrar() {
    for (int i = 0; i < this->fila; i++ ) {
        for (int j = 0; j < this->columna; j++) {
            //cout << casilleros[i][j]->obtenerId() << " ";
            //cout << obtenerDato(i,j)->obtenerId() << " ";
            obtenerDato(i,j)->mostrarEnMapa();
            cout << " |";
        }
        cout << endl;
    }
}

void Mapa::baja(int fila, int columna) {}

/*
void Mapa::alta(string dato, int fila, int columna) {
    Parser parser = Parser(dato);
    Objeto * objeto = parser.crear_dato();
    casilleros[fila][columna]->cambiar_dato(objeto);


}*/

/*
bool Mapa::estaVacio(int fila, int columna) {
    return obtener(fila, columna)->vacio(); 
}
*/