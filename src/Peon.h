#pragma once
#include "pieza.h"
class peon : public Pieza
{
public:
    peon(color col)
        :Pieza(tipo_pieza::PEON, col)
    {}
/*    void mueve(int x, int y)override {
        std::cout << "muevo el peon" << x<<y<<std::endl;
    }*/

    void mueve(int x, int y) override;
};

