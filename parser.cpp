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
        casillero = new CasilleroConstruible();
    } else if (es_transitable()) {
        casillero = new CasilleroNoConstruible();
    } else if (es_inaccesible()) {
        casillero = new CasilleroInaccesible();
    }

    return casillero;
}

bool Parser::es_construible() {
    bool respuesta = false;
    
    if (tipo_casillero() == "T") {
        respuesta = true;
    }

    return respuesta;
}

bool Parser::es_transitable() {
    bool respuesta = false;
    if (tipo_casillero() == "C") {
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

Edificio * Parser::crear_edificio() {
    Edificio * edificio;
    if (tipo_casillero() == "M") {
        edificio = new Mina();
    } else if (tipo_casillero() == "A") {
        edificio = new Aserradero();
    } else if (tipo_casillero() == "E") {
        edificio = new Escuela();
    } else if (tipo_casillero() == "F") {
        edificio = new Fabrica();
    } else if (tipo_casillero() == "O") {
        edificio = new Obelisco();
    } else if (tipo_casillero() == "P") {
        edificio = new Planeta();
    }

    return edificio;
}

Material * Parser::crear_material() {
    Material * material;
   
    if (tipo_casillero() == "W") {
        material = new MaterialRecogible();
    } //FALTAN CASOS
   
}