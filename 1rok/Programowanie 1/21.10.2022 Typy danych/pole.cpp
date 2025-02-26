#include<iostream>
#include<iomanip>
using namespace std;
int main() {
	
	float a,b;
	
	cout << "Podaj pierwszy bok prostokata: ";
	cin >> a;
	cout << "Podaj drugi bok prostokata: ";
	cin >> b;
	cout << "Pole prostokata wynosi: " << a * b << setprecision (2) << fixed << endl;
	return 0;
}
