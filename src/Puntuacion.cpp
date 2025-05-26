#include "puntuacion.h"
#include "partida.h"

int Puntuacion::calcular(const partida& partida) {
    int score = 100;

    
    score -= partida.getNumeroMovimientos();  // penaliza movimientos
    score += partida.getPiezasCapturadasJugador();  // premia piezas capturadas
    if (partida.ganoSinRecibirJaque()) score += 20;

    // score mínimo de 0
    if (score < 0) score = 0;

    return score;
}
