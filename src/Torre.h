#pragma once
#include "pieza.h"
#include <iostream>

class torre : public Pieza {

    static int modo_juego; // 0 = Silverman/Demi, 1 = Clásico

public:
    torre(color col) : Pieza(tipo_pieza::TORRE, col) {}  

    bool movimiento_valido(int x_origen, int y_origen, int x_destino, int y_destino, Pieza*** tablero, color jugadorColor) const;
};
