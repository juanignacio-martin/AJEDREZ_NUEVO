#pragma once
#include <freeglut.h>
<<<<<<< HEAD
#include "ControladorJuego.h"
#include "SeleccionVariante.h"

ControladorJuego* controlador = nullptr;
SeleccionVariante* selector = nullptr;
=======
#include "ControladorApp.h"

ControladorApp* app = nullptr;
>>>>>>> main

void displayCallback() {
    app->dibujar();
}

void mouseCallback(int boton, int estado, int x, int y) {
    app->manejarClick(boton, estado, x, y);
}

void keyboardCallback(unsigned char key, int x, int y) {
    app->manejarTecla(key, x, y);
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
<<<<<<< HEAD
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

=======
>>>>>>> main
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(800, 800); // se puede ajustar dinámicamente luego
    glutCreateWindow("Ajedrez POO");

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 800, 800, 0); // origen arriba izquierda

    app = new ControladorApp();

    glutDisplayFunc(displayCallback);
    glutMouseFunc(mouseCallback);
    glutKeyboardFunc(keyboardCallback);

    glutMainLoop();

    delete app;
    return 0;
}
