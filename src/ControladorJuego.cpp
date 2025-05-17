#include "ControladorJuego.h"
#include <freeglut.h>
#include <iostream>


ControladorJuego::ControladorJuego(partida* p)
    : juego(p) {}

void ControladorJuego::dibujar() {
   
    cam.dib(principal);

    switch (state)
    {
    case ESTADO::MENU: 

        if (!principal.getMenu()) {
            //poner una forma de fdferenciar entre la variante seleccionada
            game.inicializarTablero(principal.getTema(), principal.getVista()); //Tema y vision seleccionada por ususario en menu
            principal.getVista() ? cam.position(12.0 + 32 * cos(3.1416), 40.0, 15.0 + 32 * sin(3.1416)) : cam.position(11.9, 35.0, 14.9992); //Selecciona la posición de la camara según la visión seleccionada en el menu
            state = PARTIDA; 
        }
        else
            principal.inicio();
        break;
    
    case ESTADO::PARTIDA:
        //Dibujar segun el modo y la vision
        game.drawpartida(principal.getTema(),principal.getVista());


        //Se gestiona las puntuaciones
        //if (vistatablero.getPuntuaciones()) Puntuaciones();

        //Cambio a estado promocion
        if ()
            state = PROMOCION;
        //Cambio estado a fin
        if ()
            state = FIN, cam.setfin(true);
        break;

    case ESTADO:  PROMOCION:
        //codigo relacionado con el controlador de promocio


        break;
    case ESTADO: FIN:
        
        glEnable(GL_TEXTURE_2D); //Activar 2D

        glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("resources/images/Puntuaciones.png").id);

        glDisable(GL_LIGHTING);
        glBegin(GL_POLYGON);
        glColor3f(1, 1, 1);

        glTexCoord2d(1, 1);    glVertex3f(0, 0, -0.1);
        glTexCoord2d(0, 1);    glVertex3f(0, 16, -0.1);
        glTexCoord2d(0, 0);    glVertex3f(12, 16, -0.1);
        glTexCoord2d(1, 0);    glVertex3f(12, 0, -0.1);
        glEnd();

        glEnable(GL_LIGHTING);
        glDisable(GL_TEXTURE_2D);

       
        break;
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
    }

    glutPostRedisplay();
}

void ControladorJuego::manejarTecla(unsigned char key, int x, int y) {
    if (key == 27) { // ESC para cancelar selección
        seleccionandoOrigen = true;
        std::cout << "Selección cancelada." << std::endl;
    }
}
