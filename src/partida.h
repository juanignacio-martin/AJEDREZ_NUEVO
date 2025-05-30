#pragma once

#include "tablero.h"
#include "jugador.h"
#include "Bot.h"


class partida {
private:
    jugador jugadorBlanco;
    jugador jugadorNegro;
    jugador* jugadorActual;
    tablero* t;
    std::string variante;
    int turno;
    bool juegoTerminado;
    Bot* bot = nullptr;
    bool contraBot = false;

    //control de puntuacion
    int movimientosRealizados = 0;
    int piezasCapturadasJugador = 0;
    bool recibioJaque = false;

public:
    partida(const std::string& tipo = "clasico");
    ~partida();

    bool jugarTurno(int x1, int y1, int x2, int y2);


    void mostrarTablero() const;
    jugador* getJugadorActual() const;
    bool estaEnJaque() const;
    Pieza*** getTablero() const {
        return t->getTablero(); // en `tablero` haces return tab;
    }
    tablero* getTableroPtr() const {
        return t;
    }
    int getFilas() const { return t->getFilas(); }
    int getColumnas() const { return t->getColumnas(); }
    std::string getVariante() const { return variante; }




    void setBot(Bot* b) {
        bot = b;
        contraBot = true;
    }
    Bot* getBot() const { return bot; }
    bool esContraBot() const { return contraBot; }   




    //controldr de final de partida para clasificacion
    bool haFinalizado() const;
    //métodos de puntuación
    int getNumeroMovimientos() const;
    int getPiezasCapturadasJugador() const;
    bool ganoSinRecibirJaque() const;

    void cambiarTurno();
private:

    void inicializarTablero();     // crea el tablero según la variante
    void colocarSilverman();
    void colocarDemi();
    void colocarClasico();
};
//función global "libre"
void pedirNombreJugador();

