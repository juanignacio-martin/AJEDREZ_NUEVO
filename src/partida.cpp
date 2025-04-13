<<<<<<< HEAD
#include "partida.h"
#include "tablero.h"
#include "jugador.h"
#include <iostream>
#include <string>

using namespace std;

partida::partida()
    : jugadorBlanco (color::BLANCO), jugadorNegro (color::NEGRO), tableroSelec(nullptr)

{

    string eleccion;
    cout << "¿Qué tipo de tablero quieres usar? (Demi/Silver): ";
    cin >> eleccion;

    if (eleccion == "Demi" || eleccion == "demi") {
        tableroSelec = new tablero(8,4);
    }
    else if (eleccion == "Silver" || eleccion == "silver") {
        tableroSelec = new tablero(5,4);
    }
    else {
        cout << "Opción inválida, se seleccionará TableroDemi por defecto." << endl;
        tableroSelec = new tablero(8,4);
    }
}

partida::~partida() {
    delete tableroSelec; // Liberar memoria
}

void partida::mostrarTablero() const {
    tableroSelec -> print(std::cout); // Polimorfismo: llamar a imprimir() según tipo de tablero
}
=======
#include "Partida.h"
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
    // negras
    (*t)[0][0] = new torre(color::NEGRO);
    (*t)[0][1] = new rey(color::NEGRO);     // ? rey va en 1
    (*t)[0][2] = new dama(color::NEGRO);    // ? dama va en 2
    (*t)[0][3] = new torre(color::NEGRO);

    for (int j = 0; j < 5; ++j)
        (*t)[1][j] = new peon(color::NEGRO);

    // blancas
    for (int j = 0; j < 5; ++j)
        (*t)[3][j] = new peon(color::BLANCO);

    (*t)[4][0] = new torre(color::BLANCO);
    (*t)[4][1] = new rey(color::BLANCO);     // ? rey va en 1
    (*t)[4][2] = new dama(color::BLANCO);    // ? dama va en 2
    (*t)[4][3] = new torre(color::BLANCO);
}


void partida::colocarDemi() {
    // negras
    (*t)[0][3] = new torre(color::NEGRO);
    (*t)[0][2] = new caballo(color::NEGRO);
    (*t)[0][1] = new alfil(color::NEGRO);
    (*t)[0][0] = new rey(color::NEGRO);
    for (int j = 0; j < 8; ++j)
        (*t)[1][j] = new peon(color::NEGRO);

    // blancas
    for (int j = 0; j < 8; ++j)
        (*t)[6][j] = new peon(color::BLANCO);
    (*t)[7][3] = new torre(color::BLANCO);
    (*t)[7][2] = new caballo(color::BLANCO);
    (*t)[7][1] = new alfil(color::BLANCO);
    (*t)[7][0] = new rey(color::BLANCO);

}

void partida::colocarClasico() {
    // negras
    (*t)[0][0] = new torre(color::NEGRO);
    (*t)[0][1] = new caballo(color::NEGRO);
    (*t)[0][2] = new alfil(color::NEGRO);
    (*t)[0][3] = new dama(color::NEGRO);
    (*t)[0][4] = new rey(color::NEGRO);
    (*t)[0][5] = new alfil(color::NEGRO);
    (*t)[0][6] = new caballo(color::NEGRO);
    (*t)[0][7] = new torre(color::NEGRO);

    for (int j = 0; j < 8; ++j)
        (*t)[1][j] = new peon(color::NEGRO);

    // blancas
    for (int j = 0; j < 8; ++j)
        (*t)[6][j] = new peon(color::BLANCO);

    (*t)[7][0] = new torre(color::BLANCO);
    (*t)[7][1] = new caballo(color::BLANCO);
    (*t)[7][2] = new alfil(color::BLANCO);
    (*t)[7][3] = new dama(color::BLANCO);
    (*t)[7][4] = new rey(color::BLANCO);
    (*t)[7][5] = new alfil(color::BLANCO);
    (*t)[7][6] = new caballo(color::BLANCO);
    (*t)[7][7] = new torre(color::BLANCO);
}


void partida::jugarTurno(int x1, int y1, int x2, int y2) {
    std::cout << "Turno de " << (jugadorActual->getColor() == color::BLANCO ? "blancas" : "negras") << std::endl;

    t->mueve_pieza(x1, y1, x2, y2);

    if (t->estaEnJaque(jugadorActual->getColor())) {
        std::cout << "Tu rey esta en jaque." << std::endl;
    }

    cambiarTurno();
    turno++;
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
>>>>>>> main
