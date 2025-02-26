#include <iostream>
using namespace std;

struct Kwiatek
{
	int wysokosc;
	int liczbaPlatkow;

	Kwiatek(int x = 10) : liczbaPlatkow(x), wysokosc(89) {}

	Kwiatek &operator=(const Kwiatek &t)
	{
		this->liczbaPlatkow = t.liczbaPlatkow;
		this->wysokosc = t.wysokosc;
		return *this;
	}
	// Kwiatek(Kwiatek &doSkopiowania)
	// {
	// 	liczbaPlatkow = doSkopiowania.liczbaPlatkow;
	// 	wysokosc = doSkopiowania.wysokosc;
	// }
};

int main()
{

	Kwiatek storczyk(20);
	const Kwiatek roza(storczyk);

	Kwiatek orchodea;
	storczyk = orchodea = roza;

	cout << storczyk.liczbaPlatkow << endl;
	cout << roza.liczbaPlatkow << endl;
	cout << orchodea.liczbaPlatkow << endl;

	return 0;
}
