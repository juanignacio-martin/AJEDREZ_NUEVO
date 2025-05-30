#include "ControladorPromocion.h"
#include "peon.h"
#include <string>

ControladorPromocion::ControladorPromocion() {
    opciones = { tipo_pieza::DAMA, tipo_pieza::TORRE, tipo_pieza::ALFIL, tipo_pieza::CABALLO };
}




void ControladorPromocion::dibujar(color c) {
    int ANCHO_FIJO = 500;
    int ALTO_FIJO = 500;
    glutReshapeWindow(ANCHO_FIJO, ALTO_FIJO);


    // Configuración de viewport y proyección
    glViewport(0, 0, ANCHO_FIJO, ALTO_FIJO);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, ANCHO_FIJO, ALTO_FIJO, 0);  // origen en esquina superior izquierda
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Dibujar fondo
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("resources/images/MenuPromocion.png").id);

    // Limpiar fondo blanco
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 1.0f, 1.0f); // no alterar color de textura
    glBegin(GL_QUADS);
    glTexCoord2f(0, 0); glVertex2f(0, 0);
    glTexCoord2f(1, 0); glVertex2f(ANCHO_FIJO, 0);
    glTexCoord2f(1, 1); glVertex2f(ANCHO_FIJO, ALTO_FIJO);
    glTexCoord2f(0, 1); glVertex2f(0, ALTO_FIJO);
    glEnd();


    glDisable(GL_TEXTURE_2D);
    glDisable(GL_BLEND);



    // Dibujar botones
    for (size_t i = 0; i < opciones.size(); ++i) {
        int x = xInicio;
        int y = yInicio + i * (altoBoton + separacion);

        // Rectángulo translúcido
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glColor4f(0.8f, 0.8f, 0.8f, 0.5f); // gris semi-transparente
        glBegin(GL_QUADS);
        glVertex2f(x, y);
        glVertex2f(x + anchoBoton, y);
        glVertex2f(x + anchoBoton, y + altoBoton);
        glVertex2f(x, y + altoBoton);
        glEnd();
        glDisable(GL_BLEND);

        // Texto del botón
        glColor3f(0.0f, 0.0f, 0.0f);
        std::string texto;
        switch (opciones[i]) {
        case tipo_pieza::DAMA: texto = "Dama"; break;
        case tipo_pieza::TORRE: texto = "Torre"; break;
        case tipo_pieza::ALFIL: texto = "Alfil"; break;
        case tipo_pieza::CABALLO: texto = "Caballo"; break;
        default: continue;
        }
        glRasterPos2f(x + 20, y + altoBoton * 0.65f);  // mejor centrado vertical
        for (char c : texto) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
        }
    }

    glutSwapBuffers();
}




void ControladorPromocion::manejarClick(int x, int y, Pieza*** tablero, int fila, int columna,partida* pa) {
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
        }

    }
}
void ControladorPromocion::configurarOpciones(const std::string& variante) {
    opciones.clear();
    if (variante == "silverman") {
        opciones.push_back(tipo_pieza::DAMA);
        opciones.push_back(tipo_pieza::TORRE);
    }
    else if (variante == "demi") {
        opciones.push_back(tipo_pieza::ALFIL);
        opciones.push_back(tipo_pieza::CABALLO);
        opciones.push_back(tipo_pieza::TORRE);
    }
    else {  // clásico
        opciones.push_back(tipo_pieza::DAMA);
        opciones.push_back(tipo_pieza::TORRE);
        opciones.push_back(tipo_pieza::ALFIL);
        opciones.push_back(tipo_pieza::CABALLO);
    }
}