#pragma once
#include "partida.h"
#include "VistaTablero.h"

class ControladorJuego {

    partida* juego;
    
    enum ESTADO { MENU, PARTIDA, PROMOCION,FIN } state{ MENU };  //Estados posibles de pantalla

public:
    menu principal;
    partida game;
    vistatablero cam;
    //Mouse raton;
    char cancion[50];
    ControladorJuego(partida* p);

    void dibujar();
    void manejarClick(int boton, int estado, int x, int y);
    void manejarTecla(unsigned char key, int x, int y);
    
    void MenuPromo();
    
};
