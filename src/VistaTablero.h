#pragma once
#include "partida.h"
#pragma once


#include "freeglut.h"
#include "ETSIDI.h"
#include "math.h"
#include <iostream>
#include "cstring"
class VistaTablero {
public:
    void dibujaV(const partida& p);
    int getCeldaSize() const { return celdaSize; }

private:
    const int celdaSize = 80; // Tamaño de cada casilla en píxeles
    char obtenerSimbolo(const Pieza* pieza);
};