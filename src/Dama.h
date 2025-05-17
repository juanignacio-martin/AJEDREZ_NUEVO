#pragma once
#include "pieza.h"
class dama :public Pieza
{
public:
    dama(color col, int t, int v)
        :Pieza(tipo_pieza::DAMA, , col, t, v)
    {}
    bool movimiento_valido(int x_origen, int y_origen, int x_destino, int y_destino, Pieza*** tablero) const;

};

