#include "partida.h"
#include <iostream>
#include "freeglut.h"

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
        std::cout << "Tu rey est? en jaque.\n";
        recibioJaque = true;
    }

    // Workaround para no modificar tablero.cpp 1. Contar piezas del oponente antes del movimiento
    color colorOponente = (colorJugador == color::BLANCO) ? color::NEGRO : color::BLANCO;
    int piezasAntes = 0;

    for (int i = 0; i < t->getFilas(); i++) {
        for (int j = 0; j < t->getColumnas(); j++) {
            Pieza* p = t->getTablero()[i][j];
            if (p != nullptr && p->getColor() == colorOponente)
                piezasAntes++;
        }
    }
    //2. hacemos movimiento
    bool exito = t->mueve_pieza(x1, y1, x2, y2, colorJugador);


    if (exito) {
        movimientosRealizados++;

        // 3. Contamos piezas oponente tras movimiento
        int piezasDespues = 0;
        for (int i = 0; i < t->getFilas(); i++) {
            for (int j = 0; j < t->getColumnas(); j++) {
                Pieza* p = t->getTablero()[i][j];
                if (p != nullptr && p->getColor() == colorOponente)
                    piezasDespues++;
            }
        }

        // 4. Si disminuyeron==se ha capturado una pieza
        if (piezasDespues < piezasAntes) {
            piezasCapturadasJugador++;
        }
        //fin workaround
        if (exito) {
            movimientosRealizados++;//actualizamos marcador de movimiento
            std::cout << "[DEBUG] Movimiento realizado: (" << x1 << "," << y1 << ") -> (" << x2 << "," << y2 << ")\n";
            std::cout << "[DEBUG] Tablero tras mover:\n";
            t->print(std::cout); // saber que tablero tiene esta función implementada

            // Verificar si la partida terminó después del movimiento
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

//declaraciones de puntuacion
int partida::getNumeroMovimientos() const {
    // temporal
return movimientosRealizados;;
}

int partida::getPiezasCapturadasJugador() const {
    // temporal
    return piezasCapturadasJugador;
}

bool partida::ganoSinRecibirJaque() const {
    // temporal
    return !recibioJaque;
}
//finalizar partida para cuadrar la clasificacion
bool partida::haFinalizado() const {
	std::cout<<"[LOG] entra a bool partida:haFinalizao 112\n ";
    return juegoTerminado;
}



