#pragma once

#include "freeglut.h"
#include "ETSIDI.h"
#include "math.h"
#include <iostream>
#include "cstring"
#define cas 3

class Tile
{
	//parametros para la casilla, ocupada, apuntada con raton, movimiento posible(por implementar)
	bool color;
	
	 
	bool apuntada = false; //informa si el ratón la está apuntando
	
	int tam = cas;
	

public:
	//Métodos
	void dibucasilla(int i, int j); //Dibuja la casilla. Recibe las coordenadas 

	
	
	

	friend class Board;
};