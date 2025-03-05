#pragma once
#include "Pieza.h"
class Rey :  public Pieza
{
public:
    Rey(color col)
        :Pieza(tipo_pieza::REY, col)
    {}

};