#pragma once
#include "Bot.h"

class BotFacil : public Bot {
public:
	void realizarMovimiento(partida& juego)override;
};
