#pragma once
#include <vector>
#include <ctime>
using namespace std;

class Punto2D
{
public:
	double z, x;
	bool operator==(Punto2D p) { return (z == p.z && x == p.x) ? true : false; };
	void operator=(Punto2D p) { z = p.z; x = p.x; };
};

double modulo(Punto2D, Punto2D);
double cronometro(int x);//0 para reiniciar cornometro, 1 para tomar medida desde inicio, 2 para tomar medida desde la anterior medida
