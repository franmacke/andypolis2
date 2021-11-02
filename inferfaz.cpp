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
