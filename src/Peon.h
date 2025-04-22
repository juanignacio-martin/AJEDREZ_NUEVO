#pragma once
#include "pieza.h"
#include "tablero.h"
class peon : public Pieza
{
public:
    peon(color col)
        :Pieza(tipo_pieza::PEON, col)
    {}
/*    void mueve(int x, int y)override {
        std::cout << "muevo el peon" << x<<y<<std::endl;
    }*/

    bool movimiento_valido(int x_origen, int y_origen, int x_destino, int y_destino, Pieza*** tablero) const override;
    
    void promocionar(Pieza*** pieza_tablero, int x, int y);
};

