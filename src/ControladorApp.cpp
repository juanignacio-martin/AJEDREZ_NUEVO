#include "ControladorApp.h"
#include "BotFacil.h"
#include "BotMedio.h"
#include <algorithm>

#include <iostream>

ControladorApp::ControladorApp() {
    estado = EstadoApp::MENU_PRINCIPAL;
    mostrarMenuPrincipal();

    std::vector<std::string> opciones = {
        "Variante",
        "Tematica",
        "Seleccionar Oponente",
        "Empezar",
        "Salir"
    };

    std::vector<std::function<void()>> acciones = {
    [this]() { mostrarMenuVariante(); },
    [this]() { mostrarMenuTematica(); },
    [this]() { mostrarSeleccionOponente(); },
    [this]() { iniciarJuego(varianteSeleccionada, tematicaSeleccionada,1); }

    };


}
void ControladorApp::mostrarMenuVariante() {
    estado = EstadoApp::MENU_VARIANTE;

    std::vector<std::string> opciones = {
        "Jugar Clasico",
        "Jugar Silverman",
        "Jugar Demi",
        "Volver"
    };

    std::vector<std::function<void()>> acciones = {
        [this]() { varianteSeleccionada = "clasico"; mostrarMenuPrincipal(); },
        [this]() { varianteSeleccionada = "silverman"; mostrarMenuPrincipal(); },
        [this]() { varianteSeleccionada = "demi"; mostrarMenuPrincipal(); },
        [this]() { mostrarMenuPrincipal(); }
    };
    int seleccionado = 0;
    if (varianteSeleccionada == "silverman") seleccionado = 1;
    else if (varianteSeleccionada == "demi") seleccionado = 2;

    menu.setIndiceSeleccionado(seleccionado);
    menu.setOpciones(opciones, acciones);
}

void ControladorApp::mostrarMenuTematica() {
    estado = EstadoApp::MENU_TEMATICA;

    std::vector<std::string> opciones = {
        "CLASICO",
        "ELECTRONICA",
        "Volver"
    };

    std::vector<std::function<void()>> acciones = {
        [this]() { tematicaSeleccionada = "CLASICO"; mostrarMenuPrincipal(); },
        [this]() { tematicaSeleccionada = "ELECTRONICA"; mostrarMenuPrincipal(); },
        [this]() { mostrarMenuPrincipal(); }
    };

    menu.setOpciones(opciones, acciones);
}
void ControladorApp::mostrarMenuPrincipal() {
    estado = EstadoApp::MENU_PRINCIPAL;

    std::vector<std::string> opciones = {
        "VARIANTE",
        "TEMATICA",
        "OPONENTE",
        "Empezar"
    };

    std::vector<std::function<void()>> acciones = {
        [this]() { mostrarMenuVariante(); },
        [this]() { mostrarMenuTematica(); },
        [this]() { mostrarSeleccionOponente(); },
        [this]() { iniciarJuego(varianteSeleccionada,tematicaSeleccionada,contraBotSeleccionado); }
    };

    menu.setOpciones(opciones, acciones);
}
void ControladorApp::mostrarSeleccionOponente() {
    std::vector<std::string> opciones = {
        "VS HUMANO",
        "VS BOT FACIL",
        "VS BOT MEDIO",
        "VOLVER"
    };

    std::vector<std::function<void()>> acciones = {
         [this]() { contraBotSeleccionado = false; mostrarMenuPrincipal(); },
        [this]() { contraBotSeleccionado = true; dificultadBot = 1; mostrarMenuPrincipal(); },
        [this]() { contraBotSeleccionado = true; dificultadBot = 2; mostrarMenuPrincipal(); },

        [this]() { mostrarMenuPrincipal(); }
        /*[this]() { iniciarJuego(varianteSeleccionada,tematicaSeleccionada, false); },
        [this]() { iniciarJuego(varianteSeleccionada, tematicaSeleccionada, true); }*/
    };

    menu.setOpciones(opciones, acciones);
}

