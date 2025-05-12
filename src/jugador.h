#pragma once
#include "pieza.h"

class jugador {
private:
    color col;  // Color del jugador (BLANCO o NEGRO)
    bool turno; // Indica si es su turno o no
    bool esIA_; // Nuevo miembro para controlar si es IA

public:
    // Constructor
    jugador(color c) : col(c), turno(c == color::BLANCO), esIA_(false) {}

    // Getters
    color getColor() const { return col; }
    bool esTurno() const { return turno; }
    //bool esIA() const { return esIA_; }
    // Métodos para manejar turnos
    //void setEsIA(bool esIA) { esIA_ = esIA; }
    void iniciarTurno() { turno = true; }
    void terminarTurno() { turno = false; }
};
