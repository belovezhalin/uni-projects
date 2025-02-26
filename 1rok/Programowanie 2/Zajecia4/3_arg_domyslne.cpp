#include <iostream>
#include <string>
using namespace std;

class A
{
	double x;
	int i;
	string s;

public:
	A() {}

	A(double _x, string _s = "DOMYSLNY", int _i = 9)
	{                                                   // prze�aowanie - mo�liwe inne zachowanie
		cout << "Konstruktor 1 klasy A" << endl;
		x = _x;
		i = _i;
		s = _s;
	}

	void wyswietl()
	{
		cout << "Obiekt klasy A: " << x << " " << s << " " << i << endl;
	}
};

int main()
{
	A a1;
	A a1(5);

	a1.wyswietl();
	//	a1.wyswietl();

	// cin.get();
	// cin.ignore();
	return 0;
}
