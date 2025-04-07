#pragma once
#include "pieza.h"

class jugador {
private:
    color col;  // Color del jugador (BLANCO o NEGRO)
    bool turno; // Indica si es su turno o no

public:
    // Constructor
    jugador(color c) : col(c), turno(c == color::BLANCO) {}

    // Getters
    color getColor() const { return col; }
    bool esTurno() const { return turno; }

    // Métodos para manejar turnos
    void iniciarTurno() { turno = true; }
    void terminarTurno() { turno = false; }
};
