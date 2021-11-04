#include "casilleroIntransitable.h"

CasilleroIntransitable::CasilleroIntransitable() {
    this->identificador = "T";
    this->dato = 0;
}

void CasilleroIntransitable::cambiar_dato(Objeto * dato) {
    this->dato = dato;
    // this->identificador = dato->id();
}
