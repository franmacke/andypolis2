#ifndef CASILLERO_TRANSITABLE_H
#define CASILLERO_TRANSITABLE_H
#include "casillero.h"
#include "material.h"

const string TRANSITABLE = "transitable";

using namespace std;
class CasilleroTransitable : public Casillero {
    protected:
    Material * material;

    public:
    CasilleroTransitable(){this->vacio = true;
        this->tipoCasillero = TRANSITABLE; this->material = nullptr;}

    void agregarMateriales(Material* material){ this->material = material;
        this->vacio = false;}

    void recolectarmaterial(){this->vacio = true;}

    void agregarEdificio(Edificio* edificio){}
    
    void mostrarEnMapa();

    void eliminarEdificio() {}

    void eliminarObjeto() { this->material = nullptr; this->vacio = true;}

    string obtenerNombre(){return this->material->obtenerNombre();}

    void liberarMemoria() {
        if (material != nullptr) {
            delete material;
        }
    }

    ~CasilleroTransitable();
};


#endif //ANDYPOLIS2_CASILLEROCONSTRUIBLE_H
