#pragma once
#include "Partida.h"
#include "VistaTablero.h"

class ControladorJuego {

    partida* juego;
    VistaTablero vista;

    bool seleccionandoOrigen = true;
    int origenX = -1, origenY = -1;

public:
    ControladorJuego(partida* p);
    void dibujar();
    void manejarClick(int boton, int estado, int x, int y);
    void manejarTecla(unsigned char key, int x, int y);

    const VistaTablero& getVista() const { return vista; }

};
