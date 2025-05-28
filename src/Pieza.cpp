#include "Pieza.h"
#include "ETSIDI.h"
#include "freeglut.h"
#include <iostream>


    ostream& operator<<(std::ostream& os, const Pieza& pieza) {
    std::string tipoStr;
    std::string colorStr;

    // Convertir tipo_pieza a string
    switch (pieza.tipo) {
    case tipo_pieza::TORRE: tipoStr = "TORRE"; break;
    case tipo_pieza::CABALLO: tipoStr = "CABALLO"; break;
    case tipo_pieza::ALFIL: tipoStr = "ALFIL"; break;
    case tipo_pieza::DAMA: tipoStr = "DAMA"; break;
    case tipo_pieza::REY: tipoStr = "REY"; break;
    case tipo_pieza::PEON: tipoStr = "PEON"; break;
    case tipo_pieza::VACIO: tipoStr = "VACIO"; break;
    }

    // Convertir color a string
    switch (pieza.col) {
    case color::BLANCO: colorStr = "BLANCO"; break;
    case color::NEGRO: colorStr = "NEGRO"; break;
    }

    // Formatear la salida
    os << tipoStr << colorStr;
    return os;
}


    std::string tipoPiezaToString(tipo_pieza tipo) {
        switch (tipo) {
        case tipo_pieza::TORRE: return "Torre";
        case tipo_pieza::CABALLO: return "Caballo";
        case tipo_pieza::ALFIL: return "Alfil";
        case tipo_pieza::DAMA: return "Dama";
        case tipo_pieza::REY: return "Rey";
        case tipo_pieza::PEON: return "Peon";
        case tipo_pieza::VACIO: return "Vacío";
        default: return "Desconocido";
        }
    }

