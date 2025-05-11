#pragma once
#include <freeglut.h>
#include "ControladorApp.h"

ControladorApp* app = nullptr;

void displayCallback() {
    app->dibujar();
}

void mouseCallback(int boton, int estado, int x, int y) {
    app->manejarClick(boton, estado, x, y);
}

void keyboardCallback(unsigned char key, int x, int y) {
    app->manejarTecla(key, x, y);
}

int main(int argc, char** argv) {
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