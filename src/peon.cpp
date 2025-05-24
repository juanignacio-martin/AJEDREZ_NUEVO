#include "dama.h"
#include "torre.h"
#include "alfil.h"
#include "caballo.h"
#include "peon.h"


int peon::modo_juego = 0; // Inicialmente en modo clásico/demichess

int peon::ultima_fila_doble = -1;
int peon::ultima_columna_doble = -1;

void peon::registrarMovimientoDoble(int fila, int columna) {
    ultima_fila_doble = fila;
    ultima_columna_doble = columna;
}

void peon::setModoJuego(int modo) {
    peon::modo_juego = modo;
}

bool peon::movimiento_valido(int x_origen, int y_origen, int x_destino, int y_destino, Pieza*** tablero, color jugadorColor) const {

    static bool enPassantCapturadoEstaLlamada = false;

    if (tablero[x_origen][y_origen] == nullptr ||
        tablero[x_origen][y_origen]->getColor() != jugadorColor) {
        return false;
    }

    int direccion = (this->getColor() == color::BLANCO) ? -1 : 1;

    // Movimiento normal
    if (y_origen == y_destino && x_destino == x_origen + direccion && tablero[x_destino][y_destino] == nullptr) {
        enPassantCapturadoEstaLlamada = false;
        return true;
    }

    // Movimiento doble (primer turno, modo clásico)
    if (modo_juego == 0) {
        if (y_origen == y_destino && x_destino == x_origen + 2 * direccion &&
            ((this->getColor() == color::BLANCO && x_origen == 6) || (this->getColor() == color::NEGRO && x_origen == 1)) &&
            tablero[x_destino][y_destino] == nullptr && tablero[x_origen + direccion][y_destino] == nullptr) {
            registrarMovimientoDoble(x_destino, y_destino);
            enPassantCapturadoEstaLlamada = false;
            return true;
        }
    }

    // Captura normal
    if (abs(y_destino - y_origen) == 1 && x_destino == x_origen + direccion &&
        tablero[x_destino][y_destino] != nullptr &&
        tablero[x_destino][y_destino]->getColor() != this->getColor()) {
        enPassantCapturadoEstaLlamada = false;
        return true;
    }

    // Captura al paso
    if (abs(y_destino - y_origen) == 1 && x_destino == x_origen + direccion &&
        tablero[x_destino][y_destino] == nullptr &&
        x_origen == ultima_fila_doble && y_destino == ultima_columna_doble &&
        tablero[x_origen][y_destino] != nullptr &&
        tablero[x_origen][y_destino]->getTipo() == tipo_pieza::PEON &&
        tablero[x_origen][y_destino]->getColor() != this->getColor() &&
        this->getColor() == jugadorColor) {

        if (!enPassantCapturadoEstaLlamada) {
            delete tablero[x_origen][y_destino];
            tablero[x_origen][y_destino] = nullptr;

            ultima_fila_doble = -1;
            ultima_columna_doble = -1;

            enPassantCapturadoEstaLlamada = true;

            std::cout << "Captura al paso: peón eliminado en (" << x_origen << ", " << y_destino << ")\n";
        }

        return true;
    }

    enPassantCapturadoEstaLlamada = false;
    return false;
}




void peon::promocionar(Pieza*** tablero, int fila, int columna, tipo_pieza nueva) {
    color c = tablero[fila][columna]->getColor();
    delete tablero[fila][columna];

    switch (nueva) {
    case tipo_pieza::DAMA:
        tablero[fila][columna] = new dama(c);
        break;
    case tipo_pieza::TORRE:
        tablero[fila][columna] = new torre(c);
        break;
    case tipo_pieza::ALFIL:
        tablero[fila][columna] = new alfil(c);
        break;
    case tipo_pieza::CABALLO:
        tablero[fila][columna] = new caballo(c);
        break;
    default:
        tablero[fila][columna] = new dama(c);
        break;
    }
}





