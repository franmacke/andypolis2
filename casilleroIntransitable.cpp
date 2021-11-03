#include "casilleroIntransitable.h"

CasilleroIntransitable::CasilleroIntransitable() {
    this->identificador = "T";
}

void CasilleroIntransitable::cambiar_edificio(Edificio * edificio) {
    this->edificio = edificio;
}