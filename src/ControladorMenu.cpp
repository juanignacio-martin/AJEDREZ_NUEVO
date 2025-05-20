#include "ControladorMenu.h"
#include <string>
#include <ETSIDI.h>

ControladorMenu::ControladorMenu() {}

void ControladorMenu::setOpciones(const std::vector<std::string>& opciones, const std::vector<std::function<void()>>& acciones) {
    textos = opciones;
    callbacks = acciones;
}

void ControladorMenu::dibujar() {
    glClear(GL_COLOR_BUFFER_BIT);
    dibujaFondo();
    for (size_t i = 0; i < textos.size(); ++i) {
        int x = xInicio;
        int y;

        // Si es el �ltimo bot�n (suponiendo que es "Empezar")
        if (i == textos.size() - 1) {
            y = yInicio + i * (altoBoton + separacion) + separacionExtra;

            // Dibujar bot�n m�s grande
            glColor3f(0.0f, 0.5f, 0.2f);  // otro color si quieres
            glBegin(GL_QUADS);
            glVertex2f(x, y);
            glVertex2f(x + anchoBoton, y);
            glVertex2f(x + anchoBoton, y + altoBotonGrande);
            glVertex2f(x, y + altoBotonGrande);
            glEnd();

            glColor3f(1.0f, 1.0f, 1.0f);
            glRasterPos2f(x + 20, y + altoBotonGrande / 2);
            for (char c : textos[i]) {
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
            }
        }
        else {
            // Botones normales
            y = yInicio + i * (altoBoton + separacion);
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

void ControladorMenu::dibujaFondo()
{
    glEnable(GL_TEXTURE_2D);

    Tema();
    glDisable(GL_LIGHTING);
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glBegin(GL_QUADS);

    glBegin(GL_QUADS);
    glTexCoord2f(0, 0); glVertex3f(0, 0, -0.1);           // Esquina superior izquierda
    glTexCoord2f(1, 0); glVertex3f(800, 0, -0.1);         // Esquina superior derecha
    glTexCoord2f(1, 1); glVertex3f(800, 600, -0.1);       // Inferior derecha
    glTexCoord2f(0, 1); glVertex3f(0, 600, -0.1);         // Inferior izquierda
    glEnd();

    glDisable(GL_LIGHTING);
    glDisable(GL_TEXTURE_2D);
}
void ControladorMenu::Tema()
{
    switch (tematica)
    {
    case 0: glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("resources/images/menu.png").id); break;
    case 1: glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("resources/images/menu.png").id); break;
    }
}