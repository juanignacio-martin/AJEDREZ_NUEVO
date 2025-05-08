<<<<<<< HEAD
#include "Partida.h"
#include "Jugador.h"

=======
#pragma once
#include <freeglut.h>
#include "ControladorJuego.h"
>>>>>>> main

ControladorJuego* controlador = nullptr;

void displayCallback() {
    controlador->dibujar();
}

void mouseCallback(int button, int state, int x, int y) {
    controlador->manejarClick(button, state, x, y);
}

void keyboardCallback(unsigned char key, int x, int y) {
    controlador->manejarTecla(key, x, y);
}

int main(int argc, char** argv) {
    std::string variante;
    std::cout << "Elige variante (clasico, silverman, demi): ";
    std::cin >> variante;

    partida* p = new partida(variante);
    controlador = new ControladorJuego(p);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(p->getColumnas() * controlador->getVista().getCeldaSize(), p->getFilas() * controlador->getVista().getCeldaSize());
    glutCreateWindow("Ajedrez POO");
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

<<<<<<< HEAD
    while (true) {

        jugador* jugadorActual = p.getJugadorActual();
        color colorJugador = jugadorActual->getColor();

        std::cout << "\nTurno de " << (p.getJugadorActual()->getColor() == color::BLANCO ? "blancas" : "negras") << std::endl;
=======
>>>>>>> main

    gluOrtho2D(0, p->getColumnas() * controlador->getVista().getCeldaSize(), p->getFilas() * controlador->getVista().getCeldaSize(), 0); 

    glutDisplayFunc(displayCallback);
    glutMouseFunc(mouseCallback);
    glutKeyboardFunc(keyboardCallback);

<<<<<<< HEAD
        p.jugarTurno(x1, y1, x2, y2, colorJugador);
        p.mostrarTablero();
    }
=======
    glutMainLoop();

    delete controlador;
    delete p;
>>>>>>> main

    return 0;
}
