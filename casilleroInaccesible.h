//
// Created by ydsas on 3/11/2021.
//

#ifndef CASILLERO_INACCESIBLE_H
#define CASILLERO_INACCESIBLE_H
#include "casillero.h"

class CasilleroInaccesible : public Casillero {
    private:
    Objeto * dato;
    
    public:
    //CasilleroInaccesible();
    //void cambiar_dato(Objeto * dato);
    void mostrarEnMapa(){cout << "L";}// estaria bueno en colores en vez de una letra
};


#endif //ANDYPOLIS2_CASILLEROCONSTRUIBLE_H
