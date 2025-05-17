#pragma once
#include "pieza.h"
#include "tablero.h"

class peon : public Pieza
{
private:
    static int modo_juego; // 0 = Clásico/Demi, 1 = Silverman

public:
    peon(color col, int t, int v)
        : Pieza(tipo_pieza::PEON, col, t, v)
    {}

    bool movimiento_valido(int x_origen, int y_origen, int x_destino, int y_destino, Pieza*** tablero) const override;
    void promocionar(Pieza*** pieza_tablero, int x, int y);

    static void setModoJuego(int modo); // Setter para cambiar el modo de juego
};
