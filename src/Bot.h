#pragma once
class partida;

class Bot {
public:
    virtual ~Bot() = default;
    virtual void jugarTurnoBot(partida* juego) = 0;
};
