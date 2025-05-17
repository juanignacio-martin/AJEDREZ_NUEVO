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
    Pieza(tipo_pieza tip = tipo_pieza::VACIO, color col = color::BLANCO, int t, int v)
        : tipo(tip), col(col), tema (t), vista (v){}

    virtual ~Pieza() {}  // Destructor virtual obligatorio para clases base

    // Método virtual puro para validar movimiento
    virtual bool movimiento_valido(int x_origen, int y_origen, int x_destino, int y_destino, Pieza*** tablero) const = 0;

  //  Getters 
    color getColor() const { return col; }
    tipo_pieza getTipo() const { return tipo; }

    bool esVacio() const { return tipo == tipo_pieza::VACIO; }

    friend ostream& operator<<(std::ostream& os, const Pieza& pieza);

    //Metodos interfaz 
    void cambiaTematica(int t) { tema = t; }
    void cambiaVision(int v) { vista = v; }
protected:
    tipo_pieza tipo;
    color col;
    int tema{};             //Tematica del juego, por defecto normal
    int vista = 1;          //Por defecto vista modo 3D

    inline static Model King{ "resources/model/King.obj" };
    inline static Model Queen{ "resources/model/Queen.obj" };
    inline static Model Bishop{ "resources/model/Bishop.obj" };
    inline static Model Rook{ "resources/model/Rook.obj" };
    inline static Model Knight{ "resources/model/Knight.obj" };
    inline static Model Pawn{ "resources/model/Pawn.obj" };
};




//cambi00