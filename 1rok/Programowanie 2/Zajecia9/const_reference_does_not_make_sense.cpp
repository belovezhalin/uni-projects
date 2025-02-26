#include <iostream>
using namespace std;

class Kwiatek
{
public:
	int liczbaPlatkow;

	Kwiatek(int lP)
	{
		liczbaPlatkow = lP;
	}
};

int main()
{

	int a = 1;
	int b = 2;

	//---------------------------

	int *i1 = &a;
	*i1 = 3;
	i1 = &b;

	const int *i2 = &a; // "wskaźnik na stałą"
	// *i2 = 1;
	i2 = &b;

	int *const i3 = &a; // "stały wskaźnik"
	*i3 = 1;
	// i3 = &b;

	//---------------------------

	const int &r1 = a; // "referencja na stałą"
	// r1 = 90;
	// a = 90;
	// int& const r2 = a; // referencja z natury jest stała

	int &ref2 = a;
	cout << "!!" << a << endl;
	cout << "---" << &a << endl;
	cout << "---" << &ref2 << endl; // gives address of a, not of reference
	ref2 = b;
	cout << "---" << &ref2 << endl;
	cout << "!!" << a << endl;
	//---------------------------

	// Kwiatek k1(3), k2(5);

	// cout << &k1 << endl;

	// k1 = k2;

	// cout << k1.liczbaPlatkow << endl; //????????

	// cout << &k1 << endl;

	return 0;
}
