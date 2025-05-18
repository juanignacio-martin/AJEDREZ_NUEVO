#include "peon.h"
#include "dama.h"
#include "torre.h"
#include "alfil.h"
#include "caballo.h"

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
   
    if (tablero[x_origen][y_origen] == nullptr ||
        tablero[x_origen][y_origen]->getColor() != jugadorColor) {
        return false;
    }

    int promo;
    if (modo_juego == 1)
        promo = 3;
    else
        promo = 6;

    int direccion = (this->getColor() == color::BLANCO) ? -1 : 1; // Blancos avanzan hacia arriba, negros hacia abajo

    // Movimiento normal (una casilla adelante)
    if (y_origen == y_destino && x_destino == x_origen + direccion && tablero[x_destino][y_destino] == nullptr) {
        // Comprobar si ha llegado al final y promocionar
        if ((this->getColor() == color::BLANCO && x_destino == 0) || (this->getColor() == color::NEGRO && x_origen == promo)) {
            // Llamar a la función de promoción directamente
            peon* p = dynamic_cast<peon*>(tablero[x_origen][y_origen]);
            if (p) {
             //   p->promocionar(tablero, x_origen, y_origen);
            }
        }
        return true;
    }

    // Movimiento doble si es el primer turno
    if (modo_juego == 0) {
        if (y_origen == y_destino && x_destino == x_origen + 2 * direccion && (x_origen == 1 || x_origen == 6) &&
            tablero[x_destino][y_destino] == nullptr && tablero[x_origen + direccion][y_destino] == nullptr) {
            registrarMovimientoDoble(x_destino, y_destino);
            return true;
        }
    }

    // **Captura en diagonal**
    if (abs(y_destino - y_origen) == 1 && x_destino == x_origen + direccion &&
        tablero[x_destino][y_destino] != nullptr &&
        tablero[x_destino][y_destino]->getColor() != this->getColor()) {
        // Comprobar si ha llegado al final y promocionar
        if ((this->getColor() == color::BLANCO && x_destino == 0) || (this->getColor() == color::NEGRO && x_origen == promo)) {
            // Llamar a la función de promoción directamente
            peon* p = dynamic_cast<peon*>(tablero[x_origen][y_origen]);
            if (p) {
              //  p->promocionar(tablero, x_origen, y_origen);
            }
        }
        return true;
    }

    //Captura al paso

    if (abs(y_destino - y_origen) == 1 && x_destino == x_origen + direccion &&
        tablero[x_destino][y_destino] == nullptr &&
        x_origen == ultima_fila_doble && // El peón contrario debe haber pasado justo junto
        y_destino == ultima_columna_doble &&
        tablero[x_origen][y_destino] != nullptr &&
        tablero[x_origen][y_destino]->getTipo() == tipo_pieza::PEON &&
        tablero[x_origen][y_destino]->getColor() != this->getColor()) {

        // Eliminar el peón enemigo
        delete tablero[x_origen][y_destino];
        tablero[x_origen][y_destino] = nullptr;

        ultima_fila_doble = -1;
        ultima_columna_doble = -1;
        return true;
    }

    return false; // Si no cumple ninguna condición, es un movimiento inválido.
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

