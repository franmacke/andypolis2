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

    Edificio* nuevoEdificio;
    string nombre, fila, columna, basura;

    fstream archivo;
    abrir(archivo, PATH_UBICACIONES);

    while (getline(archivo, nombre, ' ')) {

        getline(archivo, basura, '(');
        getline(archivo, fila, ',');
        getline(archivo, basura, ESPACIO);
        getline(archivo, columna, ')');
        getline(archivo, basura);

        int filas = stoi(fila) - 1;
        int columnas = stoi(columna) - 1;

        nuevoEdificio = crearEdificio(nombre);
        //mapa.alta(*nuevoEdificio, filas, columnas);
        mapa.obtenerDato(filas, columnas)->agregarEdificio(nuevoEdificio);

    }
    nuevoEdificio = nullptr;
    delete nuevoEdificio;
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


/*
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

    for (int i = 0; i < fila; i++) {
        for (int j = 0; j < columna; j++) {
            if (j != columna - 1) {
                getline(archivo, casillero, ESPACIO);
            } else {
                getline(archivo, casillero);
            }
            // cout << casillero << " ";
            Coordenada coordenadas(i,j);
            mapa.cargar_casillero(casillero, coordenadas);
        }
    }
    
    cerrar(archivo);
    return mapa;
}
*/
void Archivo::procesarArchivoMapa(Mapa& mapa) {
    fstream archivo;
    abrir(archivo, PATH_MAPA);

    Dato nuevoCasillero;
    string filas, columnas, tipoCasillero;
    int fila, columna;

    getline(archivo, filas, ESPACIO);
    getline(archivo, columnas);

    cout << "FILAS: " << filas << endl;
    cout << "COLUMNAS: " << columnas << endl;

    //fila = stoi(filas);
    //columna = stoi(columnas);

    fila = mapa.filaMapa();
    columna = mapa.columnaMapa();

    for (int i = 0; i < fila; i++) {
        for (int j = 0; j < columna; j++) {
            if (j != columna - 1) {
                getline(archivo, tipoCasillero, ESPACIO);
            } else {
                getline(archivo, tipoCasillero);
            }
            // cout << casillero << " ";
            //Coordenada coordenadas(i,j);
            //mapa.alta(casillero, i, j);
            nuevoCasillero = crearCasillero(tipoCasillero);
            //mapa.setearMapa(tipoCasillero, i, j);
            mapa.alta(nuevoCasillero, i, j);


        }
    }
}

int Archivo::leerFilas()  {
    fstream archivo;
    abrir(archivo, PATH_MAPA);
    string fila;
    int x = 0;
    getline(archivo, fila, ' ');
    x = stoi(fila, nullptr);
    return x;

}

int Archivo::leerColumnas() {
    fstream archivo;
    abrir(archivo, PATH_MAPA);
    string columna, basura;
    int y = 0;
    archivo >> basura;
    archivo >> columna;
    //getline(archivo, columna);
    y = stoi(columna, nullptr);
    return y;
}

Edificio* Archivo::crearEdificio(string &nombre) {

        Edificio* nuevo;

        if (nombre == "mina") {
            nuevo = new Mina();
        } else if (nombre == "aserradero") {
            nuevo = new Aserradero();
        } else if (nombre == "escuela") {
            nuevo = new Escuela();
        } else if (nombre == "fabrica") {
            nuevo = new Fabrica();
        } else if (nombre == "obelisco") {
            nuevo = new Obelisco();
        } else if (nombre == "planta") {
            nuevo = new Planeta();
        }

        return nuevo;

}

Dato Archivo::crearCasillero(string &nombre) {

    Dato nuevo;
    if (nombre == "C") {
        nuevo = new CasilleroTransitable();
    } else if (nombre == "T") {
        nuevo = new CasilleroConstruible();
    } else if (nombre == "L") {
        nuevo = new CasilleroInaccesible();
    }

    return nuevo;

}