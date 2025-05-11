#pragma once
#pragma once
#include "partida.h"
#include "tablero.h"

class Bot {
public:
    virtual ~Bot() = default;
    virtual void realizarMovimiento(partida& juego) = 0;
};
