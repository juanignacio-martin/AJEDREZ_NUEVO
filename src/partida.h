#pragma once
#include "tablero.h"
#include "jugador.h"

class partida {
private:
    jugador jugadorBlanco;
    jugador jugadorNegro;
    jugador* jugadorActual;
    tablero* t;
    std::string variante;
    int turno;

public:
    partida(const std::string& tipo = "clasico");
    ~partida();

    void jugarTurno(int x1, int y1, int x2, int y2);
    void mostrarTablero() const;
    jugador* getJugadorActual() const;
    bool estaEnJaque() const;

private:
    void inicializarTablero();     // crea el tablero según la variante
    void cambiarTurno();
    void colocarSilverman();
    void colocarDemi();
    void colocarClasico();
};
