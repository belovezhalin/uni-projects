#include <cstdio>
#include "Bateria.h"

Bateria::Bateria() : stanNaladowania(100) {}

unsigned Bateria::getStanNaladowania() const
{
	return stanNaladowania;
}

void Bateria::rozladuj(unsigned ile)
{
	if (ile >= stanNaladowania)
	{
		stanNaladowania = 0;
		printf("Bateria rozladowana\n");
	}
	else
		stanNaladowania -= ile;
}

// bool onoff(){}
