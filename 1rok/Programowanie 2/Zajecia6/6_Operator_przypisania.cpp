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

	~Tablica()
	{
		delete[] elementy;
		elementy = 0;
	}

	void wstaw(unsigned miejsce, double element)
	{
		if (miejsce > liczbaElementow - 1)
		{
			cout << "Tablica jest za ma�a";
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

	Tablica(const Tablica &t)
	{
		liczbaElementow = t.liczbaElementow;
		elementy = new double[liczbaElementow];
		for (unsigned i = 0; i < liczbaElementow; ++i)
		{
			elementy[i] = t.elementy[i];
		}
		cout << "Konstruktor kopiujacy tablicy" << endl;
	}

	Tablica &operator=(const Tablica &t)
	{
		if (this == &t)
			return *this;

		liczbaElementow = t.liczbaElementow;
		if (elementy)
		{
			delete[] elementy;
			elementy = NULL;
		}
		elementy = new double[liczbaElementow];
		for (unsigned i = 0; i < liczbaElementow; ++i)
		{
			elementy[i] = t.elementy[i];
		}
		cout << "Operator przypisania tablicy" << endl;
		return *this;
	}
};

int main()
{

	Tablica T1(3);
	T1.wstaw(0, 10.);
	T1.wstaw(1, 20.);
	T1.wstaw(2, 30.);
	T1.prezentuj();

	Tablica T2, T3;

	T2.prezentuj();

	T3 = (T2 = T1);

	// T2 = T1;
	// T3 = T2;

	T2.prezentuj();

	/* DODAC DO KLASY
	Tablica& operator=(const Tablica& t) {
		if (this == &t) return *this;

		liczbaElementow = t.liczbaElementow;
		if (elementy) {
			delete[] elementy;
			elementy = NULL;
		}
		elementy = new double[liczbaElementow];
		for (unsigned i = 0; i < liczbaElementow; ++i) {
			elementy[i] = t.elementy[i];
		}
		cout << "Operator przypisania tablicy" << endl;
		return *this;
	}
	*/

	int i, j, k = 9;
	cout << (i = j = k);
	// cout << i;
	// cout << j;
	// cout << k;

	/*

	Tablica T3;
	T3.prezentuj();
	T3 = T1;
	T3.prezentuj();

	T1.wstaw(0, 1000.);

	T3.prezentuj();

	/*
	Tablica T2(T1);
	T2.prezentuj();


	T1.wstaw(0, 1000.);
	T2.prezentuj();
	T1.prezentuj();
	*/

	/*
	Tablica T3;
	T3.prezentuj();
	int i, j, k = 9;
	i = j = k;

	T1.operator=(T2);
	T3 = (T1 = T2);
	T3.prezentuj();
	*/

	// T1.wstaw(0, 1000.);
	// T3.prezentuj();

}
