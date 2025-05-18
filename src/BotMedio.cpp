#include "BotMedio.h"
#include <cstdlib>
#include <ctime>
#include <vector>
#include <iostream>
#include "partida.h"
#include "pieza.h"

//Asignamos valores a cada pieza
int valorPieza(tipo_pieza tipo) {
    switch (tipo) {
    case tipo_pieza::REY: return 1000;
    case tipo_pieza::DAMA: return 9;
    case tipo_pieza::TORRE: return 5;
    case tipo_pieza::ALFIL: return 3;
    case tipo_pieza::CABALLO: return 3;
    case tipo_pieza::PEON: return 1;
    default: return 0;
    }
}

void BotMedio::jugarTurnoBot(partida* juego) {
    srand(time(nullptr));
    Pieza*** tablero = juego->getTablero();
    color colorBot = juego->getJugadorActual()->getColor();
    int filas = juego->getFilas();
    int columnas = juego->getColumnas();

    struct Jugada {
        int x1, y1, xd, yd;
        int valorCaptura;
    };

    std::vector<Jugada> capturas;
    std::vector<Jugada> movimientosValidos;

    // Recorremos el tablero para encontrar piezas del bot
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            Pieza* p = tablero[i][j];
            if (p && p->getColor() == colorBot) {
                for (int xd = 0; xd < filas; ++xd) {
                    for (int yd = 0; yd < columnas; ++yd) {
                        Pieza* destino = tablero[xd][yd];

                        // No permitir comerse al rey enemigo
                        if (destino && destino->getTipo() == tipo_pieza::REY)
                            continue;

                        if (p->movimiento_valido(i, j, xd, yd, tablero, colorBot)) {
                            int valor = (destino && destino->getColor() != colorBot)
                                ? valorPieza(destino->getTipo())
                                : 0;

                            Jugada jugada = { i, j, xd, yd, valor };

                            if (valor > 0)
                                capturas.push_back(jugada);
                            else
                                movimientosValidos.push_back(jugada);
                        }
                    }
                }
            }
        }
    }
    // Si hay capturas, escoger la de mayor valor
    if (!capturas.empty()) {
        Jugada mejor = capturas[0];
        for (const auto& j : capturas) {
            if (j.valorCaptura > mejor.valorCaptura)
                mejor = j;
        }
        juego->jugarTurno(mejor.x1, mejor.y1, mejor.xd, mejor.yd);
        return;
    }
    // Si no hay capturas, mover aleatoriamente una pieza válida
    if (!movimientosValidos.empty()) {
        int idx = rand() % movimientosValidos.size();
        Jugada j = movimientosValidos[idx];
        juego->jugarTurno(j.x1, j.y1, j.xd, j.yd);
        return;
    }
    std::cout << "[BOT MEDIO] No se pudo mover ninguna pieza.\n";

}

