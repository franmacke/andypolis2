#ifndef CASILLERO_INACCESIBLE_H
#define CASILLERO_INACCESIBLE_H
#include "casillero.h"

const string INACCESIBLE = "inaccesible";

class CasilleroInaccesible : public Casillero {
    private:
    
    public:
    CasilleroInaccesible(){this->vacio = true;
        this->tipoCasillero = INACCESIBLE;};

    void mostrarEnMapa(){cout << "L";}

    void agregarEdificio(Edificio* edificio){}

    void eliminarEdificio() {}

    void eliminarObjeto() {}

    void agregarMateriales(Material* material){}

    string obtenerNombre(){return "";}

    void liberarMemoria() {}

};

#endif //ANDYPOLIS2_CASILLEROCONSTRUIBLE_H
