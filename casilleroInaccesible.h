//
// Created by ydsas on 3/11/2021.
//

#ifndef CASILLERO_INACCESIBLE_H
#define CASILLERO_INACCESIBLE_H
#include "casillero.h"

class CasilleroInaccesible : public Casillero {
    private:
    
    public:
    CasilleroInaccesible(){this->vacio = true;
        this->tipoCasillero = "Inaccesible";};
    //void cambiar_dato(Objeto * dato);
    void mostrarEnMapa(){cout << COLOR_AZUL<< EMOJI_LAGO ;}// estaria bueno en colores en vez de una letra

    void agregarEdificio(Edificio* edificio){}

    void eliminarEdificio() {}

    void eliminarObjeto() {}

    void agregarMateriales(Material* material){}

    string obtenerNombre(){return "";}

    void liberarMemoria() {}

};


#endif //ANDYPOLIS2_CASILLEROCONSTRUIBLE_H
