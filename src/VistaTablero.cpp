
#include "VistaTablero.h"
#include <freeglut.h>
void VistaTablero::dibujaV(const partida& p) {
    glClear(GL_COLOR_BUFFER_BIT);

    Pieza*** tablero = p.getTablero();      // obtener el tablero
    int filas = p.getFilas();               // necesitas tener estos getters en partida
    int columnas = p.getColumnas();

    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            if ((i + j) % 2 == 0)
                glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("resources/images/WhiteTileSW.png").id);
            else
                glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("resources/images/BlackTileSW.png").id);

            glBegin(GL_QUADS);
            glVertex2f(j * celdaSize, i * celdaSize);
            glVertex2f((j + 1) * celdaSize, i * celdaSize);
            glVertex2f((j + 1) * celdaSize, (i + 1) * celdaSize);
            glVertex2f(j * celdaSize, (i + 1) * celdaSize);
            glEnd();

            const Pieza* pieza = tablero[i][j];
            if (pieza != nullptr) {
                char simbolo = obtenerSimbolo(pieza);
                if (pieza->getColor() == color::BLANCO)
                    glColor3f(0.0f, 0.0f, 0.0f);
                else
                    glColor3f(1.0f, 0.0f, 0.0f);

                glRasterPos2f(j * celdaSize + 25, i * celdaSize + 50);
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, simbolo);
            }
        }
    }

    glutSwapBuffers();
}

/*
char VistaTablero::obtenerSimbolo(const Pieza* pieza) {
    if (!pieza) return ' ';
    switch (pieza->getTipo()) {
    case tipo_pieza::PEON: return 'P';
    case tipo_pieza::TORRE: return 'T';
    case tipo_pieza::REY: return 'R';
    case tipo_pieza::DAMA: return 'D';
    case tipo_pieza::ALFIL: return 'A';
    case tipo_pieza::CABALLO: return 'C';
    default: return ' ';
    }
}
*/