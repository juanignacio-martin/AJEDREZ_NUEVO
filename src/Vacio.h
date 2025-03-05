#pragma once
#include "Pieza.h"
class Vacio :public Pieza
{
public:

    Vacio(color col)
        :Pieza(tipo_pieza::VACIO, col)
    {}
};