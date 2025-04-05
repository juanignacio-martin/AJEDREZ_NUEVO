#pragma once
#include <iostream>
#include "tablero.h"
#include "Jugador.h"

class partida
{
	jugador jugadorBlanco;
	jugador jugadorNegro;
	jugador* jugadorActual; // Puntero al jugador que tiene el turno

	tablero* tableroSelec;

public:
	partida(); // Constructor
	~partida(); // Destructor
	void mostrarTablero() const;
};

