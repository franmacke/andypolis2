#ifndef UTILIDAD_H
#define UTILIDAD_H

#include <iostream>
#include <ctime>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>

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



const string EMOJI_CIUDAD = "\U0001f301";
const string EMOJI_EDIFICIO = "\U0001f3e2";
const string EMOJI_PERSONA = "\U0001f477";
const string EMOJI_OBRA = "\U0001f6a7";
const string EMOJI_LISTA = "\U0001f4c4";
const string EMOJI_MAPA = "\U0001f5fa";
const string EMOJI_BRUJULA = "\U0001f9ed";
const string EMOJI_CAMION = "\U0001f69b";
const string EMOJI_TARJETA = "\U0001f4be";
const string EMOJI_TRACTOR = "\U0001f69c";
const string EMOJI_LLUVIA = "\U0001f327";
const string EMOJI_MINA = "\u26CF";
const string EMOJI_ASERRADERO = "\U0001fa93";
const string EMOJI_FABRICA = "\U0001f3ed";
const string EMOJI_ESCUELA = "\U0001f3eb";
const string EMOJI_PLANTA = "\U0001f50b";
const string EMOJI_OBELISCO = "\U0001f3db";
const string EMOJI_LAGO = "\U0001f7e6";
const string EMOJI_TERRENO = "\U0001f7e9";
const string EMOJI_CALLE = "\U0001f7eb";
const string EMOJI_PIEDRA = "\u26F0";
const string EMOJI_MADERA = "\U0001f332";
const string EMOJI_METAL = "\U0001f529";
const string COLOR_ROJO = "\e[0;31m";
const string COLOR_BLANCO = "\x1b[37m";
const string COLOR_VERDE = "\x1b[32m";
const string COLOR_AZUL = "\x1b[34m";
const std::string COLOR_POR_DEFECTO  = "\e[0m";
const std::string COLOR_DORADO = "\x1b[33m";


class Utilidad {
    public:
    string minuscula(string palabra);
    string mayuscula(string palabra);
    string capitalizar(string palabra);
    bool es_numero(string numero);
    bool confirmar_operacion();
};


#endif