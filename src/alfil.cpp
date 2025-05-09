#include "alfil.h"



bool alfil::movimiento_valido(int x_origen, int y_origen, int x_destino, int y_destino, Pieza*** tablero, color jugadorColor) const {
   
    if (tablero[x_origen][y_origen] == nullptr ||
        tablero[x_origen][y_origen]->getColor() != jugadorColor) {
        return false;
    }
    
    if (abs(x_destino - x_origen) != abs(y_destino - y_origen)) return false; // Debe ser un movimiento en diagonal

    int paso_x = (x_destino > x_origen) ? 1 : -1; //Si se mueve a la derecha =1, si izquierda = -1
    int paso_y = (y_destino > y_origen) ? 1 : -1; //Si se mueve hacia arriba =1, si abajo = -1

    int x = x_origen + paso_x, y = y_origen + paso_y;
    while (x != x_destino && y != y_destino) {
        if (tablero[x][y] != nullptr) return false; // No puede haber piezas en el camino
        x += paso_x;
        y += paso_y;
    }

    return true;
}
