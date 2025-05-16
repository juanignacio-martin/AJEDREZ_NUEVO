#pragma once
#include "ControladorJuego.h"
#include "ControladorMenu.h"
#include "ControladorPromocion.h"
#include "BotFacil.h"

enum class EstadoApp { MENU,SELECCION_OPONENTE, JUEGO, PROMOCION };

class ControladorApp {
public:
    ControladorApp();

    void dibujar();
    void manejarClick(int boton, int estado, int x, int y);
    void manejarTecla(unsigned char key, int x, int y);

    EstadoApp getEstado() const { return estado; }
    void cambiarEstado(EstadoApp nuevo);

    void iniciarJuego(std::string variante,bool contraBot);
    void mostrarMenuPromocion(int fila, int columna, color c);
    void realizarPromocion(tipo_pieza nuevaPieza);
    void mostrarSeleccionOponente();

private:
    EstadoApp estado;
    ControladorMenu menu;
    ControladorJuego* juego = nullptr;
    ControladorPromocion promo;

    // datos de la promoción
    int promFila = -1, promColumna = -1;
    color colorPromocion;

    std::string varianteSeleccionada;
};
