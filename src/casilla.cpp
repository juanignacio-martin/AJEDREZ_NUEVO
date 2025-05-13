#include "casilla.h"

void Casilla::dibucasilla(int i, int j)
{
	glEnable(GL_TEXTURE_2D);

	(color ? glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("resources/images/WhiteTileSW.png").id) : glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("resources/images/BlackTileSW.png").id)))));



	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);

	glTexCoord2d(0, 1); glVertex3d(i * tam, 0.01, j * tam);
	glTexCoord2d(1, 1); glVertex3d(i * tam, 0.01, tam * (j + 1));
	glTexCoord2d(1, 0); glVertex3d(tam * (i + 1), 0.01, tam * (j + 1));
	glTexCoord2d(0, 0); glVertex3d(tam * (i + 1), 0.01, j * tam);
	glEnd();

	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);



}