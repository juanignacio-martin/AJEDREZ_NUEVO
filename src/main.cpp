#pragma once
#include <freeglut.h>
#include "ControladorJuego.h"

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


    gluOrtho2D(0, p->getColumnas() * controlador->getVista().getCeldaSize(), p->getFilas() * controlador->getVista().getCeldaSize(), 0); 

    glutDisplayFunc(displayCallback);
    glutMouseFunc(mouseCallback);
    glutKeyboardFunc(keyboardCallback);

    glutMainLoop();

    delete controlador;
    delete p;
    //test Rama Horatiu
    return 0;
}
