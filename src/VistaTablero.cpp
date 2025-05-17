
#include "VistaTablero.h"
#include <iostream>
#define mirax 12.0
#define miray 0.0
#define miraz 15.0

//Establece posiciones iniciales de la camara tanto en el menu como al iniciar la partida
void vistatablero::dib(menu& principal)
{

    if (principal.getMenu())
    {
        gluLookAt(6, 8, 16,  // posicion del ojo
            6, 8, 0,      // hacia que punto mira  
            1.0, 0.0, 0.0);      // definimos visión hacia arriba (eje X)
    }
    else if (!vistaPuntuaciones && !fin)
    {
        gluLookAt(posx, posy, posz,  // posicion del ojo
            mirax, miray, miraz,      // hacia que punto mira  
            0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)  
    }
    else
    {
        gluLookAt(7.5, 8, 8,  // posicion del ojo   
            7.5, 8, 0,      // hacia que punto mira   
            0.0, 1.0, 0.0);      // definimos hacia arriba  
    }

}



//Permite acercar la camara al tablero al pulsar '+' y alejarla al pulsar '-'
void vistatablero::zoom(menu& principal, unsigned char key)
{
    if (!principal.getMenu() && estatico && principal.getVision())
    {
        double zoom = 0.5; // Ajusta el factor de zoom según sea necesario

        double dirx = mirax - posx;
        double diry = miray - posy;
        double dirz = miraz - posz;

        // Normaliza el vector de dirección
        double modulodir = sqrt(dirx * dirx + diry * diry + dirz * dirz);
        double unitariodirx = dirx / modulodir;
        double unitariodiry = diry / modulodir;
        double unitariodirz = dirz / modulodir;

        if (key == '+' && zoomin < 30)
        {
            // Mueve el punto de mira en la dirección opuesta al vector de dirección de la cámara
            posx = posx + unitariodirx * zoom;
            posy = posy + unitariodiry * zoom;
            posz = posz + unitariodirz * zoom;
            zoomin = zoomin + 1;
            zoomout = zoomout - 1;
        }

        else if (key == '-' && zoomout < 20)
        {
            // Mueve el punto de mira en la dirección del vector de dirección de la cámara
            posx = posx - unitariodirx * zoom;
            posy = posy - unitariodiry * zoom;
            posz = posz - unitariodirz * zoom;
            zoomin = zoomin - 1;
            zoomout = zoomout + 1;
        }

        else if (key == 'p' || key == 'P')  vistaPuntuaciones = true;

        else if (key == 'j' || key == 'J') vistaPuntuaciones = false;
    }
}



