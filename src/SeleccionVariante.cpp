#include "SeleccionVariante.h"
#include <freeglut.h>

SeleccionVariante::SeleccionVariante(int anchoVentana, int altoVentana)
    : ancho(anchoVentana), alto(altoVentana), variante(""), confirmada(false) {}

bool SeleccionVariante::varianteConfirmada() const {
    return confirmada;
}

std::string SeleccionVariante::getVariante() const {
    return variante;
}

bool SeleccionVariante::clicEnRango(int x, int y, int bx, int by, int bw, int bh) {
    return (x >= bx && x <= bx + bw && y >= by && y <= by + bh);
}

void SeleccionVariante::dibujarBoton(int x, int y, int w, int h, const char* texto) {
    glColor3f(0.2f, 0.2f, 0.8f);
    glBegin(GL_QUADS);
    glVertex2i(x, y);
    glVertex2i(x + w, y);
    glVertex2i(x + w, y + h);
    glVertex2i(x, y + h);
    glEnd();

    glColor3f(1, 1, 1);
    glRasterPos2i(x + 10, y + h / 2 - 5);
    for (const char* c = texto; *c; ++c) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }
}

void SeleccionVariante::dibujar() {
    glClear(GL_COLOR_BUFFER_BIT);

    if (!confirmada) {
        dibujarBoton(100, 400, 200, 50, "Clasico");
        dibujarBoton(100, 300, 200, 50, "Silverman");
        dibujarBoton(100, 200, 200, 50, "Demi");
    }

    glutSwapBuffers();
}

void SeleccionVariante::manejarClic(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && !confirmada) {
        int wy = alto - y;

        if (clicEnRango(x, wy, 100, 400, 200, 50)) {
            variante = "clasico";
            confirmada = true;
        }
        else if (clicEnRango(x, wy, 100, 300, 200, 50)) {
            variante = "silverman";
            confirmada = true;
        }
        else if (clicEnRango(x, wy, 100, 200, 200, 50)) {
            variante = "demi";
            confirmada = true;
        }

        glutPostRedisplay();
    }
}