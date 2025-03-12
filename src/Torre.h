#pragma once
#include "pieza.h"
#include <iostream>

class torre : public Pieza {
public:
    torre(color col) : Pieza(tipo_pieza::TORRE, col) {}  

    bool movimiento_valido(int x_origen, int y_origen, int x_destino, int y_destino, Pieza*** tablero) const;
};
