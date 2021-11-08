#include "juego.h"

/*
void Juego::cargar_archivos() {
    Archivo archivo;
    materiales = archivo.leer_materiales();
    
}
*/

void Juego::jugar() {
    //cargar_archivos();
    
    
}

void Juego::mostrarOpciones() {
    cout << "[1] CONSTRUIR EDIFICIO POR NOMBRE" << endl;
    cout << "[2] LISTAR LOS EDIFICIOS CONSTRUIDOS" << endl;
    cout << "[3] LISTAR TODOS LOS EDIFICIOS" << endl;
    cout << "[4] DEMOLER EDIFICIO POR COORDENADAS" << endl;
    cout << "[5] MOSTRAR MAPA" << endl;
    cout << "[6] CONSULTAR COORDENADAS" << endl;
    cout << "[7] MOSTRAR INVENTARIO" << endl;
    cout << "[8] RECOLECTAR RECURSOS PRODUCIDOS" << endl;
    cout << "[9] LLUVIA DE RECURSOS" << endl;
    cout << "[10] GUARDAR Y SALIR" << endl;
}

void Juego::pedirOpcion() {
   
    cout << " Ingrese una opcion: ";
    cin >> opcion ;
}

int Juego::pedirFila(Mapa& mapa) {
    int fila;
    cout << "\t\tIngrese el numero de fila: ";
    cin >> fila;
    while (fila > mapa.filaMapa()){
        cout << "\t\tFila ingresada esta mal, intentalo de nuevo: ";
        cin >> fila;
    }
    return fila;
}

int Juego::pedirColumna(Mapa& mapa) {
    int columna;
    cout << "\t\tIngrese el numero de columna: ";
    cin >> columna;
    while (columna > mapa.columnaMapa()){
        cout << "\t\tColumna ingresada esta mal, intentalo de nuevo: ";
        cin >> columna;
    }
    return columna;
}

void Juego::interfazPrincipal(Mapa &mapa, Ciudad* ciudad, Inventario* inventario) {

    while (opcion != GUARDAR_Y_SALIR){
        
       mostrarOpciones();
       pedirOpcion();

        switch (opcion) {
            case CONSTRUIR_EDIFICIO_POR_NOMBRE:
                cout << "\n\n\t\t CONSTRUIR EDIFICIO POR NOMBRE \n\n\n";
                break;

            case LISTAR_LOS_EDIFICIOS_CONSTRUIDOS:
                cout << "\n\n\t\t LISTAR LOS EDIFICIOS CONSTRUIDOS \n\n\n";
                mostrarConstruidos(ciudad, mapa);
                break;

            case LISTAR_TODOS_LOS_EDIFICIOS:
                cout << "\n\n\t\t LISTAR TODOS LOS EDIFICIOS \n\n\n";
                mostrarTodosLosEdificios(ciudad);
                break;

            case DEMOLER_UN_EDIFICIO_POR_COORDENADA:
                cout << "\n\n\t\t DEMOLER UN EDIFICIO POR COORDENADA \n\n\n";
                break;

            case MOSTRAR_MAPA:
                cout << "\n\n\t\t MOSTRAR MAPA \n\n\n";
                mapa.mostrar();
                break;

            case CONSULTAR_COORDENADA:
                cout << "\n\n\t\t CONSULTAR COORDENADA \n\n\n";
                consultarCoordenada(mapa);
                break;

            case MOSTRAR_INVENTARIO:
                cout << "\n\n\t\t MOSTRAR INVENTARIO \n\n\n";
                mostrarInventario(inventario);
                break;

            case RECOLECTAR_RECURSOS_PRODUCIDOS:
                cout << "\n\n\t\t RECOLECTAR RECURSOS PRODUCIDOS \n\n\n";
                break;

            case LLUVIA_DE_RECURSOS:
                cout << "\n\n\t\t LLUVIA DE RECURSOS \n\n\n";
                lluviaDeRecursos(mapa, inventario);
                break;

            case GUARDAR_Y_SALIR:
                cout << "\n\n\t\t GUARDAR Y SALIR \n\n\n";
                break;


            default: cout << " Ingreso una opcion invalida" << endl;

        }
        
    }
}

void Juego::mostrarInventario(Inventario *inventario) {
    for (int i = 0; i < CANTIDAD_TIPO_MATERIALES; ++i) {
        cout << "Tipo de material: " << inventario->obtenerMaterial(i)->obtenerNombre() << endl;
        cout << "Cantidad: " << inventario->obtenerMaterial(i)->obtenerTotal() << endl;
        cout << "---------------------------------------------------" << endl;
    }
}


void Juego::mostrarTodosLosEdificios(Ciudad* ciudad) {

    for (int i = 0; i < CANTIDAD_TIPOS_EDIFICIOS; ++i) {
        cout << "Tipo de edificio: " << ciudad->obtenerEdificio(i)->obtenerNombre() << endl;
        cout << "Cantidad de piedras necesarias: " << ciudad->obtenerEdificio(i)->obtenerPiedra() << endl;
        cout << "Cantidad de maderas necesarias: " << ciudad->obtenerEdificio(i)->obtenerMadera() << endl;
        cout << "Cantidad de metales necesarias: " << ciudad->obtenerEdificio(i)->obtenerMetal() << endl;
        cout << "Cantidad de construidos: " << ciudad->obtenerEdificio(i)->obtenerTotal() << endl;
        cout << "Cantidad de permitidos: " << ciudad->obtenerEdificio(i)->obtenerTope() << endl;
        cout << "___________________________________________________" << endl;
    }

}

