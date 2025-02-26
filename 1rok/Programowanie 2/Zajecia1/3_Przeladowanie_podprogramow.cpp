#include <iostream>
#include <string>
using namespace std;

int dodaj(int i, int j)
{
	cout << "Dodawanie dwoch intow" << endl;
	return i + j;
}

double dodaj(double a, double b) {
	cout << "Dodawanie dwoch doubli" << endl;
	return a + b;
}

double dodaj(char a, double b) {
	cout << "Dodawanie char'a i double'a" << endl;
	return (a - 48) + b;
}

double dodaj(string a, double b) {
	cout << "Dodawanie string'a i double'a" << endl;
	return stod(a) + b;
}


int main(int argc)
{
	int x = 2;
	double y = 5.;
	cout << dodaj(x, y) << endl;

	double a = 5.6;
	double b = 7.0;
	cout << dodaj(a, b) << endl;

	char c = '3';
	b = 5;

	cout << c << endl;
	cout << (int)c << endl;
	cout << (int)c - 48 << endl;

	cout << dodaj(c, b) << endl;

	string s = "2a";
	b = 6;
	cout << dodaj(s, b) << endl;

	cin.ignore();
	return 0;
}
