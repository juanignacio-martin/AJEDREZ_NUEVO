#include "ControladorJuego.h"
#include <freeglut.h>
#include <iostream>

ControladorJuego::ControladorJuego(partida* p)
    : juego(p) {}

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
    }

    glutPostRedisplay();
}

void ControladorJuego::manejarTecla(unsigned char key, int x, int y) {
    if (key == 27) { // ESC para cancelar selección
        seleccionandoOrigen = true;
        std::cout << "Selección cancelada." << std::endl;
    }
}
