//
// Created by ydsas on 3/11/2021.
//

#ifndef CASILLERO_TRANSITABLE_H
#define CASILLERO_TRANSITABLE_H
#include "casillero.h"
#include "material.h"

using namespace std;
class CasilleroTransitable : public Casillero {
    protected:
    Material * material;

    public:
    CasilleroTransitable(){this->vacio = true;
        this->tipoCasillero = "Transitable"; this->material = nullptr;}
    //void cambiar_dato(Objeto * dato);

    void agregarMateriales(Material* material){ this->material = material;
        this->vacio = false;}

    void recolectarmaterial(){this->vacio = true;}

    void agregarEdificio(Edificio* edificio){}
    void mostrarEnMapa();// estaria bueno en colores en vez de una letra

    void eliminarEdificio() {}

    string obtenerNombre(){return this->material->obtenerNombre();}

    ~CasilleroTransitable();
};


#endif //ANDYPOLIS2_CASILLEROCONSTRUIBLE_H
