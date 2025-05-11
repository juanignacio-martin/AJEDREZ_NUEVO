#include "tablero.h"

using namespace std;

tablero::tablero(int N, int M) : _N(N), _M(M) {
	if (_N <= 0 || _M <= 0) {
		std::cout << "error en la dimension de la matriz" << std::endl;
		_N = 0;
		_M = 0;
		tab = nullptr;
		return;
	}

	// Reservar memoria para el tablero
	tab = new Pieza * *[_N];
	for (int i = 0; i < _N; ++i) {
		tab[i] = new Pieza * [_M];
		for (int j = 0; j < _M; ++j) {
			tab[i][j] = nullptr;
		}
	}
}

void tablero::reserva_inicializacionClasico() {

	;
	peon::setModoJuego(0);
	if (_N != 8 || _M != 8) {
		std::cout << "Error: el tablero clasico debe ser de 8x8." << std::endl;
		return;
	}

	tab = new Pieza * *[_N];
	for (int i = 0; i < _N; i++) {
		tab[i] = new Pieza * [_M];
		for (int j = 0; j < _M; j++) {
			tab[i][j] = nullptr;
		}
	}
	
	// Piezas negras
	tab[0][0] = new torre(color::NEGRO);
	tab[0][1] = new caballo(color::NEGRO);
	tab[0][2] = new alfil(color::NEGRO);
	tab[0][3] = new dama(color::NEGRO);
	tab[0][4] = new rey(color::NEGRO);
	tab[0][5] = new alfil(color::NEGRO);
	tab[0][6] = new caballo(color::NEGRO);
	tab[0][7] = new torre(color::NEGRO);

	for (int j = 0; j < _M; ++j)
		tab[1][j] = new peon(color::NEGRO);

	// Piezas blancas
	for (int j = 0; j < _M; ++j)
		tab[6][j] = new peon(color::BLANCO);

	tab[7][0] = new torre(color::BLANCO);
	tab[7][1] = new caballo(color::BLANCO);
	tab[7][2] = new alfil(color::BLANCO);
	tab[7][3] = new dama(color::BLANCO);
	tab[7][4] = new rey(color::BLANCO);
	tab[7][5] = new alfil(color::BLANCO);
	tab[7][6] = new caballo(color::BLANCO);
	tab[7][7] = new torre(color::BLANCO);
}



void tablero::reserva_inicializacionDemi() {

	peon::setModoJuego(0);
	if (_N <= 0 || _M <= 0) {
		std::cout << "Error: dimensiones invalidas del tablero" << std::endl;
		return;
	}

	// Reservar memoria para la matriz de punteros a punteros
	tab = new Pieza * *[_N];
	std::cout << "Memoria para tab reservada correctamente." << std::endl;

	for (int i = 0; i < _N; i++) {
		tab[i] = new Pieza * [_M]; // Reservar cada fila
		std::cout << "Fila " << i << " reservada correctamente." << std::endl;

		for (int j = 0; j < _M; j++) {
			tab[i][j] = nullptr; // Inicializar con nullptr
		}
	}

	std::cout << "Tablero inicializado correctamente." << std::endl;

	tab[0][3] = new torre(color::NEGRO);
	tab[0][1] = new caballo(color::NEGRO);
	tab[0][2] = new alfil(color::NEGRO);
	tab[0][0] = new rey(color::NEGRO);
	//tab[0][1] = new dama(color::NEGRO);
	for (int j = 0; j < _M; ++j) {
		tab[1][j] = new peon(color::NEGRO);
	}


	//Blancas
	for (int j = 0; j < _M; ++j) {
		tab[6][j] = new peon(color::BLANCO);; // Peones blancos
	}
	tab[7][3] = new torre(color::BLANCO); // Torres blancas
	tab[7][1] = new caballo(color::BLANCO); // Caballos blancos
	tab[7][2] = new alfil(color::BLANCO); // Alfiles blancos
	tab[7][0] = new rey(color::BLANCO);              // Dama blanca
	//tab[4][1] = new dama(color::BLANCO);              // Rey blanco


}
void tablero::reserva_inicializacionSilver() {

	peon::setModoJuego(1);

	if (_N <= 0 || _M <= 0) {
		std::cout << "Error: dimensiones invalidas del tablero" << std::endl;
		return;
	}

	// Reservar memoria para la matriz de punteros a punteros
	tab = new Pieza * *[_N];
	std::cout << "Memoria para tab reservada correctamente." << std::endl;

	for (int i = 0; i < _N; i++) {
		tab[i] = new Pieza * [_M]; // Reservar cada fila
		std::cout << "Fila " << i << " reservada correctamente." << std::endl;

		for (int j = 0; j < _M; j++) {
			tab[i][j] = nullptr; // Inicializar con nullptr
		}
	}

	std::cout << "Tablero inicializado correctamente." << std::endl;

	tab[0][3] = new torre(color::NEGRO);
	tab[0][0] = new torre(color::NEGRO);
	//tab[0][1]  = new caballo(color::NEGRO);
	//tab[0][2]  = new alfil(color::NEGRO);
	tab[0][2] = new rey(color::NEGRO);
	tab[0][1] = new dama(color::NEGRO);
	for (int j = 0; j < _M; ++j) {
     tab[1][j] = new peon(color::NEGRO);
	}


	//Blancas
	for (int j = 0; j < _M; ++j) {
		tab[3][j] = new peon(color::BLANCO);; // Peones blancos
	}
	tab[4][3] = new torre(color::BLANCO); // Torres blancas
	tab[4][0] = new torre(color::BLANCO);
	//tab[7][1] =  new caballo(color::BLANCO); // Caballos blancos
	//tab[7][2] = new alfil(color::BLANCO); // Alfiles blancos
	tab[4][2] = new rey(color::BLANCO);              // Dama blanca
	tab[4][1] = new dama(color::BLANCO);              // Rey blanco


}

