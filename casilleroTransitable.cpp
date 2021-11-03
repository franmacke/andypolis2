//
// Created by ydsas on 3/11/2021.
//

#include "casilleroTransitable.h"

CasilleroTransitable::CasilleroTransitable() {
    material = 0;
    this->identificador = "C";
}

void CasilleroTransitable::cambiar_dato(string dato) {
    Parser parser = Parser(dato);
    this->material = parser.crear_material();
}