#include "archivos.h"



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

    string nombre, piedra, madera, metal, cantidad_permitidos;

    while (getline(archivo, nombre, ESPACIO)) {
        getline(archivo, piedra, ESPACIO);
        getline(archivo, madera, ESPACIO);
        getline(archivo, metal, ESPACIO);
        getline(archivo, cantidad_permitidos);
    

        // Edificio edificio (nombre, stoi(piedra), stoi(madera), stoi(metal), stoi(cantidad_permitidos));
        int piedras = stoi(piedra);
        int maderas = stoi(madera);
        int metales = stoi(metal);
        int tope = stoi(cantidad_permitidos);
        // Edificio edificio (nombre, stoi(piedra), stoi(madera), stoi(metal), stoi(cantidad_permitidos));

        Edificio* nuevo_edificio = setearEdificio(nombre, piedras, maderas, metales, tope);

        //Edificio * nuevo_edificio = crearEdificio(nombre);

        edificios->agregarEdificio(nuevo_edificio);
        
        // edificios->agregar(edificio);
    }
   
}

void Archivo::procesarArchivoDatosEdificios(Edificio** edificios) {
    fstream archivo;
    abrir(archivo, PATH_EDIFICIOS);

    string nombre, piedra, madera, metal, cantidad_permitidos;
    //edificios = new Edificio* [CANTIDAD_TIPOS_EDIFICIOS];
    int i = 0;
    while (getline(archivo, nombre, ESPACIO)) {
        getline(archivo, piedra, ESPACIO);
        getline(archivo, madera, ESPACIO);
        getline(archivo, metal, ESPACIO);
        getline(archivo, cantidad_permitidos);

        int piedras = stoi(piedra);
        int maderas = stoi(madera);
        int metales = stoi(metal);
        int tope = stoi(cantidad_permitidos);
        // Edificio edificio (nombre, stoi(piedra), stoi(madera), stoi(metal), stoi(cantidad_permitidos));

        Edificio* nuevo_edificio = setearEdificio(nombre, piedras, maderas, metales, tope);


        //*edificios = nuevo_edificio;
        //cout << edificios[i]->obtenerNombre() << endl;
        i++;

        //edificios->agregarEdificio(nuevo_edificio);
        // edificios->agregar(edificio);
    }
}


void Archivo::procesarArchivoEdificios(Mapa &mapa, Ciudad * edificiosConstruidos) {

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

        int filas = stoi(fila);
        int columnas = stoi(columna);
        nuevoEdificio = crearEdificio(nombre, filas, columnas);
        //mapa.alta(*nuevoEdificio, filas, columnas);
        edificiosConstruidos->agregarEdificio(nuevoEdificio);
        
        mapa.obtenerDato(filas, columnas)->agregarEdificio(nuevoEdificio);

    }
    nuevoEdificio = nullptr;
    delete nuevoEdificio;
    cerrar(archivo);
}


/*
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

*/
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

Edificio* Archivo::crearEdificio(string &nombre, int fila, int columna) {

        Edificio* nuevo;

        if (nombre == "mina") {
            nuevo = new Mina(fila, columna);
        } else if (nombre == "aserradero") {
            nuevo = new Aserradero(fila, columna);
        } else if (nombre == "escuela") {
            nuevo = new Escuela(fila, columna);
        } else if (nombre == "fabrica") {
            nuevo = new Fabrica(fila, columna);
        } else if (nombre == "yacimiento") {
            nuevo = new Yacimiento(fila, columna);
        } else if (nombre == "obelisco") {
            nuevo = new Obelisco(fila, columna);
        } else if (nombre == "planta") {
            nuevo = new Planta(fila, columna);
        }

        return nuevo;

}


Material* Archivo::setearMaterial(string nombre, int cantidad) {
    Material* nuevo;

    if (nombre == "madera" || nombre == "Madera"){
        nuevo = new Madera(cantidad);
    } else if (nombre == "piedra" || nombre == "Piedra"){
        nuevo = new Piedra(cantidad);
    } else if (nombre == "metal" || nombre == "Metal"){
        nuevo = new Metal(cantidad);
    } else if (nombre == "oro" || nombre == "Oro"){
        nuevo = new Oro(cantidad);
    }
    return nuevo;
}

Edificio* Archivo::setearEdificio(string nombre, int piedra, int madera, int metal, int tope) {

    Edificio* nuevo;

    if (nombre == "mina"  || nombre == "Mina") {
        nuevo = new Mina(piedra, madera, metal, tope);
    } else if (nombre == "aserradero"  || nombre == "Aserradero") {
        nuevo = new Aserradero(piedra, madera, metal, tope);
    } else if (nombre == "escuela" || nombre == "Escuela") {
        nuevo = new Escuela(piedra, madera, metal, tope);
    } else if (nombre == "yacimiento"  || nombre == "Yacimiento") {
        nuevo = new Yacimiento(piedra, madera, metal, tope);
    } else if (nombre == "fabrica" || nombre == "Fabrica") {
        nuevo = new Fabrica(piedra, madera, metal, tope);
    } else if (nombre == "obelisco" || nombre == "Obelisco") {
        nuevo = new Obelisco(piedra, madera, metal, tope);
    } else if (nombre == "planta" || nombre == "Planta") {
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