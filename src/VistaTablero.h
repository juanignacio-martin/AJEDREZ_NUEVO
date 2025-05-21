#pragma once
#include "partida.h"
#include <ETSIDI.h>

class VistaTablero {
public:
    ETSIDI::Sprite spriteBlancoPeon;
    ETSIDI::Sprite spriteBlancoTorre;
    ETSIDI::Sprite spriteBlancoAlfil;
    ETSIDI::Sprite spriteBlancoCaballo;
    ETSIDI::Sprite spriteBlancoDama;
    ETSIDI::Sprite spriteBlancoRey;

    ETSIDI::Sprite spriteNegroPeon;
    ETSIDI::Sprite spriteNegroTorre;
    ETSIDI::Sprite spriteNegroAlfil;
    ETSIDI::Sprite spriteNegroCaballo;
    ETSIDI::Sprite spriteNegroDama;
    ETSIDI::Sprite spriteNegroRey;


    VistaTablero();
   
    ETSIDI::Sprite* getSprite(const Pieza* pieza);
    void dibujar(const partida& p);
    int getCeldaSize() const { return celdaSize; }

private:
    const int celdaSize = 80; // Tamaño de cada casilla en píxeles
    char obtenerSimbolo(const Pieza* pieza);
};


