#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include "casillero.h"
#include "casilleroTransitable.h"
#include "casilleroIntransitable.h"
#include "casilleroInaccesible.h"
#include "mina.h"
#include "aserradero.h"
#include "escuela.h"
#include "fabrica.h"
#include "obelisco.h"
#include "planeta.h"

using namespace std;

class Parser {
    private:
    string entrada;

    public:
    Parser(string entrada);
    Casillero * procesar_entrada();
    string tipo_casillero();
    bool es_inaccesible();
    bool es_transitable();
    bool es_construible();
    Edificio * crear_edificio();
    Material * crear_material();
};


#endif