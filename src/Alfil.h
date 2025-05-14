#pragma once
#include "pieza.h"

class alfil : public Pieza {
public:
    alfil(color col) : Pieza(tipo_pieza::ALFIL, col) {}

    bool movimiento_valido(int x_origen, int y_origen, int x_destino, int y_destino, Pieza*** tablero) const;

};
