#include "menu.h"

void menu::inicio()
{
	if (ventana == 0 || ventana == 1) //Menú inicial o menú TEMÁTICA
	{
		dibujaFondo();

		bt1.setEsquina({ 5, 10 }); //ArI
		bt1.dibuja(sonido, ventana, 1);

		bt2.setEsquina({ 5,5 }); //ArD
		bt2.dibuja(sonido, ventana, 2);

		if (ventana == 0)
		{
			bt3.setEsquina({ 3, 10 }); //AbI
			bt3.dibuja(sonido, ventana, 3);
		}

		bt4.setEsquina({ 3,5 }); //AbD
		bt4.dibuja(sonido, ventana, 4);

		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);

	}
	else
	{
		dibujaFondo();

		bt5.setEsquina({ 9, 8 }); //Ar
		bt5.dibuja(sonido, ventana, 1);

		bt6.setEsquina({ 6,8 }); //Medio
		bt6.dibuja(sonido, ventana, 2);

		bt7.setEsquina({ 3,8 }); //Ab
		bt7.dibuja(sonido, ventana, 3);

		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);

		glEnable(GL_TEXTURE_2D);
	}

}

void menu::Tema()
{
	switch (tema)
	{
	case 0: glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("resources/images/MenuSW.png").id); break;
	case 1: glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("resources/images/MenuETSIDI.png").id); break;
	}
}