tablero::~tablero() {
	liberacion();
}

void tablero::liberacion() {
	if (tab) {
		for (int i = 0; i < _N; i++) {
			delete[] tab[i];  // Libera cada fila
		}
		delete[] tab;  // Libera el array de punteros
		tab = nullptr;
	}
}


ostream& tablero::print(std::ostream& o) {
	for (int i = 0; i < _N; i++) {
		for (int j = 0; j < _M; j++) {
			if (tab[i][j] != nullptr) {
				o << *tab[i][j] << " ";
			}
			else {
				o << ". ";  // RepresentaciÃ³n de casilla vacÃ­a
			}
		}
		o << std::endl;
	}
	return o;
}


Pieza** tablero::operator[](int i) {
	if (i >= 0 && i < _N) {
		return tab[i];  // Devuelve Pieza*
	}
	throw std::out_of_range("Indice fuera de rango");
}

const Pieza* const* tablero::operator[](int i) const {
	if (i >= 0 && i < _N) {
		return tab[i];  // Devuelve const Pieza* const*
	}
	throw std::out_of_range("Indice fuera de rango");
}

bool tablero::mueve_pieza(int x_origen, int y_origen, int x_destino, int y_destino, color jugadorColor) {
	// Validar que haya una pieza en origen
	if (!tab[x_origen][y_origen]) {
		std::cout << "No hay pieza en la casilla de origen.\n";
		return false;
	}

	// Verificar que la pieza sea del jugador
	if (tab[x_origen][y_origen]->getColor() != jugadorColor) {
		std::cout << "La pieza no pertenece al jugador.\n";
		return false;
	}

	// Verificar si el movimiento es válido
	if (!tab[x_origen][y_origen]->movimiento_valido(x_origen, y_origen, x_destino, y_destino, tab, jugadorColor)) {
		std::cout << "Movimiento inválido.\n";
		return false;
	}

	// Guardar punteros antes de mover
	Pieza* piezaOrigen = tab[x_origen][y_origen];
	Pieza* piezaDestino = tab[x_destino][y_destino];

	// Simular el movimiento
	tab[x_destino][y_destino] = piezaOrigen;
	tab[x_origen][y_origen] = nullptr;

	// Verificar si el rey queda en jaque
	if (estaEnJaque(jugadorColor)) {
		// Deshacer movimiento
		tab[x_origen][y_origen] = piezaOrigen;
		tab[x_destino][y_destino] = piezaDestino;
		std::cout << "Movimiento inválido: el rey sigue en jaque.\n";
		return false;
	}

	// Si había una pieza enemiga, eliminarla
	if (piezaDestino != nullptr) {
		std::cout << "Capturando " << tipoPiezaToString(piezaDestino->getTipo())
			<< " (" << (piezaDestino->getColor() == color::BLANCO ? "Blanco" : "Negro") << ").\n";
		delete piezaDestino;
	}

	color oponente = (jugadorColor == color::BLANCO) ? color::NEGRO : color::BLANCO;

	if (esJaqueMate(oponente)) {
		std::cout << "¡Jaque mate! " << (jugadorColor == color::BLANCO ? "Blancas" : "Negras") << " ganan." << std::endl;
	}
	else if (esTablas(oponente)) {
		std::cout << "¡Tablas!" << std::endl;
	}

	std::cout << "Moviendo pieza...\n";
	return true;
}




