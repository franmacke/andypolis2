#ifndef CASILLERO_CONSTRUIBLE_H
#define CASILLERO_CONSTRUIBLE_H

#include <iostream>
#include "casillero.h"
#include "edificio.h"

using namespace std;

class CasilleroIntransitable : public Casillero {

    public:
    CasilleroIntransitable();
    void cambiar_dato(Objeto * dato);
    void convertir(string dato);

};


#endif