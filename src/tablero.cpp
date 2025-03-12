#include "tablero.h"

using namespace std;

tablero::tablero(int N, int M) :
	_N(N),
	_M(M)
{
	if (N > 0 && M > 0) {
		reserva_inicializacion();

	}
	else { _N = 0, _M = 0;  cout << "error en la dimension de la matriz" << endl; }
}

void tablero::reserva_inicializacion()
{
	// Reserva
	tab = new Pieza * *[_N];
	for (int i = 0; i < _N; i++) {
		tab[i] = new Pieza * [_M];
		for (int j = 0; j < _M; j++) {
			tab[i][j] = nullptr;  // Inicialización a puntero nulo
		}
	}


	// Inicialización
	tab[0][0] = tab[0][7]= new torre(color::NEGRO);
	tab[0][1] = tab[0][6] = new caballo(color::NEGRO);
	tab[0][2] = tab[0][5] = new alfil(color::NEGRO);
	tab[0][3] = new rey(color::NEGRO);
	tab[0][4] = new dama(color::NEGRO);
	for (int j = 0; j < _M; ++j) {
		tab[1][j] = new peon(color::NEGRO);
	}


	//Blancas
	for (int j = 0; j < _M; ++j) {
		tab[6][j] = new peon(color::BLANCO);; // Peones blancos
	}
	tab[7][0] = tab[7][7] = new torre(color::BLANCO); // Torres blancas
	tab[7][1] = tab[7][6] = new caballo(color::BLANCO); // Caballos blancos
	tab[7][2] = tab[7][5] = new alfil(color::BLANCO); // Alfiles blancos
	tab[7][3] = new rey(color::BLANCO);              // Dama blanca
	tab[7][4] = new dama(color::BLANCO);              // Rey blanco


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
				o << *tab[i][j] << " ";  // Desreferencia el puntero para imprimir la pieza
			}
			else {
				o << ". ";  // Representación de casilla vacía
			}
		}
		o << std::endl;
	}
	return o;
}


Pieza** tablero::operator[](int i) {
	if (i >= 0 && i < _N) {
		return tab[i];  // Devuelve `Pieza**`
	}
	throw std::out_of_range("Índice fuera de rango");
}

const Pieza* const* tablero::operator[](int i) const {
	if (i >= 0 && i < _N) {
		return tab[i];  // Devuelve `const Pieza* const*`
	}
	throw std::out_of_range("Índice fuera de rango");
}

void tablero::mueve_pieza(int x_origen, int y_origen, int x_destino, int y_destino) {
	// Verificar que las coordenadas son válidas
	if (x_origen < 0 || x_origen >= _N || y_origen < 0 || y_origen >= _M ||
		x_destino < 0 || x_destino >= _N || y_destino < 0 || y_destino >= _M) {
		std::cout << "Movimiento fuera de los límites del tablero." << std::endl;
		return;
	}

	// Verificar que hay una pieza en la posición de origen
	if (tab[x_origen][y_origen] == nullptr) {
		std::cout << "No hay ninguna pieza en esta casilla." << std::endl;
		return;
	}

	// Verificar que el movimiento es válido según la pieza
	if (!tab[x_origen][y_origen]->movimiento_valido(x_origen, y_origen, x_destino, y_destino, tab)) {
		std::cout << "Movimiento inválido." << std::endl;
		return;
	}

	// Si hay una pieza en destino, verificar si es del enemigo
	if (tab[x_destino][y_destino] != nullptr) {
		if (tab[x_destino][y_destino]->getColor() == tab[x_origen][y_origen]->getColor()) {
			std::cout << "No puedes capturar tu propia pieza." << std::endl;
			return;
		}
		else {
			// Captura de pieza enemiga
			std::cout << "Capturando " << tipoPiezaToString(tab[x_destino][y_destino]->getTipo()) << " enemigo.\n";

			delete tab[x_destino][y_destino];  // Eliminar pieza capturada
		}
	}

	// Mover la pieza
	std::cout << "Moviendo " << tipoPiezaToString(tab[x_origen][y_origen]->getTipo())
		<< " de (" << x_origen << ", " << y_origen << ") a ("
		<< x_destino << ", " << y_destino << ")" << std::endl;


	tab[x_destino][y_destino] = tab[x_origen][y_origen]; // Colocar la pieza en el nuevo lugar
	tab[x_origen][y_origen] = nullptr; // Dejar vacía la casilla de origen
}
