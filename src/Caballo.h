#include "ETSIDI.h"
#include "Pieza.h"
#include <Vector>
#include <iostream>

class Caballo :public Pieza
{
public:
Caballo(color col)
        :Pieza(tipo_pieza::CABALLO, col)
    {}
~Caballo() {};//destructor
	//void dibuja();
	//int getColor() { return color; }
	//void movimientovalido(int origen, int destino, bool& b);
};
