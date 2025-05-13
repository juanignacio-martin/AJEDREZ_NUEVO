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
#define square 3
class tablero {
public:


	int _N, _M;
	Pieza*** tab = nullptr;

	//interfaz
	int tema{};
	


public:
	tablero(int N = -1, int M = -1);
	tablero(const tablero&) = delete;				//=delete, tablero solo hay uno
	~tablero();

	//I/O
	std::ostream& print(std::ostream&);


	bool mueve_pieza(int x_origen, int y_origen, int x_destino, int y_destino, color jugadorColor);


	//SET
	void cell(int i, int j, Pieza* val) {
		delete tab[i][j];  // Evita fugas de memoria eliminando la pieza anterior
		tab[i][j] = val;   // Asigna la nueva pieza
	}



	Pieza** operator[](int i);
	const Pieza* const* operator[](int i) const;
	bool estaEnJaque(color jugadorColor);

	void reserva_inicializacionClasico();
	void reserva_inicializacionDemi();
	void reserva_inicializacionSilver();
	void liberacion();

	Pieza*** getTablero() const { return tab; }

	int getFilas() const { return _N; }
	int getColumnas() const { return _M; }

	//interfaz
	void dibuja(bool tema);
};

