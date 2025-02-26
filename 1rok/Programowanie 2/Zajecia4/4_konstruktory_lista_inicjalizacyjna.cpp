#include <iostream>
#include <string>
using namespace std;

class Beta
{
	int i;

public:
	Beta() : i(10)
	{ // Lista inicjalizacyjna
		cout << "Konstruktor domyslny klasy Beta" << endl;
		//	i = 0;
	}
	Beta(int _i)
	{
		cout << "Konstruktor 1 klasy Beta" << endl;
		i = _i;
	}

	void wyswietl()
	{
		cout << "Obiekt klasy Beta: " << i << endl;
	}
};

class Alpha
{
	double x;
	Beta b;

public:
	Alpha()
	{
		cout << "Konstruktor domyslny klasy Alpha" << endl;
		x = 0;
	}

	Alpha(double _x)
	{
		cout << "Konstruktor 1 klasy Alpha" << endl;
		x = _x;
	}

	Alpha(double _x, int _i) : b(_i)
	{
		cout << "Konstruktor 2 klasy Alpha" << endl;
		x = _x;
	}

	void wyswietl()
	{
		cout << "Obiekt klasy A: " << x << " ";
		b.wyswietl();
	}
};

class Mieszkanie
{
	int numer;

	Mieszkanie(int _numer)
	{
		numer = _numer;
	}
};

class Blok
{
	Mieszkanie mieszkania[5];
	int liczba_mieszkan;

	Blok(int _ilczba_mieszkan)
	{
		//.... (wypełniam mieszkania)
	}

};

int main()
{
	// Beta b;

	// b.wyswietl();

	Alpha a(7, 80);

	a.wyswietl();

	return 0;
}
