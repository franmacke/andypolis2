#include "parser.h"


Parser::Parser(string entrada) {
    this->entrada = entrada;
}

string Parser::tipo_casillero() {
    return entrada;
}


Casillero * Parser::procesar_entrada() {
    Casillero * casillero;

    if (es_construible()) {
        casillero = new CasilleroInstransitable(tipo_casillero());
    } else if (es_transitable()) {
        casillero = new CasilleroTransitable(tipo_casillero());
    } else if (es_intransitable()) {
        casillero = new CasilleroInaccesible(tipo_casillero());
    }

    return casillero;
}

bool Parser::es_construible() {
    bool respuesta = false;
    if (tipo_casillero() == "M") {
        respuesta = true;
    } else if (tipo_casillero() == "A") {
        respuesta = true;
    } else if (tipo_casillero() == "E") {
        respuesta = true;
    } else if (tipo_casillero() == "F") {
        respuesta = true;
    } else if (tipo_casillero() == "O") {
        respuesta = true;
    } else if (tipo_casillero() == "P") {
        respuesta = true;
    }

    return respuesta;
}

bool Parser::es_transitable() {
    bool respuesta = false;
    if (tipo_casillero() == "W") {
        respuesta = true;
    } else if (tipo_casillero() == "S") {
        respuesta = true;
    } else if (tipo_casillero() == "I") {
        respuesta = true;
    } 

    return respuesta;
}

bool Parser::es_inaccesible() {
    bool respuesta = false;
    if (tipo_casillero() == "L") {
        respuesta = true;
    } 
    return respuesta;
}