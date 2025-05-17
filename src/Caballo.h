#pragma once
#include "pieza.h"
class caballo :public Pieza
{
public:
    caballo(color col, int t, int v)
        :Pieza(tipo_pieza::CABALLO, col, t, v)
    {}
    bool movimiento_valido(int x_origen, int y_origen, int x_destino, int y_destino, Pieza*** tablero) const;

};

