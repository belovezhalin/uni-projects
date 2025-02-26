#include <iostream>
using namespace std;

class C
{
public:
	int a;
	const int b;

	C(int _a, int _b) : a(_a), b(_b) {}

	void setA(int _a) { a = _a; }
	void print() { cout << a << " " << b << " " << endl; }
	void changeB()
	{

		a = 9;
	}
	static const int c = 99;

	//	C(int _a, int _b, int _c) :a(_a), b(_b), c(_c) {}

	void shout()
	{
		a = 10;
		cout << "niestala" << endl;
		cout << a << endl;
		cout << b << endl;
		cout << c << endl;
	}

	mutable int m;
	void shout() const
	{
		m = 90;
		cout << "stala" << endl;
		cout << a << endl;
		// cout << m << endl;
		cout << c << endl;
	}
};

void printSum(const C &_c)
{
	//_c.a = 10;
	cout << _c.a + _c.b << endl;
}

int main()
{

	const C Cconst(100, 200);
	Cconst.shout();
	Cconst.m = 20;
	Cconst.shout();

	cin.ignore();
	return 0;
}