void ControladorApp::dibujar() {
    switch (estado) {
    case EstadoApp::MENU_PRINCIPAL:
    case EstadoApp::MENU_TEMATICA:
    case EstadoApp::MENU_VARIANTE:
    case EstadoApp::SELECCION_OPONENTE:
        menu.dibujar(); break;
    case EstadoApp::JUEGO:
        if (juego) juego->dibujar(); break;
    case EstadoApp::PROMOCION:
        promo.dibujar(colorPromocion); break;
    case EstadoApp::CLASIFICACION:
        dibujarPantallaClasificacion();break;
    }
}

void ControladorApp::manejarClick(int boton, int estadoClick, int x, int y) {
    if (estadoClick != GLUT_DOWN) return;

    switch (estado) {
    case EstadoApp::MENU_PRINCIPAL:
    case EstadoApp::MENU_TEMATICA:
    case EstadoApp::MENU_VARIANTE:
    case EstadoApp::SELECCION_OPONENTE:
        menu.manejarClick(x, y);
        break;

    case EstadoApp::JUEGO:
        if (juego) juego->manejarClick(boton, estadoClick, x, y);
        break;

    case EstadoApp::PROMOCION:
        if (juego) promo.manejarClick(x, y, juego->getTablero(), promFila, promColumna);
        cambiarEstado(EstadoApp::JUEGO);
        break;
    }
}

void ControladorApp::manejarTecla(unsigned char key, int x, int y) {

    if (estado == EstadoApp::JUEGO && juego)
        juego->manejarTecla(key, x, y);
    else if (estado == EstadoApp::CLASIFICACION) {
        if (key == 13) {  // ENTER
            if (!nombreJugadorActual.empty()) {
                clasificacion.agregar(nombreJugadorActual, 100);         // puntuación fija
                clasificacion.guardar("ranking.txt");                    // guardamos en archivo
                // Restablecer ventana
                glutReshapeWindow(1500, 1000);

                // Restaurar sistema de coordenadas
                glMatrixMode(GL_PROJECTION);
                glLoadIdentity();
                gluOrtho2D(0, 1500, 1000, 0);

                cambiarEstado(EstadoApp::MENU_PRINCIPAL);

                glutPostRedisplay();
            }
        }else if (key == 8 || key == 127) { // BACKSPACE
            if (!nombreJugadorActual.empty()) {
                nombreJugadorActual.pop_back();
            }
        }
        else if (isalnum(key) || key == ' ') {
            if (nombreJugadorActual.length() < 20) {
                nombreJugadorActual += key;
            }
        }
        glutPostRedisplay();
    }
}

void ControladorApp::cambiarEstado(EstadoApp nuevo) {
    if (nuevo == EstadoApp::CLASIFICACION) {
        clasificacion.cargar("ranking.txt");
    }
    estado = nuevo;
}

void ControladorApp::iniciarJuego(std::string variante, std::string tema, bool contraBot) {
    if (juego) delete juego;

    partida* nuevaPartida = new partida(variante);
    if (contraBot) {
		if (dificultadBot == 1) {
			nuevaPartida->setBot(new BotFacil());
		}
		else if (dificultadBot == 2) {
            nuevaPartida->setBot(new BotMedio());
		}
		
    }
    juego = new ControladorJuego(nuevaPartida, this, tematicaSeleccionada);

    int ancho = nuevaPartida->getColumnas() * 100;
    int alto = nuevaPartida->getFilas() * 100;

    glutReshapeWindow(ancho, alto);
    glLoadIdentity();
    gluOrtho2D(0, ancho, alto, 0);  // sistema de coordenadas ajustado

    estado = EstadoApp::JUEGO;
}


void ControladorApp::mostrarMenuPromocion(int fila, int columna, color c) {
    promFila = fila;
    promColumna = columna;
    colorPromocion = c;
    estado = EstadoApp::PROMOCION;
}

void ControladorApp::realizarPromocion(tipo_pieza nuevaPieza) {
    // esta función queda reservada por si quieres forzar promociones desde fuera
}

void ControladorApp::manejarTeclaEspecial(int key, int x, int y) {
    if (estado == EstadoApp::CLASIFICACION) {
        if (key == GLUT_KEY_UP) {
            scrollOffset = (scrollOffset - 20 > 0) ? (scrollOffset - 20) : 0;
        }
        else if (key == GLUT_KEY_DOWN) {
            scrollOffset += 20;
        }
        glutPostRedisplay();
    }
}

