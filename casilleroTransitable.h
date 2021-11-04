//
// Created by ydsas on 3/11/2021.
//

#ifndef CASILLERO_TRANSITABLE_H
#define CASILLERO_TRANSITABLE_H
#include "casillero.h"
//#include "material.h"

class CasilleroTransitable : public Casillero {
    protected:
    Objeto * material; 

    public:
    CasilleroTransitable();
    void cambiar_dato(Objeto * dato);
    // virtual void mostrarEnMapa(){cout << "C ";}// estaria bueno en colores en vez de una letra
};


#endif //ANDYPOLIS2_CASILLEROCONSTRUIBLE_H
