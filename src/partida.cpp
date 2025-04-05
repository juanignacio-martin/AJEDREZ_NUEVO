#include "partida.h"
#include "tablero.h"
#include "jugador.h"
#include <iostream>
#include <string>

using namespace std;

partida::partida()
    : jugadorBlanco (color::BLANCO), jugadorNegro (color::NEGRO), tableroSelec(nullptr)

{

    string eleccion;
    cout << "¿Qué tipo de tablero quieres usar? (Demi/Silver): ";
    cin >> eleccion;

    if (eleccion == "Demi" || eleccion == "demi") {
        tableroSelec = new tablero(8,4);
    }
    else if (eleccion == "Silver" || eleccion == "silver") {
        tableroSelec = new tablero(5,4);
    }
    else {
        cout << "Opción inválida, se seleccionará TableroDemi por defecto." << endl;
        tableroSelec = new tablero(8,4);
    }
}

partida::~partida() {
    delete tableroSelec; // Liberar memoria
}

void partida::mostrarTablero() const {
    tableroSelec -> print(std::cout); // Polimorfismo: llamar a imprimir() según tipo de tablero
}