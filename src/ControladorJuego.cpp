#include "ControladorJuego.h"
#include <freeglut.h>
#include <iostream>
#include "Partida.h"
#include "ControladorApp.h"
#include "peon.h"

ControladorJuego::ControladorJuego(partida* p, ControladorApp* app)
    : juego(p), app(app) {
    // Ajustar tama�o de ventana al tablero
    int ancho = juego->getColumnas() * vista.getCeldaSize();
    int alto = juego->getFilas() * vista.getCeldaSize();
    glutReshapeWindow(ancho, alto);
    glLoadIdentity();
    gluOrtho2D(0, ancho, alto, 0);
}

void ControladorJuego::dibujar() {
   

    switch (state)
    {
    case ESTADO::MENU: 

        //Aqui se pone la eleccion de camara2d y 3d con una funcion que elija vista.
        // pondra tambien de VISTATABLERO  vista.colocar_camara o algo asi 
    
    case ESTADO::PARTIDA:
        //Dibujar segun el modo y la vision
        partida.drawpartida(puntero.getVision());

    
}

void ControladorJuego::manejarClick(int boton, int estado, int x, int y) {
    if (estado != GLUT_DOWN) return;

    int fila = y / vista.getCeldaSize();
    int columna = x / vista.getCeldaSize();

    if (seleccionandoOrigen) {
        origenX = fila;
        origenY = columna;
        seleccionandoOrigen = false;
    }
    else {
        juego->jugarTurno(origenX, origenY, fila, columna);
        seleccionandoOrigen = true;

        // Detectar si hay promoci�n
        Pieza* pz = juego->getTablero()[fila][columna];
        if (peon* p = dynamic_cast<peon*>(pz)) {
            if ((p->getColor() == color::BLANCO && fila == 0) ||
                (p->getColor() == color::NEGRO && fila == juego->getFilas() - 1)) {
                app->mostrarMenuPromocion(fila, columna, p->getColor());
                return;
            }
        }
    }

    glutPostRedisplay();
}

void ControladorJuego::manejarTecla(unsigned char key, int x, int y) {
    if (key == 27) { // ESC para cancelar selecci�n
        seleccionandoOrigen = true;
        std::cout << "Selecci�n cancelada." << std::endl;
    }
}
