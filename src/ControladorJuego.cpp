#include "ControladorJuego.h"
#include <freeglut.h>
#include <iostream>
#include "Partida.h"
#include "ControladorApp.h"
#include "peon.h"

ControladorJuego::ControladorJuego(partida* p, ControladorApp* app)
    : juego(p), app(app) {

                      
}

void ControladorJuego::dibujar() {
    vista.dibujar(*juego);
}

void ControladorJuego::manejarClick(int boton, int estado, int x, int y) {
    if (estado != GLUT_DOWN) return;

    int fila = y / vista.getCeldaSize();
    int columna = x / vista.getCeldaSize();

    if (seleccionandoOrigen) {
        origenX = fila;
        origenY = columna;
        seleccionandoOrigen = false;
    }
    else {
        juego->jugarTurno(origenX, origenY, fila, columna);
        seleccionandoOrigen = true;

        // Detectar si hay promoción
        Pieza* pz = juego->getTablero()[fila][columna];
        if (peon* p = dynamic_cast<peon*>(pz)) {
            if ((p->getColor() == color::BLANCO && fila == 0) ||
                (p->getColor() == color::NEGRO && fila == juego->getFilas() - 1)) {
                app->mostrarMenuPromocion(fila, columna, p->getColor());
                return;
            }
        }
        // Si es contra bot y le toca al bot
        if (juego->esContraBot() && juego->getJugadorActual()->getColor() == color::NEGRO) {
            juego->getBot()->jugarTurnoBot(juego);
        }
    }
    glutPostRedisplay();
}

void ControladorJuego::manejarTecla(unsigned char key, int x, int y) {
    if (key == 27) { // ESC para cancelar selección
        seleccionandoOrigen = true;
        std::cout << "Selección cancelada." << std::endl;
    }
}
