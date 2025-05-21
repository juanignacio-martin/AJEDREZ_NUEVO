#pragma once
#include <vector>
#include <ctime>
using namespace std;

class Punto
{
public:
	double z, x;
	bool operator==(Punto p) { return (z == p.z && x == p.x) ? true : false; };
	void operator=(Punto p) { z = p.z; x = p.x; };
};

double modulo(Punto, Punto);
double cronometro(int x);//0 para reiniciar cornometro, 1 para tomar medida desde inicio, 2 para tomar medida desde la anterior medida
