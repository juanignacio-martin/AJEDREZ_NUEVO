#include "torre.h"


bool torre::movimiento_valido(int x_origen, int y_origen, int x_destino, int y_destino, Pieza*** tablero, color jugadorColor) const {

    if (tablero[x_origen][y_origen] == nullptr ||
        tablero[x_origen][y_origen]->getColor() != jugadorColor) {
        return false;
    }
    if (x_origen != x_destino && y_origen != y_destino) return false; // Solo en línea recta

    if (x_origen != x_destino && y_origen != y_destino) return false; // Solo en lÃ­nea recta


    int paso_x = (x_destino - x_origen) ? (x_destino > x_origen ? 1 : -1) : 0;
    int paso_y = (y_destino - y_origen) ? (y_destino > y_origen ? 1 : -1) : 0;

    int x = x_origen + paso_x, y = y_origen + paso_y;
    while (x != x_destino || y != y_destino) {
        if (tablero[x][y] != nullptr) return false; // No puede haber piezas en el camino
        x += paso_x;
        y += paso_y;
    }

    return true;
}

