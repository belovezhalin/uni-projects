#include <iostream>
using namespace std;

class Tablica
{
	double *elementy;
	unsigned liczbaElementow;

public:
	Tablica(unsigned l = 1) : liczbaElementow(l)
	{
		elementy = new double[liczbaElementow];
		for (unsigned i = 0; i < liczbaElementow; ++i)
		{
			elementy[i] = 0;
		}
		cout << "Konstruktor tablicy" << endl;
	}

	void wyczysc()
	{
		delete[] elementy;
	}

	// destruktor - tworzony automatycznie przez kompilator

	~Tablica()
	{
		delete[] elementy;
		elementy = 0;
		cout << "Destruktor tablicy" << endl;
	}

	void zeruj()
	{
		delete[] elementy;
		liczbaElementow = 1;
		elementy = new double[1];
		elementy[0] = 0;
	}

	void wstaw(unsigned miejsce, double element)
	{
		if (miejsce > liczbaElementow - 1)
		{ // kontrola - pola private
			cout << "Tablica jest za mala" << endl;
			return;
		}
		elementy[miejsce] = element;
	}

	void prezentuj()
	{
		cout << "Prezentacja tablicy" << endl;
		for (unsigned i = 0; i < liczbaElementow; i++)
		{
			cout << elementy[i] << endl;
		}
		cout << endl;
	}
};

int main()
{
	{
		Tablica t1(3);
		t1.wstaw(1, 100);
		t1.prezentuj();
	}
	cout << "KONIEC";

	return 0;
}
