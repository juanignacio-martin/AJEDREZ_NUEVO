#pragma once
#include "partida.h"

class VistaTablero {
public:
    void dibujar(const partida& p);
    int getCeldaSize() const { return celdaSize; }

private:
    const int celdaSize = 80; // Tamaño de cada casilla en píxeles
    char obtenerSimbolo(const Pieza* pieza);
};