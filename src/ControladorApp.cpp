#include "ControladorApp.h"
#include "BotFacil.h"
#include "BotMedio.h"

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
}

void ControladorApp::cambiarEstado(EstadoApp nuevo) {
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