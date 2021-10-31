#ifndef DIMENSION_H
#define DIMENSION_H

#include <iostream>

using namespace std;

class Dimension {
    private:
    int alto;
    int ancho;

    public:
    Dimension();
    Dimension(int alto, int ancho);
    int obtener_alto();
    int obtener_ancho();
    void setear_alto(int ancho);
    void setear_ancho(int alto);
    bool es_valida();

};

#endif

