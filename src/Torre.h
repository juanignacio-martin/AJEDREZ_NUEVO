#pragma once
#include "Pieza.h"
class Torre :   public Pieza
{
public:
    Torre(color col)
        :Pieza(tipo_pieza::TORRE, col)
    {}

};