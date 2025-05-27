#pragma once
#include <vector>
#include <functional>
#include <freeglut.h>
#include "Pieza.h"
#include "partida.h"

class ControladorPromocion {
public:
    ControladorPromocion();

    void dibujar(color c);
//    void manejarClick(int x, int y, std::function<void(tipo_pieza)> seleccionar);
    void manejarClick(int x, int y, Pieza*** tablero, int fila, int columna,partida* p);


private:
    std::vector<tipo_pieza> opciones;
    int anchoBoton = 150;
    int altoBoton = 60;
    int separacion = 30;
    int xInicio = 100;
    int yInicio = 100;
};
