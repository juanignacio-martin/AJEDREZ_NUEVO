#pragma once
#include "pieza.h"
#include "tablero.h"
class peon : public Pieza
{
<<<<<<< HEAD
    static int modo_juego; // 0 = Clásico/Demi, 1 = Silverman
=======
    static int modo_juego; // 0 = ClÃ¡sico/Demi, 1 = Silverman
>>>>>>> main
    static int ultima_fila_doble;
    static int ultima_columna_doble;

    static void registrarMovimientoDoble(int fila, int columna);

public:
    peon(color col)
        :Pieza(tipo_pieza::PEON, col)
    {}
    /*    void mueve(int x, int y)override {
            std::cout << "muevo el peon" << x<<y<<std::endl;
        }*/

    bool movimiento_valido(int x_origen, int y_origen, int x_destino, int y_destino, Pieza*** tablero, color jugadorColor) const override;

    void promocionar(Pieza*** pieza_tablero, int x, int y);

    static void setModoJuego(int modo); // Cambia el modo de juego
<<<<<<< HEAD
};
=======
};
>>>>>>> main
