#include "juego.h"

void Juego::cargar_archivos() {
    Archivo archivo;
    materiales = archivo.leer_materiales();
}

void Juego::jugar() {
    cargar_archivos();
    
    
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


void Juego::interfazPrincipal(Mapa &mapa) {

    while (opcion != GUARDAR_Y_SALIR){
        
       mostrarOpciones();
       pedirOpcion();

        switch (opcion) {
            case CONSTRUIR_EDIFICIO_POR_NOMBRE:
                cout << "\n\n\t\t CONSTRUIR EDIFICIO POR NOMBRE \n\n\n";
                break;

            case LISTAR_LOS_EDIFICIOS_CONSTRUIDOS:
                cout << "\n\n\t\t LISTAR LOS EDIFICIOS CONSTRUIDOS \n\n\n";
                break;

            case LISTAR_TODOS_LOS_EDIFICIOS:
                cout << "\n\n\t\t LISTAR TODOS LOS EDIFICIOS \n\n\n";
                break;

            case DEMOLER_UN_EDIFICIO_POR_COORDENADA:
                cout << "\n\n\t\t DEMOLER UN EDIFICIO POR COORDENADA \n\n\n";
                break;

            case MOSTRAR_MAPA:
                cout << "\n\n\t\t MOSTRAR MAPA \n\n\n";
                break;

            case CONSULTAR_COORDENADA:
                cout << "\n\n\t\t CONSULTAR COORDENADA \n\n\n";
                //consultarCoordenada(mapa);
                break;

            case MOSTRAR_INVENTARIO:
                cout << "\n\n\t\t MOSTRAR INVENTARIO \n\n\n";
                //consultarCoordenada(mapa);
                break;

            case RECOLECTAR_RECURSOS_PRODUCIDOS:
                cout << "\n\n\t\t RECOLECTAR RECURSOS PRODUCIDOS \n\n\n";
                break;

            case LLUVIA_DE_RECURSOS:
                cout << "\n\n\t\t LLUVIA DE RECURSOS \n\n\n";
                break;

            case GUARDAR_Y_SALIR:
                cout << "\n\n\t\t GUARDAR Y SALIR \n\n\n";
                break;


            default: cout << " Ingreso una opcion invalida" << endl;

        }
        
    }
}