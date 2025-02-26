#include <iostream>
using namespace std;

// void g();

// void f()
// {
// 	g();
// }

// void g() {}

// int main(){

// }


class B;

class A
{
	int a;

public:
	A() : a(1) {}
	int dodajDoB(B _B);

	// friend int razyDwa(A _A);
	friend int dodaj(A _A, B _B);
	// friend int dodaj(A _A);
};

class B
{
	int b;

public:
	B() : b(10) {}

	friend int dodaj(A _A, B _B);
	friend int A::dodajDoB(B _B);
	// friend class A;
};

int A::dodajDoB(B _B)
{
	return a + _B.b;
}

int dodaj(A _A, B _B)
{
	return _A.a + _B.b;
}

/*
int razyDwa(A _A)
{
	// this->
	return 2 * _A.a;
}

int dodaj(A _A, B _B)
{
	return _A.a + _B.b;
}

int dodaj(A _A)
{
	return _A.a;
}
*/

int main()
{
	cout << "Hej" << endl;
	A A1;
	B B1;
	cout << A1.dodajDoB(B1) << endl;
	// cout << A1.a << endl;

	// cout << razyDwa(A1) << endl;
	cout << dodaj(A1, B1) << endl;
	// cout << dodaj(A1) << endl;
	// cout << A1.dodajDoB(B1) << endl;

	return 0;
}
