#pragma once
#include "pieza.h"

class alfil : public Pieza {
public:
    alfil(color col) : Pieza(tipo_pieza::ALFIL, col) {}
    void mueve(int x, int y) override;
};
