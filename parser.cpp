#include "parser.h"

Parser::Parser(string entrada, int cantidad) {
    // Para materiales
    this->entrada = entrada;
    this->cantidad = cantidad;
}


Parser::Parser(string entrada) {
    this->entrada = entrada;
}

int Parser::cantidad_entrada() {
    return cantidad;
}

string Parser::tipo_casillero() {
    return entrada;
}

/*
Casillero * Parser::procesar_entrada() {
    Casillero * casillero;

    if (es_construible()) {
        casillero = new CasilleroConstruible();
    } else if (es_transitable()) {
        casillero = new CasilleroTransitable();
    } else if (es_inaccesible()) {
        casillero = new CasilleroInaccesible();
    }

    return casillero;
}
*/
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
/*
Objeto * Parser::crear_dato() {
    Objeto * objeto;

    if (tipo_casillero() == "mina") {
        objeto = new Mina();
    } else if (tipo_casillero() == "aserradero") {
        objeto = new Aserradero();
    } else if (tipo_casillero() == "escuela") {
        objeto = new Escuela();
    } else if (tipo_casillero() == "fabrica") {
        objeto = new Fabrica();
    } else if (tipo_casillero() == "obelisco") {
        objeto = new Obelisco();
    } else if (tipo_casillero() == "planta") {
        objeto = new Planeta();
    } else if (tipo_casillero() == "madera") {
        objeto = new MaterialRecogible("madera", cantidad_entrada());
    } else if (tipo_casillero() == "metal") {
        objeto = new MaterialRecogible("metal", cantidad_entrada());
    } else if (tipo_casillero() == "piedra") {
        objeto = new MaterialRecogible("piedra", cantidad_entrada());
    }

    return objeto;
}

*/

// MaterialRecogible * Parser::crear_material() {
//     MaterialRecogible * material;
   
//     if (tipo_casillero() == "W") {
//         material = new MaterialRecogible("madera", cantidad_entrada());
//     } else if (tipo_casillero() == "M") {
//         material = new MaterialRecogible("metal", cantidad_entrada());
//     } else if (tipo_casillero() == "S") {
//         material = new MaterialRecogible("piedra", cantidad_entrada());
//     }
    
//     return material;
// }

