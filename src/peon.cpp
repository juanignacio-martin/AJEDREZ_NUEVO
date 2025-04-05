#include "peon.h"

bool peon::movimiento_valido(int x_origen, int y_origen, int x_destino, int y_destino, Pieza*** tablero) const {
    int direccion = (this->getColor() == color::BLANCO) ? -1 : 1; // Blancos avanzan hacia arriba, negros hacia abajo

    // Movimiento normal (una casilla adelante)
    if (y_origen == y_destino && x_destino == x_origen + direccion && tablero[x_destino][y_destino] == nullptr) {
        return true;
    }

    // Movimiento doble si es el primer turno
    if (y_origen == y_destino && x_destino == x_origen + 2 * direccion && (x_origen == 1 || x_origen == 6) &&
        tablero[x_destino][y_destino] == nullptr && tablero[x_origen + direccion][y_destino] == nullptr) {
        return true;
    }

    // **Captura en diagonal**
    if (abs(y_destino - y_origen) == 1 && x_destino == x_origen + direccion &&
        tablero[x_destino][y_destino] != nullptr &&
        tablero[x_destino][y_destino]->getColor() != this->getColor()) {
        return true;
    }
    //Comer al paso

    return false; // Si no cumple ninguna condición, es un movimiento inválido.
}
