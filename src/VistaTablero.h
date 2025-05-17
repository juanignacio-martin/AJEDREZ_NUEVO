#pragma once
#include "freeglut.h"
#include "math.h"
#include "menu.h"

class vistatablero
{
	double posx;
	double posy;
	double posz;

	double up = 0;
	double down = 0;
	double zoomin = 0;
	double zoomout = 0;
	bool rotate = FALSE;
	bool modolibre = FALSE;
	bool estatico = TRUE;
	bool vistaPuntuaciones{};
	bool fin = false; //Fin del juego

public:
	//Constructor
	vistatablero() { posx = -20.0; posy = 40.0; posz = 15.0; };
	//Métodos
	void position(double _posx, double _posy, double _posz) { posx = _posx; posy = _posy; posz = _posz; };
	void dib(menu& principal);
	void zoom(menu& principal, unsigned char key);
	bool Cambiando() { return !estatico; }
	bool getPuntuaciones() { return vistaPuntuaciones; }
	void setVistaPuntuaciones(bool c) { vistaPuntuaciones = c; }

	void setfin(const bool& f) { fin = f; }
	bool getfin() { return fin; }


};

