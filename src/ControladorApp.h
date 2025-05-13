#pragma once
#include "ControladorJuego.h"
#include "ControladorMenu.h"
#include "ControladorPromocion.h"

enum class EstadoApp { MENU,SELECCION_OPNENTE, JUEGO, PROMOCION };

class ControladorApp {
public:
    ControladorApp();

    void dibujar();
    void manejarClick(int boton, int estado, int x, int y);
    void manejarTecla(unsigned char key, int x, int y);

    EstadoApp getEstado() const { return estado; }
    void cambiarEstado(EstadoApp nuevo);

    void iniciarJuego(std::string variante);
    void mostrarMenuPromocion(int fila, int columna, color c);
    void realizarPromocion(tipo_pieza nuevaPieza);

private:
    EstadoApp estado;
    ControladorMenu menu;
    ControladorJuego* juego = nullptr;
    ControladorPromocion promo;

    // datos de la promoci�n
    int promFila = -1, promColumna = -1;
    color colorPromocion;
};
