#ifndef OBJETO_H
#define OBJETO_H

#include <iostream>

using namespace std;

class Objeto {
    private:
    string identificador;

    public:
    Objeto();
    Objeto(string identificador);
    void setear_id(string id);
    string id();
};

#endif