#include "rey.h"


bool rey::movimiento_valido(int x_origen, int y_origen, int x_destino, int y_destino, Pieza*** tablero) const {
    int dx = abs(x_destino - x_origen);
    int dy = abs(y_destino - y_origen);

    return dx <= 1 && dy <= 1;
}
