#include "caballo.h"


bool caballo::movimiento_valido(int x_origen, int y_origen, int x_destino, int y_destino, Pieza*** tablero, color jugadorColor) const {

    if (tablero[x_origen][y_origen] == nullptr ||
        tablero[x_origen][y_origen]->getColor() != jugadorColor) {
        return false;
    }

    if (x_origen == x_destino && y_origen == y_destino) return false;

    int dx = abs(x_destino - x_origen);
    int dy = abs(y_destino - y_origen);

    return (dx == 2 && dy == 1) || (dx == 1 && dy == 2);
}
