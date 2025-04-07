#include "dama.h"
#include "torre.h"
#include "alfil.h"


bool dama::movimiento_valido(int x_origen, int y_origen, int x_destino, int y_destino, Pieza*** tablero) const {
    torre t(this->getColor());
    alfil a(this->getColor());

    return t.movimiento_valido(x_origen, y_origen, x_destino, y_destino, tablero) ||
        a.movimiento_valido(x_origen, y_origen, x_destino, y_destino, tablero);
}
