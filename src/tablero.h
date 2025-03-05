#pragma once
#include <iostream>
#include "Pieza.h"
#include "Peon.h"
#include "Torre.h"
#include "Rey.h"
#include "Dama.h"
#include "Alfil.h"
#include "Caballo.h"
#include "Vacio.h"

class tablero {


	int _N, _M;
	Pieza*** tab = nullptr;

public:
	tablero(int N = -1, int M = -1);
	tablero(const tablero&) = delete;				//=delete, tablero solo hay uno
	~tablero();

	//I/O
	std::ostream& print(std::ostream&);

	//SET
	void cell(int i, int j, Pieza* val) {
		delete tab[i][j];  // Evita fugas de memoria eliminando la pieza anterior
		tab[i][j] = val;   // Asigna la nueva pieza
	}

	//GET
//	int cell(int i, int j)	const { return tab[i][j]; }

	Pieza** operator[](int i);
	const Pieza* const* operator[](int i) const;


private:
	void reserva_inicializacion();
	void liberacion();

};

