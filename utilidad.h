#ifndef UTILIDAD_H
#define UTILIDAD_H

#include <iostream>

using namespace std;

const int CONSTRUIR_EDIFICIO_POR_NOMBRE = 1;
const int LISTAR_LOS_EDIFICIOS_CONSTRUIDOS = 2;
const int LISTAR_TODOS_LOS_EDIFICIOS = 3;
const int DEMOLER_UN_EDIFICIO_POR_COORDENADA = 4;
const int MOSTRAR_MAPA = 5;
const int CONSULTAR_COORDENADA = 6;
const int MOSTRAR_INVENTARIO = 7;
const int RECOLECTAR_RECURSOS_PRODUCIDOS = 8;
const int LLUVIA_DE_RECURSOS = 9;
const int GUARDAR_Y_SALIR = 10;

const int CANTIDAD_TIPOS_EDIFICIOS = 6;
const int CANTIDAD_TIPO_MATERIALES = 4;

class Utilidad {
    public:
    string minuscula(string palabra);
    string mayuscula(string palabra);
    string capitalizar(string palabra);
    bool es_numero(string numero);
    bool confirmar_operacion();
};


#endif