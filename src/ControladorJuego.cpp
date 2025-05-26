#include "ControladorJuego.h"
#include <freeglut.h>
#include <iostream>
#include "Partida.h"
#include "ControladorApp.h"
#include "peon.h"
#include "Puntuacion.h"

ControladorJuego::ControladorJuego(partida* p, ControladorApp* app, const std::string& tematica)
    : juego(p), app(app) {

    vista.setTematica(tematica);
}

void ControladorJuego::dibujar() {
    vista.dibujar(*juego);

    // Si se ha terminado la partida, cambiamos de estado DESPUÉS de dibujar 
    if (juego->haFinalizado()) {
        static bool transicionHecha = false;
        if (!transicionHecha) {
            transicionHecha = true;
            app->puntuacionFinal = Puntuacion::calcular(*juego);
            app->cambiarEstado(EstadoApp::CLASIFICACION);
        }
    }
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
        bool exito = juego->jugarTurno(origenX, origenY, fila, columna);
        seleccionandoOrigen = true;

        if (!exito) return;

        // Detectar si hay promoción
        Pieza* pz = juego->getTablero()[fila][columna];
        if (peon* p = dynamic_cast<peon*>(pz)) {
            if ((p->getColor() == color::BLANCO && fila == 0) ||
                (p->getColor() == color::NEGRO && fila == juego->getFilas() - 1)) {
                app->mostrarMenuPromocion(fila, columna, p->getColor());
                return;
            }
        }

        if (juego->esContraBot() && juego->getJugadorActual()->getColor() == color::NEGRO) {
            juego->getBot()->jugarTurnoBot(juego);

            if (juego->haFinalizado()) {
                std::cout << "Fin de la partida.\n";
                return;
            }
        }

        glutPostRedisplay();
    }
}


void ControladorJuego::manejarTecla(unsigned char key, int x, int y) {
    if (key == 27) { // ESC para cancelar selección
        seleccionandoOrigen = true;
        std::cout << "Selección cancelada." << std::endl;
    }
}
