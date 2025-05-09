#include "ControladorMenu.h"
#include <string>

ControladorMenu::ControladorMenu() {}

void ControladorMenu::setOpciones(const std::vector<std::string>& opciones, const std::vector<std::function<void()>>& acciones) {
    textos = opciones;
    callbacks = acciones;
}

void ControladorMenu::dibujar() {
    glClear(GL_COLOR_BUFFER_BIT);

    for (size_t i = 0; i < textos.size(); ++i) {
        int x = xInicio;
        int y = yInicio + i * (altoBoton + separacion);

        glColor3f(0.2f, 0.6f, 0.8f);
        glBegin(GL_QUADS);
        glVertex2f(x, y);
        glVertex2f(x + anchoBoton, y);
        glVertex2f(x + anchoBoton, y + altoBoton);
        glVertex2f(x, y + altoBoton);
        glEnd();

        glColor3f(1.0f, 1.0f, 1.0f);
        glRasterPos2f(x + 20, y + altoBoton / 2);
        for (char c : textos[i]) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
        }
    }

    glutSwapBuffers();
}

void ControladorMenu::manejarClick(int x, int y) {
    for (size_t i = 0; i < textos.size(); ++i) {
        int x1 = xInicio;
        int y1 = yInicio + i * (altoBoton + separacion);
        int x2 = x1 + anchoBoton;
        int y2 = y1 + altoBoton;

        if (x >= x1 && x <= x2 && y >= y1 && y <= y2) {
            if (i < callbacks.size()) {
                callbacks[i]();
            }
            return;
        }
    }
}
