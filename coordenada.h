#ifndef COORDENADA_H
#define COORDENADA_H

class Coordenada
{
    private:
    int coordenada_x;
    int coordenada_y;

    public:
    Coordenada(int x, int y);
    int x();
    int y();
    void cambiar_x(int x);
    void cambiar_y(int y);

};


#endif