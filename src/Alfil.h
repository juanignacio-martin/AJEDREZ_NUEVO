#pragma once
#include "Pieza.h"

class Alfil:public Pieza
{
public:
    Alfil(color col)
        :Pieza(tipo_pieza::ALFIL, col)
    {}
    
};