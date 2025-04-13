#include "peon.h"
#include "dama.h"
#include "torre.h"
#include "alfil.h"
#include "caballo.h"

bool peon::movimiento_valido(int x_origen, int y_origen, int x_destino, int y_destino, Pieza*** tablero) const {
    int direccion = (this->getColor() == color::BLANCO) ? -1 : 1; // Blancos avanzan hacia arriba, negros hacia abajo

    // Movimiento normal (una casilla adelante)
    if (y_origen == y_destino && x_destino == x_origen + direccion && tablero[x_destino][y_destino] == nullptr) {
        // Comprobar si ha llegado al final y promocionar
        if ((this->getColor() == color::BLANCO && x_destino == 0) || (this->getColor() == color::NEGRO && x_destino == 7)) {
            // Llamar a la función de promoción directamente
            peon* p = dynamic_cast<peon*>(tablero[x_origen][y_origen]);
            if (p) {
                p->promocionar(tablero, x_destino, y_destino);
            }
        }
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
        // Comprobar si ha llegado al final y promocionar
        if ((this->getColor() == color::BLANCO && x_destino == 0) || (this->getColor() == color::NEGRO && x_destino == 7)) {
            // Llamar a la función de promoción directamente
            peon* p = dynamic_cast<peon*>(tablero[x_origen][y_origen]);
            if (p) {
                p->promocionar(tablero, x_destino, y_destino);
            }
        }
        return true;
    }

    return false; // Si no cumple ninguna condición, es un movimiento inválido.
}

void peon::promocionar(Pieza*** tablero, int x, int y) {
    int opcion;
    std::cout << "¡Tu peón ha llegado al final!\n";
    std::cout << "¿A qué pieza quieres promocionar?\n";
    std::cout << "1. Dama\n";
    std::cout << "2. Torre\n";
    std::cout << "3. Alfil\n";
    std::cout << "4. Caballo\n";
    std::cout << "Elige una opción (1-4): ";
    std::cin >> opcion;

    // Eliminar el peón
    delete tablero[x][y];

    switch (opcion) {
    case 1:
        tablero[x][y] = new dama(this->getColor());
        break;
    case 2:
        tablero[x][y] = new torre(this->getColor());
        break;
    case 3:
        tablero[x][y] = new alfil(this->getColor());
        break;
    case 4:
        tablero[x][y] = new caballo(this->getColor());
        break;
    default:
        std::cout << "Opción inválida. Promocionando a Dama por defecto.\n";
        tablero[x][y] = new dama(this->getColor());
        break;
    }
}