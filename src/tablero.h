#pragma once
#include <iostream>
#include "Pieza.h"
#include "Peon.h"
#include "Torre.h"
#include "Rey.h"
#include "Dama.h"
#include "Alfil.h"
#include "Caballo.h"
#include "Jugador.h"

class tablero {


	int _N, _M;
	Pieza*** tab = nullptr;

	jugador jugadorBlanco;
	jugador jugadorNegro;
	jugador* jugadorActual; // Puntero al jugador que tiene el turno

public:
	tablero(int N = -1, int M = -1);
	tablero(const tablero&) = delete;				//=delete, tablero solo hay uno
	~tablero();

	//I/O
	std::ostream& print(std::ostream&);


	void mueve_pieza(int x_origen, int y_origen, int x_destino, int y_destino);


	//SET
	void cell(int i, int j, Pieza* val) {
		delete tab[i][j];  // Evita fugas de memoria eliminando la pieza anterior
		tab[i][j] = val;   // Asigna la nueva pieza
	}

	//GET
//	int cell(int i, int j)	const { return tab[i][j]; }

	Pieza** operator[](int i);
	const Pieza* const* operator[](int i) const;
	void cambiarTurno();
	bool esTurnoCorrecto(int x, int y);
	bool estaEnJaque(color jugadorColor);


private:
	void reserva_inicializacionDemi();
	void reserva_inicializacionSilver();
	void liberacion();

};

