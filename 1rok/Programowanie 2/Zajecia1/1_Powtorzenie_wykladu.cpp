#include <iostream>
#include <string>

using namespace std;

void f()
{
	f();
}

// struct
class Kwiatek
{
public:
	int iloscPlatkow;
	int wysokosc;
	char typ; // C = chryzantemy, R - róże..

	Kwiatek(int iloscPlatkow, int wysokosc, char typ)
	{
		this->iloscPlatkow = iloscPlatkow;
		this->wysokosc = wysokosc;
		this->typ = typ;
		// new
	}

	~Kwiatek()
	{
		// delete
	}

	void prezentuj()
	{
		cout << "Kwiatek" << endl;
		cout << "Ilość płatków : " << iloscPlatkow << endl;
		cout << "Wysokość : " << this->wysokosc << endl;
		cout << "Typ : " << (*this).typ << endl;
		cout << endl;
	}
};

int main()
{
	for (int i = 0; i < 10; i++)
	{
		Kwiatek kwiatek(16, 10, 'R');
		kwiatek.prezentuj();
	}

	 Kwiatek kwiatek2(8, 20,'C');
	 kwiatek2.prezentuj();

	// f();

	int x = 10;
	int z = 9;
	double v = 7.7;

	int *px = &x;
	double *pv = &v;

	int sizeOfInt = sizeof(x);
	int sizeOfIntPointer = sizeof(px);
	int sizeOfDoublePointer = sizeof(pv);

	// Operator warunkowy - w ? p : f
	// int* i = NULL;
	// int a=7;
	// i = &a;

	//-std=c++11
	// cout << (i ? *i : "PUSTY");
	// cout << (i ? to_string(*i) : "PUSTY");

	// Operator przecinka - ,

	int i, j, k;

	cout << (i = 2, j = 68, k = 7) << endl;
	cout << i << " " << j << " " << k;

	// Operator rozmiaru - sizeof

	// int i = 9;
	// cout << sizeof(i) << endl;

	// cout << sizeof(char) << endl;

	// Posegreguj:
	/*
	cout << "double: " <<sizeof(double) << endl;
	cout << "long long int: " << sizeof(long long int) << endl;
	cout <<"char: " << sizeof(char) << endl;
	cout << "long int: " << sizeof(long int) << endl;
	cout << "float: "<< sizeof(float) << endl;
	cout <<"int: " << sizeof(int) << endl;
	*/

	struct S
	{
		int a;
		int b;
		double c;
	};

	cout << "S: " << sizeof(S) << endl;

	cin.ignore();
	return 0;
}
