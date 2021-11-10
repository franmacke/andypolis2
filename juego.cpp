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

    while (fila >= mapa.filaMapa() || fila < 0){
        cout << "\t\tFila ingresada esta mal, intentalo de nuevo: ";
        cin >> fila;
    }
    return fila;
}

int Juego::pedirColumna(Mapa& mapa) {
    int columna;
    cout << "\t\tIngrese el numero de columna: ";
    cin >> columna;
    while (columna >= mapa.columnaMapa() || columna < 0){
        cout << "\t\tColumna ingresada esta mal, intentalo de nuevo: ";
        cin >> columna;
    }
    return columna;
}

bool Juego::pedirConfirmacion() {
    string opcion;
    Utilidad utilidad;
    bool respuesta = false;
    cout << "Esta seguro que queres proceder? [si/no]" << endl;
    cin >> opcion;

    while (utilidad.minuscula(opcion) != "si" && utilidad.minuscula(opcion) != "no" ) {
        cout << "Ingreso invalido. Ingrese si o no: ";
        cin >> opcion;
    }

    return utilidad.minuscula(opcion) == "si"; 
}

void Juego::interfazPrincipal(Mapa &mapa, Ciudad* ciudad, Ciudad* edificiosConstruidos , Inventario* inventario) {

    while (opcion < GUARDAR_Y_SALIR){//aca quizas hay q corregir
        
       mostrarOpciones();
       pedirOpcion();

        switch (opcion) {
            case CONSTRUIR_EDIFICIO_POR_NOMBRE:
                cout << "\n\n\t\t CONSTRUIR EDIFICIO POR NOMBRE \n\n\n";
                construirEdificioPorNombre(mapa, ciudad, edificiosConstruidos, inventario);
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
                demolerEdificio(mapa, ciudad, edificiosConstruidos, inventario);
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
                recolectarMateriales(mapa, inventario, ciudad);
                break;

            case LLUVIA_DE_RECURSOS:
                cout << "\n\n\t\t LLUVIA DE RECURSOS \n\n\n";
                lluviaDeRecursos(mapa);
                break;

            case GUARDAR_Y_SALIR:
                cout << "\n\n\t\t GUARDAR Y SALIR \n\n\n";
                guardarYSalir(mapa, ciudad, inventario);
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

    for (int i = 0; i < ciudad->cantidadEdificios(); ++i) {
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

    for (int i = 0; i < ciudad->cantidadEdificios(); ++i) {

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
    return rand() % 3 + 2;
}

int Juego::cantAleatoriaPiedra() {
    return rand() % 2 + 1;
}

void Juego::lluviaDeMadera(Mapa &mapa) {

    int fila = filaAleatorio(mapa);
    int columna = columnaAleatorio(mapa);
    int cantidad = cantAleatoriaMadera();
    //cout << fila << " " << columna << endl;
    while (!mapa.obtenerDato(fila, columna)->esVacio() || mapa.obtenerDato(fila, columna)->obtenerTC() != "Transitable"){
        fila = filaAleatorio(mapa);
        columna = columnaAleatorio(mapa);
    }
    if (cantidad > 0){

        mapa.obtenerDato(fila, columna)->agregarMateriales(new Madera(fila, columna, cantidad));
        cout << "aparecieron " << cantidad << " maderas en: " << fila << " ," << columna << endl;
    }
}


void Juego::lluviaDeMetal(Mapa &mapa) {

    int fila = filaAleatorio(mapa);
    int columna = columnaAleatorio(mapa);
    int cantidad = cantAleatoriaMetal();
    //cout << fila << " " << columna << endl;
    while (!mapa.obtenerDato(fila, columna)->esVacio() || mapa.obtenerDato(fila, columna)->obtenerTC() != "Transitable"){
        fila = filaAleatorio(mapa);
        columna = columnaAleatorio(mapa);
    }
    if (cantidad > 0){

        mapa.obtenerDato(fila, columna)->agregarMateriales(new Metal(fila, columna, cantidad));
        cout << "aparecieron " << cantidad << " metales en: " << fila << " ," << columna << endl;
    }
}


void Juego::lluviaDePiedra(Mapa &mapa) {

    int fila = filaAleatorio(mapa);
    int columna = columnaAleatorio(mapa);
    int cantidad = cantAleatoriaPiedra();
    //cout << fila << " " << columna << endl;
    while (!mapa.obtenerDato(fila, columna)->esVacio() || mapa.obtenerDato(fila, columna)->obtenerTC() != "Transitable"){
        fila = filaAleatorio(mapa);
        columna = columnaAleatorio(mapa);
    }
    if (cantidad > 0){

        mapa.obtenerDato(fila, columna)->agregarMateriales(new Piedra(fila, columna, cantidad));
        cout << "aparecieron " << cantidad << " piedras en: " << fila << " ," << columna << endl;
    }
}

void Juego::lluviaDeRecursos(Mapa &mapa) {

    srand (time(NULL));
    lluviaDeMadera(mapa);
    lluviaDeMetal(mapa);
    lluviaDePiedra(mapa);

}


int Juego::cantProducidoPorAserradero(Ciudad *ciudad) {
    for (int i = 0; i < ciudad->cantidadEdificios(); ++i) {

        //cout << ciudad->obtenerEdificio(i)->obtenerNombre() << endl;
        if (ciudad->obtenerEdificio(i)->obtenerNombre() == "Aserradero"){
            cout << ciudad->obtenerEdificio(i)->obtenerTotal() << endl;
            return (ciudad->obtenerEdificio(i)->obtenerTotal() * 25);
        }
    }
}

int Juego::cantProducidoPorFabrica(Ciudad *ciudad) {
    for (int i = 0; i < ciudad->cantidadEdificios(); ++i) {

        //cout << ciudad->obtenerEdificio(i)->obtenerNombre() << endl;
        if (ciudad->obtenerEdificio(i)->obtenerNombre() == "Fabrica"){
            cout << ciudad->obtenerEdificio(i)->obtenerTotal() << endl;
            return (ciudad->obtenerEdificio(i)->obtenerTotal() * 40);
        }
    }
}


int Juego::cantProducidoPorMina(Ciudad *ciudad) {
    for (int i = 0; i < ciudad->cantidadEdificios(); ++i) {

        //cout << ciudad->obtenerEdificio(i)->obtenerNombre() << endl;
        if (ciudad->obtenerEdificio(i)->obtenerNombre() == "Mina"){
            cout << ciudad->obtenerEdificio(i)->obtenerTotal() << endl;
            return (ciudad->obtenerEdificio(i)->obtenerTotal() * 15);
        }
    }
}



void Juego::recolectarMateriales(Mapa &mapa, Inventario *inventario, Ciudad* ciudad) {

    int cantParaSumar = 0;
    for (int i = 0; i < inventario->cantidad_materiales(); ++i) {

        cantParaSumar = 0;
        if (inventario->obtenerMaterial(i)->obtenerNombre() == "Madera"){
            cantParaSumar = cantProducidoPorAserradero(ciudad);
            cout << cantParaSumar << endl;
            inventario->obtenerMaterial(i)->aumentarTotal(cantParaSumar);
            cout<< inventario->obtenerMaterial(i)->obtenerNombre() << endl;
            cantParaSumar = 0;
        } else if(inventario->obtenerMaterial(i)->obtenerNombre() == "Metal"){
            cantParaSumar = cantProducidoPorFabrica(ciudad);
            cout << cantParaSumar << endl;
            inventario->obtenerMaterial(i)->aumentarTotal(cantParaSumar);
            cout<< inventario->obtenerMaterial(i)->obtenerNombre() << endl;
            cantParaSumar = 0;
        } else if(inventario->obtenerMaterial(i)->obtenerNombre() == "Piedra") {
            cantParaSumar = cantProducidoPorMina(ciudad);
            cout << cantParaSumar << endl;
            inventario->obtenerMaterial(i)->aumentarTotal(cantParaSumar);
            cout<< inventario->obtenerMaterial(i)->obtenerNombre() << endl;
            cantParaSumar = 0;
        }

    }
}

Edificio * Juego::pedirNombreEdificio(Ciudad* datosEdificios) {
    Utilidad utilidad;
    string nombre;

    cout << "Ingrese el nombre del edificio que desea construir: ";
    cin >> nombre;

    Edificio * edificioBuscado = nullptr;
    edificioBuscado = datosEdificios->buscarEdificioPorNombre(nombre);

    while (edificioBuscado == nullptr && nombre != "fin") {
        cout << "No se encontro el edificio ingresado. Intente de nuevo: ";
        cin >> nombre;
        edificioBuscado = datosEdificios->buscarEdificioPorNombre(nombre);
    }

    // Devuelve nullptr o FIN
    return edificioBuscado;
}


bool Juego::esCasilleroConstruible(Mapa& mapa, int fila, int columna) {
    Utilidad utilidad;
    bool vacio = true;
    bool esConstruible = true;

    if (utilidad.minuscula(mapa.obtenerDato(fila, columna)->obtenerTC()) != "construible") {
        cout << "El casillero (" << fila << ", " << columna << ") no es de tipo construible" << endl;
        esConstruible = false;
    }

    if(!mapa.obtenerDato(fila, columna)->esVacio() && esConstruible) {
        cout << "El casillero (" << fila << ", " << columna << ") no esta vacio." << endl;
        vacio = false;
    }

    return vacio && esConstruible;
}

bool Juego::esCasilleroDemolible(Mapa& mapa, int fila, int columna) {
    Utilidad utilidad;
    bool vacio = true;
    bool esConstruible = true;

    if (utilidad.minuscula(mapa.obtenerDato(fila, columna)->obtenerTC()) != "construible") {
        cout << "El casillero (" << fila << ", " << columna << ") no es de tipo construible" << endl;
        esConstruible = false;
    }

    if(mapa.obtenerDato(fila, columna)->esVacio() && esConstruible) {
        cout << "El casillero (" << fila << ", " << columna << ") esta vacio." << endl;
        vacio = false;
    }

    return vacio && esConstruible;
}

// void Juego::demolerEdificio(Mapa &mapa, Ciudad* edificiosConstruidos) {
//     int fila = pedirFila(mapa);
//     int columna = pedirColumna(mapa);

//     if (esCasilleroDemolible(mapa, fila, columna)) {
//         Utilidad util;
//         string edificioParaDestruir = mapa.obtenerDato(fila, columna)->obtenerNombre();
//         cout << "Se demolio el edificio " << edificioParaDestruir << " en las coordenadas (" << fila << ", " << columna << ")." << endl;
//         mapa.baja(fila, columna);
//         edificiosConstruidos->eliminarPorCoordenadas(fila, columna);
//     }       
// }

void Juego::demolerEdificio(Mapa &mapa, Ciudad* datosEdificios, Ciudad* edificiosConstruidos, Inventario * inventario) {
    Utilidad util;

    int fila = pedirFila(mapa);
    int columna = pedirColumna(mapa);

    if (esCasilleroDemolible(mapa, fila, columna)) {
        // Busco el edificio en construidos
        Edificio * edificioParaDemoler = edificiosConstruidos->buscarEdificioPorCoordenadas(fila, columna);
        // Necesito datos del edificio
        Edificio * datoEdificio = datosEdificios->buscarEdificioPorNombre(edificioParaDemoler->obtenerNombre());
        // Mensaje
        cout << "Se demolio el edificio " << edificioParaDemoler->obtenerNombre() << " en las coordenadas (" << fila << ", " << columna << ")." << endl;
        // Elimino a mapa
        mapa.baja(fila, columna);
        // Elimino a vector construidos
        edificiosConstruidos->eliminarPorCoordenadas(fila, columna);
        // Saco materiales del inventario
        inventario->demolerEdificio(datoEdificio);
    }
}

// void Juego::construirEdificio(Mapa &mapa, Ciudad* datosEdificios, Ciudad* edificiosConstruidos, Edificio * edificio, Inventario * inventario) {
//     int fila = pedirFila(mapa);
//     int columna = pedirColumna(mapa);

//     if (esCasilleroConstruible(mapa)) {
//         Utilidad util;
//         string nombre = edificio->obtenerNombre();
//         nombre = util.minuscula(nombre);

//         Edificio * edificioConstruido = crearEdificio(nombre, fila, columna);
//         mapa.obtenerDato(fila, columna)->agregarEdificio(edificioConstruido);
//         edificiosConstruidos->agregarEdificio(edificioConstruido);
//         cout << "Se agrego el edificio " << edificioConstruido->obtenerNombre() << " en las coordenadas (" << fila << ", " << columna << ")." << endl;
//     }              
// }

void Juego::constuirEdificio(Mapa &mapa, Edificio* datosEdificio, Ciudad* edificiosConstruidos, Inventario * inventario) {
    Utilidad util;

    int fila = pedirFila(mapa);
    int columna = pedirColumna(mapa);

    if (esCasilleroConstruible(mapa, fila, columna)) {
        // Creo el edificio
        Edificio * edificioConstruido = crearEdificio(util.minuscula(datosEdificio->obtenerNombre()), fila, columna);
        // Agrego a mapa
        mapa.obtenerDato(fila, columna)->agregarEdificio(edificioConstruido);
        // Agrego a vector construidos
        edificiosConstruidos->agregarEdificio(edificioConstruido);
        // Saco materiales del inventario
        inventario->construirEdificio(datosEdificio);
        
        cout << "Se agrego el edificio " << edificioConstruido->obtenerNombre() << " en las coordenadas (" << fila << ", " << columna << ")." << endl;
    }
}


void Juego::construirEdificioPorNombre(Mapa &mapa, Ciudad * datosEdificios, Ciudad * edificiosConstruidos, Inventario * inventario) {
    Edificio * edificioBuscado = pedirNombreEdificio(datosEdificios);

    if (edificioBuscado) {
        cout << "Se encontro el edificio " << edificioBuscado->obtenerNombre() << "." << endl;
    
        if (comprobarMateriales(edificioBuscado, inventario) && 
        comprobarCantidadMaxima(edificioBuscado) && 
        pedirConfirmacion()) {
            
            constuirEdificio(mapa, edificioBuscado, edificiosConstruidos, inventario);
            // construirEdificio(mapa, datosEdificios, edifciosConstruidos, edificioBuscado, inventario);
        } 
        else {
            cout << "Se cancelo la construccion del edificio.";
        }

    } else {
        cout << "Se cancelo la construccion del edificio.";
    }

}

bool Juego::comprobarCantidadMaxima(Edificio* edificio) {
    bool esConstruible = false;
    if (edificio->obtenerTotal() + 1 <= edificio->obtenerTope()) {
        esConstruible = true;
    } else {
        cout << "Ya tenes la cantidad maxima del edicicio " << edificio->obtenerNombre() << "." << endl;
    }

    return esConstruible;
}

bool Juego::comprobarCantidadMinima(Edificio* edificio) {
    bool esDemolible = false;
    if (edificio->obtenerTotal() - 1 >= 0) {
        esDemolible = true;
    } else {
        cout << "Ya no tenes mas edificios de " << edificio->obtenerNombre() << " para destruir." << endl;
    }

    return esDemolible;
}

bool Juego::comprobarMateriales(Edificio * edificio, Inventario * inventario) {
    bool madera = true;
    bool metal = true;
    bool piedra = true;

    if (edificio->obtenerMadera() > inventario->obtenerMadera()) {
        cout << "No tenes suficiente madera." << endl;
        cout << "Tenes " << inventario->obtenerMadera() << " y necesitas " << edificio->obtenerMadera() << endl;
        madera = false;
    }
    if (edificio->obtenerMetal() > inventario->obtenerMetal()) {
        cout << "No tenes suficiente metal." << endl;
        cout << "Tenes " << inventario->obtenerMetal() << " y necesitas " << edificio->obtenerMetal() << endl;
        metal = false;
    }
    if (edificio->obtenerPiedra() > inventario->obtenerPiedra()) {
        cout << "No tenes suficiente piedra." << endl;
        cout << "Tenes " << inventario->obtenerPiedra() << " y necesitas " << edificio->obtenerPiedra() << endl;
        piedra = false;
    }

    return (piedra && madera && metal);
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




void Juego::guardarYSalir(Mapa &mapa, Ciudad* ciudad, Inventario *inventario) {
    guardarArchivoMateriales(inventario);
    //guardarArchivoUbicaciones(mapa, ciudad);
}


void Juego::guardarArchivoMateriales(Inventario *inventario) {

    ofstream archivo;
    archivo.open(PATH_MATERIALES);
    int cantidadMateriales = inventario->cantidad_materiales();
    for (int i = 0; i < cantidadMateriales; ++i) {

        archivo << inventario->obtenerMaterial(i)->obtenerNombre() << " " << inventario->obtenerMaterial(i)->obtenerTotal() << '\n';

        delete inventario->obtenerMaterial(i);
        inventario->sacarMateriales();

    }
    inventario->liberarMemoria();
    archivo.close();

}

/*
void Juego::guardarArchivoUbicaciones(Mapa &mapa, Ciudad* ciudad) {
    ofstream archivo;
    archivo.open(PATH_UBICACIONES);

    for (int i = 0; i < ciudad->cantidadEdificios(); ++i) {

        if (ciudad->obtenerEdificio(i)->obtenerTotal() > 0){
            //cout << "Tipo de edificio: " << ciudad->obtenerEdificio(i)->obtenerNombre() << endl;
            archivo << ciudad->obtenerEdificio(i)->obtenerNombre() << " (" << mapa.<< ", " << ciudad->obtenerEdificio(i)->obtenerColumna() << ")" << '\n';

        }
        delete ciudad->obtenerEdificio(i);
        ciudad->sacarEdificio();
    }
    ciudad->liberarMemoria();
    archivo.close();
}
*/



Edificio* Juego::crearEdificio(string nombre, int fila, int columna) {

        Edificio * nuevo;

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

