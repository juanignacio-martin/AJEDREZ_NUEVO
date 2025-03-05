#include <iostream>
#include "tablero.h"


using namespace std;


int main() {

	tablero m(8, 8);

	/* salida en consola */
	m.print(cout);
	cout << "*****" << endl;

	/* modificación de los valores */
	m.cell(0,0,peon(color::BLANCO));


	/* salida en consola */
	m.print(cout);

//	m[1][1].mueve(1, 1);
	/* la memoria se libera adecuadamente? - C++ is awesome!*/


}
