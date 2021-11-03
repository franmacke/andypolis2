#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include "casillero.h"


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
};


#endif