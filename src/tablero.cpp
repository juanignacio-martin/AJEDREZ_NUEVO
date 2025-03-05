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
	tab = new Pieza* [_N];
	for(int i=0;i<_N;i++){
		tab[i] = new Pieza[_M];
	}
	
	// Inicialización
    tab[0][0] = tab[0][7] = Torre(color::NEGRO); // Torres negras	
    tab[0][1] = tab[0][6] = Caballo(color::NEGRO);; // Caballos negros
    tab[0][2] = tab[0][5] = Alfil(color::NEGRO);; // Alfiles negros
    tab[0][3] = Rey(color::NEGRO);;              // Dama negra
    tab[0][4] = Dama(color::NEGRO);;              // Rey negro
    for (int j = 0; j < _M; ++j) {
        tab[1][j] = peon(color::NEGRO); // Peones negros
    }
	
    //Blancas
    for (int j = 0; j < _M; ++j) {
        tab[6][j] = peon(color::BLANCO);; // Peones blancos
    }
    tab[7][0] = tab[7][7] = Torre(color::BLANCO); // Torres blancas
    tab[7][1] = tab[7][6] = Caballo(color::BLANCO); // Caballos blancos
    tab[7][2] = tab[7][5] = Alfil(color::BLANCO); // Alfiles blancos
    tab[7][3] = Rey(color::BLANCO);              // Dama blanca
    tab[7][4] = Dama(color::BLANCO);              // Rey blanco
	
    // Resto del tablero vacío
    for (int i = 2; i < 6; ++i) {
        for (int j = 0; j < _M; ++j) {
            tab[i][j] = Vacio(color::BLANCO);
        }
    }
	
}
tablero::~tablero() {
	liberacion();
}

void tablero::liberacion()

{
	if (tab != nullptr) {
		for (int i = 0; i < _N; ++i) {
			delete[] tab[i]; // libera cada fila
		}
		delete[] tab; // liberar el vector de punteros
		tab = nullptr;
	}
}

ostream& tablero::print(ostream& o)

{
	for (int i = 0; i < _N; i++) {
		for (int j = 0; j < _M; j++) {
			o << tab[i][j] << " ";
		}
		o << endl;
	}

	return o;
}

Pieza* tablero::operator[](int i) {
    if (i >= 0 && i < _N) {
        return tab[i];
    }
}

const Pieza* tablero::operator[](int i) const {
    if (i >= 0 && i < _N) {
        return tab[i];
    }

}