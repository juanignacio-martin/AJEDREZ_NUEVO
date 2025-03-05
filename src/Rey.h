#pragma once
#include "pieza.h"
class rey :  public Pieza
{
public:
    rey(color col)
        :Pieza(tipo_pieza::REY, col)
    {}
    void mueve(int x, int y) override;
};

