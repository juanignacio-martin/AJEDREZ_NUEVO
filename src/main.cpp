#include <iostream>
#include "tablero.h"


using namespace std;


int main() {
    tablero m(8, 8);

    /* salida en consola */
    m.print(std::cout);
    std::cout << "*****" << std::endl;

    // Mover el peón desde (1,1) a (2,1)
    m.mueve_pieza(1, 1, 3, 1);

    m.mueve_pieza(6, 2, 4, 2);

    m.print(std::cout); // Verificar que el peón realmente se movió

    m.mueve_pieza(3, 1, 4, 2);

    m.print(std::cout); // Verificar que el peón realmente se movió

    return 0;
}
