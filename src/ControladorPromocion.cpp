#include "ControladorPromocion.h"
#include "peon.h"
#include <string>

ControladorPromocion::ControladorPromocion() {
    opciones = { tipo_pieza::DAMA, tipo_pieza::TORRE, tipo_pieza::ALFIL, tipo_pieza::CABALLO };
}

void ControladorPromocion::dibujar(color c) {
    glClear(GL_COLOR_BUFFER_BIT);

    for (size_t i = 0; i < opciones.size(); ++i) {
        int x = xInicio;
        int y = yInicio + i * (altoBoton + separacion);

        glColor3f(0.8f, 0.8f, 0.8f);
        glBegin(GL_QUADS);
        glVertex2f(x, y);
        glVertex2f(x + anchoBoton, y);
        glVertex2f(x + anchoBoton, y + altoBoton);
        glVertex2f(x, y + altoBoton);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f);
        std::string texto;
        switch (opciones[i]) {
        case tipo_pieza::DAMA: texto = "Dama"; break;
        case tipo_pieza::TORRE: texto = "Torre"; break;
        case tipo_pieza::ALFIL: texto = "Alfil"; break;
        case tipo_pieza::CABALLO: texto = "Caballo"; break;
        default: texto = "?"; break;
        }
        glRasterPos2f(x + 20, y + altoBoton / 2);
        for (char c : texto) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
        }
    }

    glutSwapBuffers();
}

void ControladorPromocion::manejarClick(int x, int y, Pieza*** tablero, int fila, int columna) {
    for (size_t i = 0; i < opciones.size(); ++i) {
        int x1 = xInicio;
        int y1 = yInicio + i * (altoBoton + separacion);
        int x2 = x1 + anchoBoton;
        int y2 = y1 + altoBoton;

        if (x >= x1 && x <= x2 && y >= y1 && y <= y2) {
            // reutiliza la funcion del peon
            Pieza* actual = tablero[fila][columna];
            if (peon* p = dynamic_cast<peon*>(actual)) {
                p->promocionar(tablero, fila, columna, opciones[i]);
            }
            return;
        }
    }
}
