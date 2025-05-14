#include "partida.h"
#include <iostream>

partida::partida(const std::string& tipo)
    : jugadorBlanco(color::BLANCO),
    jugadorNegro(color::NEGRO),
    jugadorActual(&jugadorBlanco),
    variante(tipo),
    turno(0),
    juegoTerminado(false) {
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
    if (juegoTerminado) {
        std::cout << "La partida ya ha terminado.\n";
        return false;
    }

    color colorJugador = jugadorActual->getColor();
    std::cout << "Turno de " << (colorJugador == color::BLANCO ? "blancas" : "negras") << std::endl;

    if (t->estaEnJaque(colorJugador)) {
        std::cout << "Tu rey está en jaque.\n";
    }

    bool exito = t->mueve_pieza(x1, y1, x2, y2, colorJugador);

    if (exito) {
        // Comprobar si terminó la partida
        color siguienteColor = (colorJugador == color::BLANCO) ? color::NEGRO : color::BLANCO;
        if (t->esJaqueMate(siguienteColor)) {
            std::cout << "¡Jaque mate! " << (colorJugador == color::BLANCO ? "Blancas" : "Negras") << " ganan.\n";
            juegoTerminado = true;
        }
        else if (t->esTablas(siguienteColor)) {
            std::cout << "¡Tablas!\n";
            juegoTerminado = true;
        }
        else {
            cambiarTurno();
            turno++;
        }
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

<<<<<<< HEAD
void partida::drawpartida(int variante, int vision) {

    //Tablero
    tablero.dibuja();


    //Piezas 
    
}
=======

>>>>>>> main
