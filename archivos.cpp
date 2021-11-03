#include "archivos.h"

const string PATH_MATERIALES = "materiales.txt";
const string PATH_UBICACIONES = "ubicaciones.txt";
const string PATH_MAPA = "mapa.txt";
const string PATH_EDIFICIOS = "edificios.txt";

const char ESPACIO = 32;
const char RETORNO = 13;
const char NULO = 00;

void Archivo::abrir(fstream &archivo, string path) {
    cout << "Abriendo " << path << endl;
    archivo.open(path, ios::in);

    if (!archivo.is_open()) {
        cout << "Falta archivo en " << path << endl;
    } else {
        cout << "ENCONTRE " << path << endl;
    }

}

void Archivo::cerrar(fstream &archivo) {
    archivo.close();
}
/*
Ciudad * Archivo::leer_edificios() {
    fstream archivo;
    abrir(archivo, PATH_EDIFICIOS);

    Ciudad * edificios = new Ciudad;

    string nombre, piedra, madera, metal, cantidad_permitidos;

    while (getline(archivo, nombre, ESPACIO)) {
        getline(archivo, piedra, ESPACIO);
        getline(archivo, madera, ESPACIO);
        getline(archivo, metal, ESPACIO);
        getline(archivo, cantidad_permitidos);

        Edificio edificio (nombre, stoi(piedra), stoi(madera), stoi(metal), stoi(cantidad_permitidos));

        edificios->agregar(edificio);
    }

    return edificios;   
}
*/

void Archivo::procesarArchivoEdificios(Mapa &mapa) {

    // Dato nuevoEdificio;
    string nombre, fila, columna, cant, basura;

    fstream archivo;
    abrir(archivo, PATH_EDIFICIOS);

    while (getline(archivo, nombre, ' ')) {

        getline(archivo, cant, '(');
        getline(archivo, fila, ',');
        getline(archivo, columna, ')');
        getline(archivo, basura);

        // nuevoEdificio = crearEdificio(nombre, cant, fila, columna);
        // mapa.alta(nuevoEdificio, stoi(fila), stoi(columna));
        Parser parser = Parser(nombre);


    }
    // nuevoEdificio = nullptr;
    // delete nuevoEdificio;
    cerrar(archivo);
}



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
    cerrar(archivo);
    return lista_materiales;
}


// Coordenada * Archivo::leer_ubicaciones() {
//     fstream archivo;
//     abrir(archivo, PATH_UBICACIONES);

//     string nombre, coordenada_x, coordenada_y, basura;

//     while(getline(archivo, nombre, ESPACIO)) {
//         getline(archivo, basura, '(');      //SACA PARENTESIS
//         getline(archivo, coordenada_x, ',');    
//         getline(archivo, basura, ESPACIO);      //SACA ESPACIO VACIO
//         getline(archivo, coordenada_y, ')');

//         Coordenada coordenada (stoi(coordenada_x), stoi(coordenada_y));

//     }
 
// }

void Archivo::procesarArchivoMapa() {

}

Mapa Archivo::leer_mapa() {
    fstream archivo;
    abrir(archivo, PATH_MAPA);

    string filas, columnas, casillero;
    int fila, columna;

    getline(archivo, filas, ESPACIO);
    getline(archivo, columnas);

    cout << "FILAS: " << filas << endl;
    cout << "COLUMNAS: " << columnas << endl;

    fila = stoi(filas);
    columna = stoi(columnas);
    Mapa mapa (stoi(filas), stoi(columnas));

    // int i = 0;
    // int j = 0;
    // int contador = 0;


    // while (getline(archivo, casillero, ESPACIO)) {
    //     cout << casillero;
    //     contador ++;
    // }

    //  cout << i << " " << j << endl;
    //  cout << contador;


    for (int i = 0; i < fila; i++) {
        for (int j = 0; j < columna; j++) {
            if (j != columna - 1) {
                getline(archivo, casillero, ESPACIO);
            } else {
                getline(archivo, casillero);
            }
            // cout << casillero << " ";
            Coordenada coordenadas(i,j);
            Parser parser = Parser(casillero);
            mapa.cargar_casillero(*parser.procesar_entrada(), coordenadas);
        }
    }
    
    cerrar(archivo);
    return mapa;
}

// Dato Archivo::crearEdificio(string &nombre, string cant, string fila, string columna) {
//     Dato nuevo;
//     if (nombre == "Mina"){
//         nuevo = new Mina();
//     }
// }