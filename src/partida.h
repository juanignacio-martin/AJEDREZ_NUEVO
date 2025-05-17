#pragma once
#include "tablero.h"
#include "jugador.h"

class partida {
private:
    jugador jugadorBlanco;
    jugador jugadorNegro;
    jugador* jugadorActual;
    tablero* tab;
    std::string variante;
    int turno;

public:
    partida(const std::string& tipo = "clasico");
    ~partida();

    void jugarTurno(int x1, int y1, int x2, int y2);
    void mostrarTablero() const;
    jugador* getJugadorActual() const;
    bool estaEnJaque() const;
    Pieza*** getTablero() const {
        return tab->getTablero(); // en `tablero` haces return tab;
    }
    int getFilas() const { return tab->getFilas(); }
    int getColumnas() const { return tab->getColumnas(); }
    //interfaz
    void drawpartida(int variante, int vision);
    void inicializarTablero(int t, int v);     // crea el tablero según la variante
private:
    
    void cambiarTurno();
    void colocarSilverman(int t, int v);
    void colocarDemi(int t, int v);
    void colocarClasico(int t, int v);

};

