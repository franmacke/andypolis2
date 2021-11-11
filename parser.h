#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include "casilleroTransitable.h"
#include "casilleroConstruible.h"
#include "casilleroInaccesible.h"
#include "mina.h"
#include "aserradero.h"
#include "escuela.h"
#include "fabrica.h"
#include "obelisco.h"
#include "planta.h"
#include "yacimiento.h"
#include "material.h"
#include "madera.h"
#include "piedra.h"
#include "metal.h"
#include "oro.h"
#include "objeto.h"

using namespace std;

class Parser {
    private:
    string entrada;
    int cantidad;

    public:
    Parser(string entrada);
    Parser(string entrada, int cantidad);
    Casillero * procesar_entrada();
    string tipo_casillero();
    int cantidad_entrada();
    bool es_inaccesible();
    bool es_transitable();
    bool es_construible();

    Objeto * crear_dato();

};


#endif