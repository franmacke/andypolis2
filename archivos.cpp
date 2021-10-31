#include "archivos.h"
#include "interfaz.h"

const string PATH_MATERIALES = "assets/materiales.txt";
const string PATH_UBICACIONES = "assets/ubicaciones.txt";
const string PATH_MAPA = "assets/mapa.txt";
const string PATH_EDIFICIOS = "assets/edificios.txt";

const char ESPACIO = 32;
const char RETORNO = 13;
const char NULO = 00;

void Archivo::abrir(fstream &archivo, string path) {
    archivo.open(path);

    if (!archivo.is_open()) {
        cout << "Falta archivo en " << path << endl;
    }

}

void Archivo::cerrar(fstream &archivo) {
    archivo.close();
}

// Edificio * Archivo::leer_edificios() {
//     fstream archivo;
//     abrir(archivo);
// }


Materiales * Archivo::leer_materiales() {
    fstream archivo;
    abrir(archivo, PATH_MATERIALES);

    Materiales * lista_materiales = new Materiales;

    string nombre, cantidad;

    while(archivo >> nombre) {
        archivo >> cantidad;

        MaterialInventario nuevo_material (nombre, stoi(cantidad));

        lista_materiales->agregar(nuevo_material);
    }

    return lista_materiales;
}


// Coordenada * Archivo::leer_ubicaciones() {
//     fstream archivo;
//     abrir(archivo, PATH_UBICACIONES);



// }

Mapa Archivo::leer_mapa() {
    fstream archivo;
    abrir(archivo, PATH_MAPA);

    string filas;
    string columnas;
    string casillero;

    getline(archivo, filas, ESPACIO);
    getline(archivo, columnas);

    cout << "FILAS: " << filas << endl;
    cout << "COLUMNAS: " << columnas << endl;

    Dimension dimensiones (stoi(filas), stoi(columnas));
    Mapa mapa (dimensiones);

    int i = 0;
    int j = 0;
    int contador = 0;

    // while (getline(archivo, casillero, ESPACIO)) {
    //     cout << casillero;
    //     contador ++;
    // }

    //  cout << i << " " << j << endl;
    //  cout << contador;

    for (int i = 0; i < dimensiones.obtener_alto(); i++) {
        for (int j = 0; j < dimensiones.obtener_ancho(); j++) {
            if (j != dimensiones.obtener_ancho() - 1) {
                getline(archivo, casillero, ESPACIO);
            } else {
                getline(archivo, casillero);
            }
            // cout << casillero << " ";
            Coordenada coordenadas(i,j);
            Casillero dato (casillero);
            mapa.cargar_casillero(dato, coordenadas);
        }
    } 
    return mapa;
}

