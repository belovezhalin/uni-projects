#include <iostream>
using namespace std;

class Pojazd {
public:
	int przebieg;

	Pojazd() { przebieg = 0; }
	
	void wyswietl() {
		cout << "Pojazd: przebieg " << przebieg << endl << endl;
	}

};

class Samochod : public Pojazd {
public:
	//int przebieg;
	int pojemnoscSilnika;

	Samochod() { przebieg = 0; pojemnoscSilnika = 0; }

	void wyswietl() {
		cout << "Samochod: przebieg " << przebieg << ", pojemnosc silnika: " << pojemnoscSilnika << endl;
	}
};

int main() {
	//Pojazd p;
	//p.wyswietl();
	//p.przebieg = 8;
	//p.wyswietl();
	//p.pojemnoscSilnika = 9;
	

	Samochod s;
	
	//s.wyswietl();
	//s.Pojazd::wyswietl();

	s.przebieg = 111;
	s.wyswietl();

	s.Pojazd::przebieg = 222;
	s.wyswietl();

	//cout << s.Pojazd::przebieg;
	s.Pojazd::wyswietl();

	/*
	s.przebieg = 111;
	//s.Pojazd::przebieg = 222;
	s.wyswietl();
	s.Pojazd::wyswietl();
	*/

	return 0;
}
