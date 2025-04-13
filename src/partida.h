#pragma once
<<<<<<< HEAD
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

=======
#include "tablero.h"
#include "jugador.h"

class partida {
private:
    jugador jugadorBlanco;
    jugador jugadorNegro;
    jugador* jugadorActual;
    tablero* t;
    std::string variante;
    int turno;

public:
    partida(const std::string& tipo = "clasico");
    ~partida();

    void jugarTurno(int x1, int y1, int x2, int y2);
    void mostrarTablero() const;
    jugador* getJugadorActual() const;
    bool estaEnJaque() const;

private:
    void inicializarTablero();     // crea el tablero según la variante
    void cambiarTurno();
    void colocarSilverman();
    void colocarDemi();
    void colocarClasico();
};
>>>>>>> main
