#include "casilleroIntransitable.h"

CasilleroIntransitable::CasilleroIntransitable() {
    this->identificador = "T";
}

void CasilleroIntransitable::cambiar_dato(string dato) {
    Parser parser = Parser(dato);
    this->edificio = parser.crear_edificio();
}