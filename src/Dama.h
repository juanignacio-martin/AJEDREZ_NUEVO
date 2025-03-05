#pragma once
#include "Pieza.h"
class Dama :
    public Pieza
{
public:
    Dama(color col)
        :Pieza(tipo_pieza::DAMA, col)
    {}

};