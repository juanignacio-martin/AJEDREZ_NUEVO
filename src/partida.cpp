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
   

    if (t->estaEnJaque(colorJugador)) {
        std::cout << "Tu rey esta en jaque.\n";
        recibioJaque = true;
    }

    //INICIO WORKAROUND PARA LA PUNTUACION DE CAPTURA
    color colorOponente = (colorJugador == color::BLANCO) ? color::NEGRO : color::BLANCO;
    int piezasAntes = 0;

    for (int i = 0; i < t->getFilas(); i++) {
        for (int j = 0; j < t->getColumnas(); j++) {
            Pieza* p = t->getTablero()[i][j];
            if (p != nullptr && p->getColor() == colorOponente)
                piezasAntes++;
        }
    }

    bool exito = t->mueve_pieza(x1, y1, x2, y2, colorJugador);

    if (exito) {
      std::cout << "Turno de " << (colorOponente == color::BLANCO ? "blancas" : "negras") << std::endl;

    }

    if (exito) {
        movimientosRealizados++;

        int piezasDespues = 0;
        for (int i = 0; i < t->getFilas(); i++) {
            for (int j = 0; j < t->getColumnas(); j++) {
                Pieza* p = t->getTablero()[i][j];
                if (p != nullptr && p->getColor() == colorOponente)
                    piezasDespues++;
            }
        }

        if (piezasDespues < piezasAntes) {
            piezasCapturadasJugador++;
        }
        //FIN WORKAROUND PARA LA PUNTUACION DE CAPTURA

        if (exito) {
            t->print(std::cout); // saber que tablero tiene esta función implementada

            // Verificar si la partida terminó después del movimiento
            color siguienteColor = (colorJugador == color::BLANCO) ? color::NEGRO : color::BLANCO;
            if (t->esJaqueMate(siguienteColor)) {
                std::cout << "Jaque mate " << (colorJugador == color::BLANCO ? "Blancas" : "Negras") << " ganan.\n";
                juegoTerminado = true;
            }
            else if (t->esTablas(siguienteColor)) {
                std::cout << "Tablas\n";
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

//gestionamos puntuacion
int partida::getNumeroMovimientos() const {
return movimientosRealizados;
}

int partida::getPiezasCapturadasJugador() const {
    return piezasCapturadasJugador;
}

bool partida::ganoSinRecibirJaque() const {
    return !recibioJaque;
}
//finalizar partida para cuadrar la clasificacion
bool partida::haFinalizado() const {
	//std::cout<<"[LOG] entra a bool partida:haFinalizao 112\n ";
    return juegoTerminado;
}



