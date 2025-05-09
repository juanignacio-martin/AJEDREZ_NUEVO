#pragma once
#include "Partida.h"
#include "VistaTablero.h"
class ControladorApp;


class ControladorJuego {

    partida* juego;
    VistaTablero vista;

    bool seleccionandoOrigen = true;
    int origenX = -1, origenY = -1;

    ControladorApp* app; // referencia para mostrar menú promoción

public:
    ControladorJuego(partida* p, ControladorApp* app);
    void dibujar();
    void manejarClick(int boton, int estado, int x, int y);
    void manejarTecla(unsigned char key, int x, int y);

    const VistaTablero& getVista() const { return vista; }
    Pieza*** getTablero() const { return juego->getTablero(); }
};
