#include "Puntuacion.h"
#include "partida.h"

int Puntuacion::calcular(const partida& partida) {
    int score = 100;

    // Penaliza cada movimiento realizado
    score -= partida.getNumeroMovimientos();

    // Premia piezas capturadas (3 puntos cada una)
    score += partida.getPiezasCapturadasJugador() * 3;

    // Premio si no recibió jaque
    if (partida.ganoSinRecibirJaque()) {
        score += 20;
    }

    // No permitir puntuación negativa
    if (score < 0) score = 0;

    return score;
}
