#include "partida.h"
#include <iostream>

partida::partida(const std::string& tipo)
    : jugadorBlanco(color::BLANCO),
    jugadorNegro(color::NEGRO),
    jugadorActual(&jugadorBlanco),
    variante(tipo),
    turno(0) {
    inicializarTablero(int t,int v);
}

partida::~partida() {
    delete tab;
}

void partida::inicializarTablero(int t, int v) {
    if (variante == "silverman") {
        tab = new tablero(5, 4);
        colocarSilverman(t,v);
    }
    else if (variante == "demi") {
        tab = new tablero(8, 4);
        colocarDemi(t,v);
    }
    else {
        tab = new tablero(8, 8);
        colocarClasico(t,v);
    }
}

void partida::colocarSilverman(int t, int v) {
    tab->reserva_inicializacionSilver(int t, int v);
}


void partida::colocarDemi(int t,int v) {

    tab->reserva_inicializacionDemi(int t,int v);
}

void partida::colocarClasico(int t, int v) {
    tab->reserva_inicializacionClasico(int t,int v);
}


void partida::jugarTurno(int x1, int y1, int x2, int y2) {
    std::cout << "Turno de " << (jugadorActual->getColor() == color::BLANCO ? "blancas" : "negras") << std::endl;

    if (!tab->mueve_pieza(x1, y1, x2, y2, jugadorActual->getColor())) {
        std::cout << "Movimiento no ejecutado." << std::endl;
        return;
    }

    if (t->estaEnJaque(jugadorActual->getColor())) {
        std::cout << "Tu rey está en jaque." << std::endl;
    }

    cambiarTurno();
    turno++;
}


void partida::cambiarTurno() {
    jugadorActual = (jugadorActual == &jugadorBlanco) ? &jugadorNegro : &jugadorBlanco;
}

void partida::mostrarTablero() const {
    tab->print(std::cout);
}

jugador* partida::getJugadorActual() const {
    return jugadorActual;
}

bool partida::estaEnJaque() const {
    return tab->estaEnJaque(jugadorActual->getColor());
}

void partida::drawpartida(int variante, int vision) {

    //Tablero
    tablero.dibuja(tema);

    //Dibuja las piezas segun el modo de vista
    blancas.cambiaTematica(tema);
    negras.cambiaTematica(tema);
    blancas.cambiaVision(vision);
    negras.cambiaVision(vision);


    //Piezas 
    
}