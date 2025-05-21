
#include "VistaTablero.h"
#include <freeglut.h>
VistaTablero::VistaTablero()
    : spriteBlancoPeon("resources/images/piezas/blanco_peon.png", 0, 0, 80, 80),
    spriteBlancoTorre("resources/images/piezas/blanco_torre.png", 0, 0, 80, 80),
    spriteBlancoAlfil("resources/images/piezas/blanco_alfil.png", 0, 0, 80, 80),
    spriteBlancoCaballo("resources/images/piezas/blanco_caballo.png", 0, 0, 80, 80),
    spriteBlancoDama("resources/images/piezas/blanco_reina.png", 0, 0, 80, 80),
    spriteBlancoRey("resources/images/piezas/blanco_rey.png", 0, 0, 80, 80),
    spriteNegroPeon("resources/images/piezas/negro_peon.png", 0, 0, 80, 80),
    spriteNegroTorre("resources/images/piezas/negro_torre.png", 0, 0, 80, 80),
    spriteNegroAlfil("resources/images/piezas/negro_alfil.png", 0, 0, 80, 80),
    spriteNegroCaballo("resources/images/piezas/negro_caballo.png", 0, 0, 80, 80),
    spriteNegroDama("resources/images/piezas/negro_reina.png", 0, 0, 80, 80),
    spriteNegroRey("resources/images/piezas/negro_rey.png", 0, 0, 80, 80)
{}
void VistaTablero::dibujar(const partida& p) {
    int ancho = p.getColumnas() * celdaSize;
    int alto = p.getFilas() * celdaSize;

    glutReshapeWindow(ancho, alto);
    glViewport(0, 0, ancho, alto);                  // usa toda la ventana
    glMatrixMode(GL_PROJECTION);                   // cámara
    glLoadIdentity();
    gluOrtho2D(0, ancho, alto, 0);                  // origen arriba izquierda

    glMatrixMode(GL_MODELVIEW);                    // modo modelado
    glLoadIdentity();

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);           // fondo blanco
    glClear(GL_COLOR_BUFFER_BIT);                  // limpiar pantalla


    Pieza*** tablero = p.getTablero();      // obtener el tablero
    int filas = p.getFilas();               // necesitas tener estos getters en partida
    int columnas = p.getColumnas();
    glDisable(GL_TEXTURE_2D);
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            if ((i + j) % 2 == 0)
                glColor3f(1.0f, 1.0f, 1.0f); // blanco
            else
                glColor3f(0.5f, 0.5f, 0.5f); // gris

            glBegin(GL_QUADS);
            glVertex2f(j * celdaSize, i * celdaSize);
            glVertex2f((j + 1) * celdaSize, i * celdaSize);
            glVertex2f((j + 1) * celdaSize, (i + 1) * celdaSize);
            glVertex2f(j * celdaSize, (i + 1) * celdaSize);
            glEnd();

            const Pieza* pieza = tablero[i][j];
            if (pieza != nullptr) {
                ETSIDI::Sprite* sprite = nullptr;

                if (pieza->getColor() == color::BLANCO) {
                    switch (pieza->getTipo()) {
                    case tipo_pieza::PEON: sprite = &spriteBlancoPeon; break;
                    case tipo_pieza::TORRE: sprite = &spriteBlancoTorre; break;
                    case tipo_pieza::ALFIL: sprite = &spriteBlancoAlfil; break;
                    case tipo_pieza::CABALLO: sprite = &spriteBlancoCaballo; break;
                    case tipo_pieza::DAMA: sprite = &spriteBlancoDama; break;
                    case tipo_pieza::REY: sprite = &spriteBlancoRey; break;
                    }
                }
                else {
                    switch (pieza->getTipo()) {
                    case tipo_pieza::PEON: sprite = &spriteNegroPeon; break;
                    case tipo_pieza::TORRE: sprite = &spriteNegroTorre; break;
                    case tipo_pieza::ALFIL: sprite = &spriteNegroAlfil; break;
                    case tipo_pieza::CABALLO: sprite = &spriteNegroCaballo; break;
                    case tipo_pieza::DAMA: sprite = &spriteNegroDama; break;
                    case tipo_pieza::REY: sprite = &spriteNegroRey; break;
                    }
                }

                if (sprite != nullptr) {
                    sprite->setPos(j * celdaSize + 40, i * celdaSize + 40);
                    sprite->setAngle(180);
                    sprite->draw();
                    glDisable(GL_TEXTURE_2D);
                }
            }
        }
    }

    glutSwapBuffers();
}



