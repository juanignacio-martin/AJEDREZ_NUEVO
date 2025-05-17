#pragma once
#include "pieza.h"

class alfil : public Pieza {
public:
    alfil(color col, int t, int v) : Pieza(tipo_pieza::ALFIL, t, v) {}

    bool movimiento_valido(int x_origen, int y_origen, int x_destino, int y_destino, Pieza*** tablero) const;

};