void ControladorApp::dibujarPantallaClasificacion() {
    // Tamaño de ventana actual
    int w = glutGet(GLUT_WINDOW_WIDTH);
    int h = glutGet(GLUT_WINDOW_HEIGHT);

    // Fondo azul oscuro
    glClearColor(0.0f, 0.1f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Puntuación y posición del jugador actual
    int puntuacionActual = 100; // Por ahora fija
    int posicionActual = 1;     // Por ahora fija

    std::string puntuacionStr = "Tu puntuacion es: " + std::to_string(puntuacionActual);
    std::string posicionStr = "Tu posicion en el ranking es: " + std::to_string(posicionActual);

    glColor3f(1.0f, 1.0f, 1.0f);
    int anchoPunt = puntuacionStr.length() * 12;
    int anchoPos = posicionStr.length() * 12;

    // Posiciones relativas a la entrada de nombre
    int yNombre = 140;

    glRasterPos2i((w - anchoPunt) / 2, yNombre - 70);
    for (char c : puntuacionStr) glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);

    glRasterPos2i((w - anchoPos) / 2, yNombre - 40);
    for (char c : posicionStr) glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);

    // Campo de entrada de nombre
    std::string pedir = "Introduce tu nombre:";
    int anchoPedir = pedir.length() * 12;
    glRasterPos2i((w - anchoPedir) / 2, yNombre);
    for (char c : pedir) glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);

    // Fondo del campo de entrada
    int inputBoxWidth = w * 2 / 3;
    int inputBoxX = (w - inputBoxWidth) / 2;
    glColor3f(0.9f, 0.9f, 0.9f);
    glBegin(GL_QUADS);
    glVertex2f(inputBoxX, yNombre + 10);
    glVertex2f(inputBoxX + inputBoxWidth, yNombre + 10);
    glVertex2f(inputBoxX + inputBoxWidth, yNombre + 50);
    glVertex2f(inputBoxX, yNombre + 50);
    glEnd();

    // Texto dentro del campo
    glColor3f(0.0f, 0.0f, 0.2f);
    glRasterPos2i(inputBoxX + 20, yNombre + 40);
    std::string linea = nombreJugadorActual + "_";
    for (char c : linea) glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);

    // Línea separadora 
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_LINES);
    glVertex2f(inputBoxX, yNombre + 70);
    glVertex2f(w - inputBoxX, yNombre + 70);
    glEnd();

    // Título clasificación
    glColor3f(1.0f, 1.0f, 1.0f);
    std::string titulo = "CLASIFICACION FINAL";
    int anchoTitulo = titulo.length() * 14;
    glRasterPos2i((w - anchoTitulo) / 2, yNombre + 100);
    for (char c : titulo)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, toupper(c));

    // Parámetros de tarjetas
    int cardHeight = 60;
    int spacing = 20;
    int startY = yNombre + 140;
    int cardWidth = w * 2 / 3;
    int x = w / 6;

    // Recorte visual: solo muestra tarjetas que estén visibles
    const auto& top = clasificacion.obtenerEntradas();
    for (size_t i = 0; i < top.size(); ++i) {
        int y = startY + static_cast<int>(i) * (cardHeight + spacing) - scrollOffset;

        if (y + cardHeight < 0 || y > h)
            continue; // fuera de vista, no se dibuja, cambiar

        // Fondo de la tarjeta
        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_QUADS);
        glVertex2f(x, y);
        glVertex2f(x + cardWidth, y);
        glVertex2f(x + cardWidth, y + cardHeight);
        glVertex2f(x, y + cardHeight);
        glEnd();

        // Texto del jugador
        glColor3f(0.0f, 0.0f, 0.2f);
        glRasterPos2i(x + 20, y + 40);
        std::string linea = std::to_string(i + 1) + ". " + top[i].nombre;
        for (char c : linea)
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);

        // Puntuación (alineado derecha)
        std::string puntos = std::to_string(top[i].puntuacion) + " pts";
        int anchoTexto = puntos.length() * 10;
        glRasterPos2i(x + cardWidth - anchoTexto - 20, y + 40);
        for (char c : puntos)
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }

    glutSwapBuffers();
}






