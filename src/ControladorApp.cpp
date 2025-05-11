#include "ControladorApp.h"
#include <iostream>

ControladorApp::ControladorApp() {
    estado = EstadoApp::MENU;

    std::vector<std::string> opciones = {
        "Jugar Clasico",
        "Jugar Silverman",
        "Jugar Demi",
        "Salir"
    };

    std::vector<std::function<void()>> acciones = {
        [this]() { iniciarJuego("clasico"); },
        [this]() { iniciarJuego("silverman"); },
        [this]() { iniciarJuego("demi"); },
        []() { exit(0); }
    };

    menu.setOpciones(opciones, acciones);
}

void ControladorApp::dibujar() {
    switch (estado) {
    case EstadoApp::MENU:
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
    case EstadoApp::MENU:
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

void ControladorApp::iniciarJuego(std::string variante) {
    if (juego) delete juego;

    partida* nuevaPartida = new partida(variante);
    juego = new ControladorJuego(nuevaPartida, this);

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
