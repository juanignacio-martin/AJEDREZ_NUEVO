#pragma once
#include "pieza.h"
class caballo :public Pieza
{
public:
    caballo(color col)
        :Pieza(tipo_pieza::CABALLO, col)
    {}
    void mueve(int x, int y) override;
};

