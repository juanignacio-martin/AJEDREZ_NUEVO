#pragma once
#include <freeglut.h>
#include "ControladorJuego.h"
#include "SeleccionVariante.h"

ControladorJuego* controlador = nullptr;
SeleccionVariante* selector = nullptr;

void displayCallback() {
    controlador->dibujar();
}

void mouseCallback(int button, int state, int x, int y) {
    controlador->manejarClick(button, state, x, y);
}

void keyboardCallback(unsigned char key, int x, int y) {
    controlador->manejarTecla(key, x, y);
}

void display() {
    if (!selector->varianteConfirmada()) {
        selector->dibujar();
    }
    else if (!controlador) {
        partida* p = new partida(selector->getVariante());
        controlador = new ControladorJuego(p);
        // Aquí puedes hacer: glutDisplayFunc(...) si tienes otro render
    }
    else {
        controlador->dibujar();  // Reemplaza por tu lógica real de juego
    }
}

void mouse(int button, int state, int x, int y) {
    if (!selector->varianteConfirmada()) {
        selector->manejarClic(button, state, x, y);
    }
    // Podrías redirigir a controlador->manejarClic si el juego está activo
}


int main(int argc, char** argv) {
    std::string variante;
    std::cout << "Elige variante (clasico, silverman, demi): ";
    std::cin >> variante;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Seleccion de Variante");

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 800, 0, 600);

    selector = new SeleccionVariante(800, 600);

    glutDisplayFunc(display);
    glutMouseFunc(mouse);

    glutMainLoop();
    
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

    return 0;
}
