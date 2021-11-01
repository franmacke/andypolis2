#include "juego.h"

void Juego::cargar_archivos() {
    Archivo archivo;
    materiales = archivo.leer_materiales();
}

void Juego::jugar() {
    cargar_archivos();
    
    
}