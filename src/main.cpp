#include <iostream>
#include "tablero.h"


using namespace std;

//Crear partida y dentro jugador y tablero

int main() {
    tablero m(8, 4); //Sí Y > 6 dibuja Demi, sí Y<6 dibuja Silver
    

    /* salida en consola */
    m.print(std::cout);
    std::cout << "*****" << std::endl;


    m.mueve_pieza(2, 2, 4, 2);
    // Mover el peón desde (1,1) a (2,1)
    m.mueve_pieza(1, 1, 3, 1);


    m.print(std::cout); // Verificar que el peón realmente se movió

    m.mueve_pieza(4, 2, 3, 1);

    m.print(std::cout); // Verificar que el peón realmente se movió
    m.mueve_pieza(0, 1, 1, 3);

    m.print(std::cout); // Verificar que el peón realmente se movió
    return 0;
}
