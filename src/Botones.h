#pragma once
#include "ETSIDI.h"
#include"Punto.h"


class Botones
{
	Punto2D p1{};		//Esquina superior derecha
	bool BotonSonido{};	//Indica si es de sonido el botón para poder tachar el cuadro o no

public:
	//Métodos
	Punto2D getEsquinaDrchaCuadro() { return p1; }
	void setEsquina(Punto2D punto) { p1 = punto; }
	void setSound() { BotonSonido = true; }
	bool getSound() { return BotonSonido; }
	void dibuja(bool sonido, int ventana, int n_com) { creaBoton(sonido, ventana, n_com); };
	void creaBoton(bool sonido, int ventana, int n_com);
	void cargaTextura(int ventana, int n_com, bool sonido);


};
