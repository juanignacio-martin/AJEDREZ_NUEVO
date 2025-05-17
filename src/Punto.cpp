#include "Punto2D.h"
#include "freeglut.h"
#include <math.h>


double modulo(Punto2D a, Punto2D b)
{
	return sqrt(pow((a.x - b.x), 2) + pow((a.z - b.z), 2));
}

double cronometro(int x)//0 para reiniciar cornometro, 1 para tomar medida desde inicio, 2 para tomar medida desde la anterior medida
{
	static unsigned t0, t1, t2;
	if (x == 0)
	{
		t0 = clock();
		return 0;
	}
	if (x == 1)
	{
		t1 = clock();
		double time = (double(t1 - t0) / CLOCKS_PER_SEC);
		return time;
	}
	if (x == 2)
	{
		t2 = clock();
		double time1 = (double(t2 - t1) / CLOCKS_PER_SEC);
		t1 = t2;
		return time1;
	}

}