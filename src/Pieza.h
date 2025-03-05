#pragma once
#include"ETSIDI.h"
#include <vector>
#include <iostream>

enum class color { BLANCO, NEGRO };//Define Color
enum class tipo_pieza { TORRE, CABALLO, ALFIL, DAMA, REY, PEON, VACIO };


class Pieza {
public:
    Pieza(tipo_pieza tip = tipo_pieza::VACIO, color col = color::BLANCO)
        : tipo(tip), col(col) {}

    virtual ~Pieza() {}  // Destructor virtual obligatorio para clases base

    virtual void mueve(int x, int y) = 0; // Método puro para hacerla abstracta

    friend std::ostream& operator<<(std::ostream& os, const Pieza& pieza);

protected:
    tipo_pieza tipo;
    color col;
};