bool tablero::estaEnJaque(color jugadorColor) {
	int reyX = -1, reyY = -1;

	// Buscar la poscion del rey del jugador 
	for (int i = 0; i < _N; i++) {
		for (int j = 0; j < _M; j++) {
			if (tab[i][j] != nullptr && tab[i][j]->getTipo() == tipo_pieza::REY && tab[i][j]->getColor() == jugadorColor) {
				reyX = i;
				reyY = j;
				break;
			}
		}
	}

	if (reyX == -1 || reyY == -1) {
		std::cout << "No se encontro el rey en el tablero." << std::endl;
		return false;
	}

	color colorContrario = (jugadorColor == color::BLANCO) ? color::NEGRO : color::BLANCO;

	// Verificr si alguna pieza rival puede atacar al rey
	for (int i = 0; i < _N; i++) {
		for (int j = 0; j < _M; j++) {
			if (tab[i][j] != nullptr && tab[i][j]->getColor() != jugadorColor) {
				if (tab[i][j]->movimiento_valido(i, j, reyX, reyY, tab, colorContrario)) {
					std::cout << "Jaque El rey de " << (jugadorColor == color::BLANCO ? "Blanco" : "Negro")
						<< " esta bajo ataque de un " << tipoPiezaToString(tab[i][j]->getTipo())
						<< " en (" << i << ", " << j << ")." << std::endl;
					return true;
				}
			}
		}
	}

	return false; // No hay jaque
}

bool tablero::esJaqueMate(color jugadorColor) {
	if (!estaEnJaque(jugadorColor)) return false;

	for (int i = 0; i < _N; i++) {
		for (int j = 0; j < _M; j++) {
			Pieza* pieza = tab[i][j];
			if (pieza && pieza->getColor() == jugadorColor) {
				for (int x = 0; x < _N; x++) {
					for (int y = 0; y < _M; y++) {
						// Ignorar si intenta comerse a su propio rey
						Pieza* destino = tab[x][y];
						if (destino && destino->getColor() == jugadorColor && destino->getTipo() == tipo_pieza::REY)
							continue;

						if (pieza->movimiento_valido(i, j, x, y, tab, jugadorColor)) {
							// Simular movimiento
							tab[x][y] = pieza;
							tab[i][j] = nullptr;

							bool sigueEnJaque = estaEnJaque(jugadorColor);

							// Deshacer
							tab[i][j] = pieza;
							tab[x][y] = destino;

							if (!sigueEnJaque)
								return false;
						}
					}
				}
			}
		}
	}
	return true;
}


bool tablero::esTablas(color jugadorColor) {

	//Comprobar si solo quedan los dos reyes
	int totalPiezas = 0;
	int cantidadReyes = 0;

	for (int i = 0; i < _N; i++) {
		for (int j = 0; j < _M; j++) {
			if (tab[i][j]) {
				totalPiezas++;
				if (tab[i][j]->getTipo() == tipo_pieza::REY)
					cantidadReyes++;
			}
		}
	}
	if (totalPiezas == 2 && cantidadReyes == 2) {
		std::cout << "Empate por material insuficiente (solo reyes).\n";
		return true;
	}

	// Comprobar si el jugador no está en jaque y no tiene jugadas legales válidas -> ahogado
	if (!estaEnJaque(jugadorColor)) {
		for (int i = 0; i < _N; i++) {
			for (int j = 0; j < _M; j++) {
				if (tab[i][j] && tab[i][j]->getColor() == jugadorColor) {
					for (int x = 0; x < _N; x++) {
						for (int y = 0; y < _M; y++) {
							if (tab[i][j]->movimiento_valido(i, j, x, y, tab, jugadorColor)) {
								// Simular el movimiento
								Pieza* origen = tab[i][j];
								Pieza* destino = tab[x][y];

								//Evitar suicidios: no permitir comerse a su propio rey
								if (destino != nullptr && destino->getColor() == jugadorColor && destino->getTipo() == tipo_pieza::REY)
									continue;

								tab[x][y] = origen;
								tab[i][j] = nullptr;

								bool sigueEnJaque = estaEnJaque(jugadorColor);

								// Deshacer
								tab[i][j] = origen;
								tab[x][y] = destino;

								if (!sigueEnJaque) {
									return false;  // Hay una jugada válida -> no es empate
								}
							}
						}
					}
				}
			}
		}
		std::cout << "Empate por ahogado: no hay jugadas válidas.\n";
		return true;
	}

	return false;  // No es empate
}