void Juego::consultarCoordenada(Mapa &mapa) {
    int fila = pedirFila(mapa);
    int columna = pedirColumna(mapa);

    cout << "el casillero es de tipo: " << mapa.obtenerDato(fila, columna)->obtenerTC() << endl;
    if (mapa.obtenerDato(fila, columna)->esVacio()){
        cout << "este casillero esta vacio." << endl;
    } else{
        cout << "este casillero esta ocupado por: " << mapa.obtenerDato(fila, columna)->obtenerNombre() << endl;
    }
}

void Juego::mostrarConstruidos(Ciudad *ciudad, Mapa &mapa) {

    for (int i = 0; i < CANTIDAD_TIPOS_EDIFICIOS; ++i) {

        if (ciudad->obtenerEdificio(i)->obtenerTotal() > 0){
            cout << "Tipo de edificio: " << ciudad->obtenerEdificio(i)->obtenerNombre() << endl;
            cout << "Cantidad de construidos: " << ciudad->obtenerEdificio(i)->obtenerTotal() << endl;
            cout << "Cantidad de permitidos: " << ciudad->obtenerEdificio(i)->obtenerTope() << endl;
            cout << "Ubicaciones: " << mapa.buscarCoordenadasPorNombre(ciudad->obtenerEdificio(i)->obtenerNombre()) << endl;
            cout << "___________________________________________________" << endl;
        }
    }
}



void Juego::mostrarDato(string nombre, int piedra, int madera, int metal, int total, int cantidadPermitida) {
    
}

int Juego::filaAleatorio(Mapa &mapa) {
    return rand() % mapa.filaMapa();
}

int Juego::columnaAleatorio(Mapa &mapa) {
    return rand() % mapa.columnaMapa();
}

int Juego::cantAleatoriaMadera() {
    return rand() % 2;
}

int Juego::cantAleatoriaMetal() {
    return rand() % 4 + 2;
}

int Juego::cantAleatoriaPiedra() {
    return rand() % 2 + 1;
}

void Juego::lluviaDeMadera(Mapa &mapa, Inventario *inventario) {

    int fila = filaAleatorio(mapa);
    int columna = columnaAleatorio(mapa);
    int cantidad = cantAleatoriaMadera();
    //cout << fila << " " << columna << endl;
    while (!mapa.obtenerDato(fila, columna)->esVacio() || mapa.obtenerDato(fila, columna)->obtenerTC() != "Transitable"){
        fila = filaAleatorio(mapa);
        columna = columnaAleatorio(mapa);
    }
    if (cantidad > 0){

        mapa.obtenerDato(fila, columna)->agregarMateriales(new Madera(cantidad));
        cout << "aparecieron " << cantidad << " maderas en: " << fila << " ," << columna << endl;
    }
}


void Juego::lluviaDeMetal(Mapa &mapa, Inventario *inventario) {

    int fila = filaAleatorio(mapa);
    int columna = columnaAleatorio(mapa);
    int cantidad = cantAleatoriaMetal();
    //cout << fila << " " << columna << endl;
    while (!mapa.obtenerDato(fila, columna)->esVacio() || mapa.obtenerDato(fila, columna)->obtenerTC() != "Transitable"){
        fila = filaAleatorio(mapa);
        columna = columnaAleatorio(mapa);
    }
    if (cantidad > 0){

        mapa.obtenerDato(fila, columna)->agregarMateriales(new Metal(cantidad));
        cout << "aparecieron " << cantidad << " metales en: " << fila << " ," << columna << endl;
    }
}


void Juego::lluviaDePiedra(Mapa &mapa, Inventario *inventario) {

    int fila = filaAleatorio(mapa);
    int columna = columnaAleatorio(mapa);
    int cantidad = cantAleatoriaPiedra();
    //cout << fila << " " << columna << endl;
    while (!mapa.obtenerDato(fila, columna)->esVacio() || mapa.obtenerDato(fila, columna)->obtenerTC() != "Transitable"){
        fila = filaAleatorio(mapa);
        columna = columnaAleatorio(mapa);
    }
    if (cantidad > 0){

        mapa.obtenerDato(fila, columna)->agregarMateriales(new Piedra(cantidad));
        cout << "aparecieron " << cantidad << " piedras en: " << fila << " ," << columna << endl;
    }
}

void Juego::lluviaDeRecursos(Mapa &mapa, Inventario *inventario) {

    srand (time(NULL));
    lluviaDeMadera(mapa, inventario);
    lluviaDeMetal(mapa, inventario);
    lluviaDePiedra(mapa, inventario);

}



/*
void Juego::mostarEdificiosTodos(Ciudad * edificios) {
    // Esta hecho feo, solo funcional
    // PROBANDO 123
    for (int i = 0; i < edificios->cantidadEdificios(); i++) {
        cout << edificios->obtenerEdificio(i)->obtenerNombre() << ": " << edificios->obtenerEdificio(i)->obtenerTotal() << endl;
    } 
}

void Juego::mostrarEdificiosConstruidos(Ciudad * edificios) {
    // Esta hecho feo, solo funcional
    for (int i = 0; i < edificios->cantidadEdificios(); i++) {
        Edificio * edificio =  edificios->obtenerEdificio(i);

        if (edificio->obtenerTotal() != 0) {
            cout << edificio->obtenerNombre() << ": " << edificio->obtenerTotal() << endl;
        }
    } 
}*/