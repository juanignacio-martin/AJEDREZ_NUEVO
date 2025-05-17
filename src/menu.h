#pragma once
#include "freeglut.h"
#include "ETSIDI.h"
#include "partida.h"
#include "Botones.h"

class menu
{
	bool Menu = true, sonido = true, tope = false;
	bool boton{};
	enum VENTANA { INICIO = 0, TEMATICA, VISION, COMENZAR } ventana{ INICIO };
	enum TEMATICA { SW = 0, ETSIDI } tema{ SW };
	enum VISION { _2D = 0, _3D } vista{ _3D };
	Botones bt1, bt2, bt3, bt4, bt5, bt6, bt7;

public:
	//Métodos
	  //void gestionaMenu();
	void dibujaFondo();
	const bool getMenu() { return Menu; }
	const bool getSonido() { return sonido; }
	const bool getBoton() { return boton; }
	//void setCoord(Punto2D p) { r = p; }
	void setMenu(const bool& valor) { Menu = valor; }
	void setSonido(const bool& valor) { sonido = valor; }
	void setBoton(const bool& valor) { boton = valor; }
	void inicio();
	void clickBotonesMenu();
	void musica() { (sonido) ? ETSIDI::playMusica("resources/sounds/menu2.mp3", true) : ETSIDI::stopMusica(); };
	void Tema();
	int getTema() { return tema; }
	int getVista() { return vista; }
	int getVentana() { return ventana; }

	//Amigos
		//friend class Coordinator;

};