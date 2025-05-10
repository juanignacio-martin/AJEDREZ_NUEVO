#include "partida.h"
#include <iostream>

partida::partida(const std::string& tipo)
    : jugadorBlanco(color::BLANCO),
    jugadorNegro(color::NEGRO),
    jugadorActual(&jugadorBlanco),
    variante(tipo),
    turno(0) {
    inicializarTablero();
}

partida::~partida() {
    delete t;
}

void partida::inicializarTablero() {
    if (variante == "silverman") {
        t = new tablero(5, 4);
        colocarSilverman();
    }
    else if (variante == "demi") {
        t = new tablero(8, 4);
        colocarDemi();
    }
    else {
        t = new tablero(8, 8);
        colocarClasico();
    }
}

void partida::colocarSilverman() {
    t->reserva_inicializacionSilver();
}


void partida::colocarDemi() {

    t->reserva_inicializacionDemi();
}

void partida::colocarClasico() {
    t->reserva_inicializacionClasico();
}



bool partida::jugarTurno(int x1, int y1, int x2, int y2) {

    color colorJugador = jugadorActual->getColor();
    std::cout << "Turno de " << (colorJugador == color::BLANCO ? "blancas" : "negras") << std::endl;

    if (t->estaEnJaque(colorJugador)) {
        std::cout << "Tu rey está en jaque.\n";
    }

    // Intentar mover la pieza
    bool exito = t->mueve_pieza(x1, y1, x2, y2, colorJugador);

    // Solo cambiar turno si el movimiento fue válido
    if (exito) {
        cambiarTurno();
        turno++;
    }

    return exito;
}


void partida::cambiarTurno() {
    jugadorActual = (jugadorActual == &jugadorBlanco) ? &jugadorNegro : &jugadorBlanco;
}

void partida::mostrarTablero() const {
    t->print(std::cout);
}

jugador* partida::getJugadorActual() const {
    return jugadorActual;
}

bool partida::estaEnJaque() const {
    return t->estaEnJaque(jugadorActual->getColor());
}

