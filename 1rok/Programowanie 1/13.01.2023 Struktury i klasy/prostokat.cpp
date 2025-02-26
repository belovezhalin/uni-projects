#include <iostream>
using namespace std;

class prostokat {
	public:
		float a;
		float b;
		float pole;
		
		void wczytaj_dane() {
		cout << "Podal bok a: "; 
		cin >> a;
		cout << "Podaj bok b: ";
		cin << b;}
		
		void policz_pole () {
		pole = a * b;}
		
		void wyswietl_wynik () {cout << "Pole prostokata o boku a = " << setprecision(2) << fixed << a << " i boku b = "<< setprecision(2) << fixed << b << "wynosi " << pole << endl;}
};

int main() {
	
	cout << "Obliczenie pola prostokata: " << endl;
	
	
	return 0;
}
