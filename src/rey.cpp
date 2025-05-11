#include "rey.h"


bool rey::movimiento_valido(int x_origen, int y_origen, int x_destino, int y_destino, Pieza*** tablero, color jugadorColor) const {

    if (tablero[x_origen][y_origen] == nullptr ||
        tablero[x_origen][y_origen]->getColor() != jugadorColor) {
        return false;
    }

    int dx = abs(x_destino - x_origen);
    int dy = abs(y_destino - y_origen);
    if (x_origen == x_destino && y_origen == y_destino) return false;

    return dx <= 1 && dy <= 1;
}
