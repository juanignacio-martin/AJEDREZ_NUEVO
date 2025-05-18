#pragma once
#include "Bot.h"
#include <vector>

class BotFacil : public Bot {
public:
    void jugarTurnoBot(partida* juego); //override;
};