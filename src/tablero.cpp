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

	peon::setModoJuego(1);

	if (_N <= 0 || _M <= 0) {
		std::cout << "Error: dimensiones inválidas del tablero" << std::endl;
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
	tab[0][2] = tab[0][5] = new alfil(color::NEGRO);
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
		std::cout << "Error: dimensiones inválidas del tablero" << std::endl;
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

	tab[0][3] = tab[0][0] = new torre(color::NEGRO);
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
	tab[4][3] = tab[4][0] = new torre(color::BLANCO); // Torres blancas
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
				o << ". ";  // Representación de casilla vacía
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
	throw std::out_of_range("Índice fuera de rango");
}

const Pieza* const* tablero::operator[](int i) const {
	if (i >= 0 && i < _N) {
		return tab[i];  // Devuelve const Pieza* const*
	}
	throw std::out_of_range("Índice fuera de rango");
}

bool tablero::mueve_pieza(int x1, int y1, int x2, int y2, color jugadorColor) {

	if (!tab[x1][y1]) return false;

	// ? Validar que la pieza sea del jugador
	if (tab[x1][y1]->getColor() != jugadorColor) {
		std::cout << "Esa pieza no te pertenece." << std::endl;
		return false;
	}



	if (!tab[x1][y1]->movimiento_valido(x1, y1, x2, y2, tab)) {
		std::cout << "Movimiento inválido." << std::endl;
		return false;
	}

	if (tab[x2][y2]) {
		std::cout << "Capturando " << tipoPiezaToString(tab[x2][y2]->getTipo()) << std::endl;
		delete tab[x2][y2];
	}

	tab[x2][y2] = tab[x1][y1];
	tab[x1][y1] = nullptr;
	std::cout << "Moviendo pieza..." << std::endl;

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
		std::cout << "No¡se encontro el rey en el tablero." << std::endl;
		return false;
	}

	// Verificr si alguna pieza rival puede atacar al rey
	for (int i = 0; i < _N; i++) {
		for (int j = 0; j < _M; j++) {
			if (tab[i][j] && tab[i][j]->getColor() != jugadorColor) {
				if (tab[i][j]->movimiento_valido(i, j, reyX, reyY, tab)) {
					std::cout << "Jaque! El rey de " << (jugadorColor == color::BLANCO ? "Blanco" : "Negro")
						<< " esta bajo ataque de un " << tipoPiezaToString(tab[i][j]->getTipo())
						<< " en (" << i << ", " << j << ")." << std::endl;
					return true;
				}
			}
		}
	}

	return false; // No hay jaque
}



void tablero::dibuja(bool tematica)
{	//Base
	glDisable(GL_LIGHTING);
	glColor3ub(128, 128, 128); //color

	//Hay que arreglar esto
	

	glBegin(GL_POLYGON);//para cuadrado
	glVertex3d(-2, 0, -2); //Inferior izquierda
	glVertex3d(-2, 0, square  * _M + 2); //Superior izquierda 
	glVertex3d(square * _N + 2, 0, square * _M + 2); //Superior derecha 
	glVertex3d(square * _N + 2, 0, -2); //Inferior derecha
	glEnd();

	glEnable(GL_LIGHTING);

	

	//Dibujo de las casillas por encima de la base
	for (int i = 0; i < _N; i++) {
		for (int j = 0; j < _M; j++)
			tablero[_N][_M].dibucasilla(i, j);
}
