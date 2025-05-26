#pragma once
#include "ControladorJuego.h"
#include "ControladorMenu.h"
#include "ControladorPromocion.h"
#include "BotFacil.h"
#include "BotMedio.h"
#include "Clasificacion.h"

enum class EstadoApp { MENU_PRINCIPAL, MENU_VARIANTE, MENU_TEMATICA, SELECCION_OPONENTE, JUEGO, PROMOCION, CLASIFICACION };

class ControladorApp {
public:
    ControladorApp();

    void dibujar();
    void manejarClick(int boton, int estado, int x, int y);
    void manejarTecla(unsigned char key, int x, int y);

    EstadoApp getEstado() const { return estado; }
    void cambiarEstado(EstadoApp nuevo);
    void mostrarMenuTematica();
    void mostrarMenuVariante();
    void mostrarMenuPrincipal();
    void iniciarJuego(std::string variante, std::string tema, bool contraBot);
    void mostrarMenuPromocion(int fila, int columna, color c);
    void realizarPromocion(tipo_pieza nuevaPieza);
    void mostrarSeleccionOponente();
    bool contraBotSeleccionado = false;
	int dificultadBot = 1;
    void dibujarPantallaClasificacion();
    void manejarTeclaEspecial(int key, int x, int y);
    //contabilizamos la puntuacion
    int puntuacionFinal = 0;

private:
    EstadoApp estado;
    ControladorMenu menu;
    ControladorJuego* juego = nullptr;
    ControladorPromocion promo;

    // datos de la promoción
    int promFila = -1, promColumna = -1;
    color colorPromocion;
    //declaramos el scroll
    int scrollOffset = 0;

    std::string varianteSeleccionada;
    std::string tematicaSeleccionada;

    std::string nombreJugadorActual = "";
    Clasificacion clasificacion;


};