#pragma once
#include "ETSIDI.h"
#include <vector>
#include <iostream>
using namespace std;

enum class color { BLANCO, NEGRO };  // Define Color
enum class tipo_pieza { TORRE, CABALLO, ALFIL, DAMA, REY, PEON, VACIO };


std::string tipoPiezaToString(tipo_pieza tipo);

class Pieza {
public:
    Pieza(tipo_pieza tip = tipo_pieza::VACIO, color col = color::BLANCO)
        : tipo(tip), col(col) {}

    virtual ~Pieza() {}  // Destructor virtual obligatorio para clases base

    // Método virtual puro para validar movimiento
    virtual bool movimiento_valido(int x_origen, int y_origen, int x_destino, int y_destino, Pieza*** tablero, color jugadorColor) const = 0;

  //  Getters 
    color getColor() const { return col; }
    tipo_pieza getTipo() const { return tipo; }

    bool esVacio() const { return tipo == tipo_pieza::VACIO; }

    friend ostream& operator<<(std::ostream& os, const Pieza& pieza);

protected:
    tipo_pieza tipo;
    color col;
};
