#include "archivos.h"


const char ESPACIO = 32;
const char RETORNO = 13;
const char NULO = 00;

void Archivo::abrir(fstream &archivo, string path) {
    // cout << "Abriendo " << path << endl;
    archivo.open(path, ios::in);

    if (!archivo.is_open()) {
        cout << "Falta archivo en " << path << endl;
    } else {
        // cout << "ENCONTRE " << path << endl;
    }

}

void Archivo::cerrar(fstream &archivo) {
    archivo.close();
}


void Archivo::leerArchivosMateriales(Inventario *materiales) {
    fstream archivo;
    abrir(archivo, PATH_MATERIALES);
    string nombre, cantidad;
    while(getline(archivo, nombre, ESPACIO)){
        getline(archivo, cantidad);

        int cantidadInicial = stoi(cantidad);
        Material* nuevoMaterial = setearMaterial(nombre, cantidadInicial);
        materiales->agregarMaterial(nuevoMaterial);
    }
}



 void Archivo::leerArchivoEdificios(Ciudad * edificios) {
     fstream archivo;
     abrir(archivo, PATH_EDIFICIOS);

     string nombre, nombre_2 ,piedra, madera, metal, cantidad_permitidos;

     while (getline(archivo, nombre, ESPACIO)) {
         if (nombre == "planta") {
             getline(archivo, nombre_2, ESPACIO);
             nombre = nombre + " " + nombre_2;
         }
         getline(archivo, piedra, ESPACIO);
         getline(archivo, madera, ESPACIO);
         getline(archivo, metal, ESPACIO);
         getline(archivo, cantidad_permitidos);

         int piedras = stoi(piedra);
         int maderas = stoi(madera);
         int metales = stoi(metal);
         int tope = stoi(cantidad_permitidos);

         Edificio* nuevo_edificio = setearEdificio(nombre, piedras, maderas, metales, tope);

         edificios->agregarEdificio(nuevo_edificio);
     }
   
 }


void Archivo::procesarArchivoEdificios(Mapa &mapa, Ciudad * edificiosConstruidos) {

    Edificio* nuevoEdificio;
    string nombre, nombre2, fila, columna, basura;

    fstream archivo;
    abrir(archivo, PATH_UBICACIONES);

    while (getline(archivo, nombre, ' ')) {

        if (nombre == "planta"){
            getline(archivo, nombre2, ' ');
            nombre = nombre + " " + nombre2;
        }
        getline(archivo, basura, '(');
        getline(archivo, fila, ',');
        getline(archivo, basura, ESPACIO);
        getline(archivo, columna, ')');
        getline(archivo, basura);

        int filas = stoi(fila);
        int columnas = stoi(columna);
        nuevoEdificio = crearEdificio(nombre, filas, columnas);
        edificiosConstruidos->agregarEdificio(nuevoEdificio);
        
        mapa.obtenerDato(filas, columnas)->agregarEdificio(nuevoEdificio);

    }
    nuevoEdificio = nullptr;
    delete nuevoEdificio;
    cerrar(archivo);
}


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

    fila = mapa.filaMapa();
    columna = mapa.columnaMapa();

    for (int i = 0; i < fila; i++) {
        for (int j = 0; j < columna; j++) {
            if (j != columna - 1) {
                getline(archivo, tipoCasillero, ESPACIO);
            } else {
                getline(archivo, tipoCasillero);
            }
            nuevoCasillero = crearCasillero(tipoCasillero);
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

Edificio* Archivo::crearEdificio(string &nombre, int fila, int columna) {

        Edificio* nuevo;

        if (nombre == MINA) {
            nuevo = new Mina(fila, columna);
        } else if (nombre == ASERRADERO) {
            nuevo = new Aserradero(fila, columna);
        } else if (nombre == ESCUELA) {
            nuevo = new Escuela(fila, columna);
        } else if (nombre == FABRICA) {
            nuevo = new Fabrica(fila, columna);
        } else if (nombre == YACIMIENTO) {
            nuevo = new Yacimiento(fila, columna);
        } else if (nombre == OBELISCO) {
            nuevo = new Obelisco(fila, columna);
        } else if (nombre == PLANTA) {
            nuevo = new Planta(fila, columna);
        }

        return nuevo;

}


Material* Archivo::setearMaterial(string nombre, int cantidad) {
    Material* nuevo;

    // REVISAR

    if (nombre == MADERA || nombre == "Madera"){
        nuevo = new Madera(cantidad);
    } else if (nombre == PIEDRA || nombre == "Piedra"){
        nuevo = new Piedra(cantidad);
    } else if (nombre == METAL || nombre == "Metal"){
        nuevo = new Metal(cantidad);
    } else if (nombre == ORO || nombre == "Oro"){
        nuevo = new Oro(cantidad);
    }
    return nuevo;
}

Edificio* Archivo::setearEdificio(string nombre, int piedra, int madera, int metal, int tope) {

    Edificio* nuevo;

    if (nombre == MINA || nombre == "Mina") {
        nuevo = new Mina(piedra, madera, metal, tope);
    } else if (nombre == ASERRADERO || nombre == "Aserradero") {
        nuevo = new Aserradero(piedra, madera, metal, tope);
    } else if (nombre == ESCUELA || nombre == "Escuela") {
        nuevo = new Escuela(piedra, madera, metal, tope);
    } else if (nombre == YACIMIENTO  || nombre == "Yacimiento") {
        nuevo = new Yacimiento(piedra, madera, metal, tope);
    } else if (nombre == FABRICA || nombre == "Fabrica") {
        nuevo = new Fabrica(piedra, madera, metal, tope);
    } else if (nombre == OBELISCO || nombre == "Obelisco") {
        nuevo = new Obelisco(piedra, madera, metal, tope);
    } else if (nombre == PLANTA || nombre == "planta") {
        nuevo = new Planta(piedra, madera, metal, tope);
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