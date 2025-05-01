#pragma once
#include "partida.h"

class VistaTablero {
public:
    void dibujar(const partida& p);
    int getCeldaSize() const { return celdaSize; }

private:
    const int celdaSize = 80; // Tama�o de cada casilla en p�xeles
    char obtenerSimbolo(const Pieza* pieza);
};