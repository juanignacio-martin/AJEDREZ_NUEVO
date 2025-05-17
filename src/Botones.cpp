#pragma once
#include "Botones.h"

void Botones::creaBoton(bool sonido, int ventana, int n_com)
{
	glEnable(GL_TEXTURE_2D);

	cargaTextura(ventana, n_com, sonido);

	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);

	glTexCoord2d(0, 0);    glVertex3f(p1.z, p1.x, 0.01);
	glTexCoord2d(1, 0);    glVertex3f(p1.z, p1.x - 4, 0.01);
	glTexCoord2d(1, 1);    glVertex3f(p1.z - 1.5, p1.x - 4, 0.01);
	glTexCoord2d(0, 1);    glVertex3f(p1.z - 1.5, p1.x, 0.01);

	glEnd();

	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}

void Botones::cargaTextura(int ventana, int n_com, bool sonido)
{
	switch (ventana)
	{
	case 0:		//Inicio
		switch (n_com)
		{
		case 1: sonido ? glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("resources/images/sonido.png").id) : glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("resources/images/sinsonido.png").id); break;
		case 2:glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("resources/images/tematica.png").id); break;
		case 3:glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("resources/images/vision3.png").id); break;
		case 4:glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("resources/images/empezar.png").id); break;
		}
		break;
	case 1:	//Temática	
		switch (n_com)
		{
		case 1:glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("resources/images/starwars.png").id); break;
		case 2:glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("resources/images/UPM.png").id); break;
		case 3: break;
		case 4:glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("resources/images/volver.png").id); break;
		}
		break;
	case 2: //Visión
		switch (n_com)
		{
		case 1:glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("resources/images/2D.png").id); break;
		case 2:glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("resources/images/3D.png").id); break;
		case 3:glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("resources/images/volver.png").id); break;
		}
		break;
	}
}