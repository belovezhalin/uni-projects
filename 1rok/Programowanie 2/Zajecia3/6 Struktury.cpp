#include <iostream>
#include <string>
using namespace std;


struct Samochod {
	string marka;
	string model;
	unsigned przebieg;
};

void ustawPolaSamochodu(Samochod &s, string _marka, string _model, unsigned _przebieg) {
	s.marka = _marka,
	s.model = _model;
	s.przebieg = _przebieg;
}

void prezentuj(Samochod const &s) {
	cout << s.marka << " " << s.model << " " << s.przebieg << endl;
}

void jedz(Samochod &s, unsigned x) {
	cout << s.marka << " " << s.model << " jedzie" << endl;
	s.przebieg += x;
}


int main() {
	Samochod fiat, opel;

	ustawPolaSamochodu(fiat, "Fiat", "Punto", 0);
	ustawPolaSamochodu(opel, "Opel", "Corsa", 100000);

	prezentuj(fiat);
	prezentuj(opel);

	jedz(fiat, 20);
	jedz(opel, 20);

	prezentuj(fiat);
	prezentuj(opel);
	



	cin.get();
	cin.ignore();
	return 0;

}
