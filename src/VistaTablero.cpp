
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

    // === 1. DIBUJAR TABLERO ===
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
                ETSIDI::Sprite* sprite = getSprite(pieza);
                if (sprite != nullptr) {
                    sprite->setPos(j * celdaSize + 40, i * celdaSize + 40);
                    sprite->setAngle(180);

                    glPushAttrib(GL_ALL_ATTRIB_BITS);   //  salva el estado
                    glColor3f(1.0f, 1.0f, 1.0f);         // asegura color correcto
                    sprite->draw();
                    glPopAttrib();                      //  restaura estado
                }
            }
        } 
    }


    glutSwapBuffers();
}

ETSIDI::Sprite* VistaTablero::getSprite(const Pieza* pieza) {
    if (!pieza) return nullptr;

    color c = pieza->getColor();

    switch (pieza->getTipo()) {
    case tipo_pieza::PEON:
        return c == color::BLANCO ? &spriteBlancoPeon : &spriteNegroPeon;
    case tipo_pieza::TORRE:
        return c == color::BLANCO ? &spriteBlancoTorre : &spriteNegroTorre;
    case tipo_pieza::CABALLO:
        return c == color::BLANCO ? &spriteBlancoCaballo : &spriteNegroCaballo;
    case tipo_pieza::ALFIL:
        return c == color::BLANCO ? &spriteBlancoAlfil : &spriteNegroAlfil;
    case tipo_pieza::DAMA:
        return c == color::BLANCO ? &spriteBlancoDama : &spriteNegroDama;
    case tipo_pieza::REY:
        return c == color::BLANCO ? &spriteBlancoRey : &spriteNegroRey;
    default:
        return nullptr;
    }
}
void VistaTablero::setTematica(const std::string& tema) {
    tematica = tema;

    if (tematica == "ELECTRONICA") {
        spriteBlancoPeon = ETSIDI::Sprite("resources/images/electro/peonm.png", 0, 0, 80, 80);
        spriteBlancoTorre = ETSIDI::Sprite("resources/images/electro/torrem.png", 0, 0, 80, 80);
        spriteBlancoAlfil = ETSIDI::Sprite("resources/images/electro/alfilm.png", 0, 0, 80, 80);
        spriteBlancoCaballo = ETSIDI::Sprite("resources/images/electro/caballom.png", 0, 0, 80, 80);
        spriteBlancoDama = ETSIDI::Sprite("resources/images/electro/reinam.png", 0, 0, 80, 80);
        spriteBlancoRey = ETSIDI::Sprite("resources/images/electro/reym.png", 0, 0, 80, 80);

        spriteNegroPeon = ETSIDI::Sprite("resources/images/electro/peone.png", 0, 0, 80, 80);
        spriteNegroTorre = ETSIDI::Sprite("resources/images/electro/torree.png", 0, 0, 80, 80);
        spriteNegroAlfil = ETSIDI::Sprite("resources/images/electro/alfile.png", 0, 0, 80, 80);
        spriteNegroCaballo = ETSIDI::Sprite("resources/images/electro/caballoe.png", 0, 0, 80, 80);
        spriteNegroDama = ETSIDI::Sprite("resources/images/electro/reinae.png", 0, 0, 80, 80);
        spriteNegroRey = ETSIDI::Sprite("resources/images/electro/reye.png", 0, 0, 80, 80);
    }
    // Si no es electrónica, se mantienen las piezas por defecto cargadas en el constructor
}