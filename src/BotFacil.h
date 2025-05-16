#pragma once
#include "Bot.h"
#include <vector>
#include <utility>

class BotFacil : public Bot {
public:
    void jugarTurnoBot(partida* juego); //override;
};