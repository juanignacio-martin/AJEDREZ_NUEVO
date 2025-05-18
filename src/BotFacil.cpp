#include "BotFacil.h"
#include <cstdlib>
#include <ctime>
#include "partida.h"


void BotFacil::jugarTurnoBot(partida* juego){
    srand(time(nullptr)); // inicializa semilla aleatoria

    Pieza*** tablero = juego->getTablero();
    color colorBot = juego->getJugadorActual()->getColor();
    int filas = juego->getFilas();
    int columnas = juego->getColumnas();

    std::vector<std::pair<int, int>> piezasBot;

    // Buscar piezas del bot
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            Pieza* p = tablero[i][j];
            if (p && p->getColor() == colorBot) {
                piezasBot.emplace_back(i, j);
            }
        }
    }

    // Probar movimientos aleatorios de esas piezas
    for (int intentos = 0; intentos < 100; ++intentos) {
        int idx = rand() % piezasBot.size();
        int x1 = piezasBot[idx].first;
        int y1 = piezasBot[idx].second;

        int dx = rand() % filas;
        int dy = rand() % columnas;

        Pieza* destino = tablero[dx][dy];

        // Si la casilla de destino tiene al Rey aliado, saltamos esta jugada
        if (destino && destino->getColor() == colorBot && destino->getTipo() == tipo_pieza::REY) {
            continue;
        }

        if (juego->jugarTurno(x1, y1, dx, dy)) {
            return; // éxito
        }
    }

    std::cout << "[BOT] No se pudo mover ninguna pieza.\n";
}
