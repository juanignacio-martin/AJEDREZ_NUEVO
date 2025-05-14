#pragma once
#include "pieza.h"
class rey :  public Pieza
{
public:
    rey(color col)
        :Pieza(tipo_pieza::REY, col)
    {}
    bool movimiento_valido(int x_origen, int y_origen, int x_destino, int y_destino, Pieza*** tablero, color jugadorColor) const;
};

