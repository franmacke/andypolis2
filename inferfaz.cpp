#include "interfaz.h"

#ifdef _WIN32
    #include <Windows.h>
    const char* CLEAR_SCREEN = "cls";
    const char* PAUSA = "pause";
#else
    #include <unistd.h>
    const char* CLEAR_SCREEN = "clear";
    const char* PAUSA = "read -p 'Toca una tecla para continuar...' var";
#endif


void Interfaz::menu() {
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

void Interfaz::pausa() {
    system(PAUSA);
}

void Interfaz::limpiar() {
    system(CLEAR_SCREEN);
}

void Interfaz::dormir(unsigned int tiempo){
    #ifdef _WIN32
        Sleep((DWORD) tiempo);
    #else
        usleep(tiempo);
    #endif
}
