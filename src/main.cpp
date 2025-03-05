#include <iostream>
#include "tablero.h"


using namespace std;


int main() {

	tablero m(8, 8);

	/* salida en consola */
	m.print(cout);
	cout << "*****" << endl;


	m[1][1]->mueve(2, 1); 

	m.print(cout);

}