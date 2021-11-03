#ifndef CASILLERO_INTRANSITABLE_H
#define CASILLERO_INTRANSITABLE_H

#include <iostream>
#include "casillero.h"

using namespace std;

class CasilleroIntransitable : public Casillero {
    private:
    Edificio * edificio;

    public:
    CasilleroIntransitable();
    void cambiar_edificio(Edificio * edificio);
};


#endif