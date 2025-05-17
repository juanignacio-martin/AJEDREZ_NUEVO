#pragma once
#include "pieza.h"
class rey :  public Pieza
{
public:
    rey(color col, int t, int v)
        :Pieza(tipo_pieza::REY, col, t, v)
    {}
    bool movimiento_valido(int x_origen, int y_origen, int x_destino, int y_destino, Pieza*** tablero) const;
};

