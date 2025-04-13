#include <iostream>
<<<<<<< HEAD
#include "tablero.h"
#include "partida.h"

using namespace std;

//Crear partida y dentro jugador y tablero

int main() {
    partida partida;
    partida.mostrarTablero();

=======
#include "Partida.h"

int main() {
    std::string variante;
    std::cout << "Elige variante (clasico, silverman, demi): ";
    std::cin >> variante;

    partida p(variante);
    p.mostrarTablero();

    int x1, y1, x2, y2;

    while (true) {
        std::cout << "\nTurno de " << (p.getJugadorActual()->getColor() == color::BLANCO ? "blancas" : "negras") << std::endl;

        std::cout << "Introduce coordenadas de origen (fila columna): ";
        std::cin >> x1 >> y1;

        std::cout << "Introduce coordenadas de destino (fila columna): ";
        std::cin >> x2 >> y2;

        p.jugarTurno(x1, y1, x2, y2);
        p.mostrarTablero();
    }

>>>>>>> main
    return 0;
}
