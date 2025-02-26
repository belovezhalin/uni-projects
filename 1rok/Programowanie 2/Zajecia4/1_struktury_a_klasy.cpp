#include <iostream>
#include <string>
using namespace std;


struct Samochod {
private:
	string marka;
	string model;
	int przebieg;
};

void ustawPolaSamochodu(Samochod &s, string _marka, string _model, unsigned _przebieg) {
	s.marka = _marka,
	s.model = _model;
	s.przebieg = _przebieg;
}

void prezentuj(const Samochod &s) {
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
	
	
	cout << fiat.marka;
	
	
//	Samochod const & s = fiat;
//	s = opel;
	
//	prezentuj(s);
	

//	prezentuj(fiat);
//	prezentuj(opel);

//	jedz(fiat, 20);
	//jedz(opel, 20);

//	prezentuj(fiat);
//	prezentuj(opel);

	//Prywatno�� p�l
//	cout << fiat.marka;

//	cin.get();
//	cin.ignore();
	return 0;

}
