#pragma once
#include "pieza.h"
#include <iostream>

class torre : public Pieza {
public:
    torre(color col) : Pieza(tipo_pieza::TORRE, col) {}  

    void mueve(int x, int y) override;
};
