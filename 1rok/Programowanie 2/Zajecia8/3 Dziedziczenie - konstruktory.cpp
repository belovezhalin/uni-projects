#include <iostream>
using namespace std;


class KlasaBazowa {
public:
	int wartoscWBazowej;

	KlasaBazowa() {
		wartoscWBazowej = 10;
		cout << "Konstruktor domyslny klasy bazowej" << endl;
	}
	KlasaBazowa(int wwb) {
		wartoscWBazowej = wwb;
		cout << "Konstruktor 1 klasy bazowej" << endl;
	}
	KlasaBazowa(const KlasaBazowa& kb) {
		wartoscWBazowej = kb.wartoscWBazowej;
		cout << "Konstruktor kopiujacy klasy bazowej" << endl;
	}
	~KlasaBazowa() {
		cout << "Destruktor klasy bazowej" << endl;
	}

	void wyswietl() {
		cout << "Wyswietlanie klasy bazowej:" << wartoscWBazowej << endl;
	}
};

class KlasaPochodna : public KlasaBazowa {
public:
	int wartoscWPochodnej;

	KlasaPochodna() {
		//this->KlasaBazowa();
		//KlasaBazowa(); // pozorne wywo³anie konstruktora
		wartoscWPochodnej = 10;
		cout << "Konstruktor domyslny klasy pochodnej" << endl;
	}

	KlasaPochodna(int wwp) {
		wartoscWPochodnej = wwp;
		cout << "Konstruktor 1 klasy pochodnej" << endl;
	}

	KlasaPochodna(int wwb, int wwp): KlasaBazowa(wwb) {
		wartoscWPochodnej = wwp;
		cout << "Konstruktor 2 klasy pochodnej" << endl;
	}
/*	KlasaPochodna(int wwb, int wwp) {
		wartoscWBazowej = wwb;
		wartoscWPochodnej = wwp;
		cout << "Konstruktor 2 klasy pochodnej" << endl;
	}*/

	/*
	KlasaPochodna(const KlasaPochodna& kp) {
		wartoscWPochodnej = kp.wartoscWPochodnej;
		cout << "Konstruktor kopiujacy klasy pochodnej" << endl;
	}
	*/

	KlasaPochodna(const KlasaPochodna& kp): KlasaBazowa(kp) {
		wartoscWPochodnej = kp.wartoscWPochodnej;
		cout << "Konstruktor kopiujacy klasy pochodnej" << endl;
	}
	
	~KlasaPochodna() {
		cout << "Destruktor klasy pochodnej" << endl;
	}

	void wyswietl() {
		cout << "Wyswietlanie klasy pochodnej:" << wartoscWBazowej <<" "<< wartoscWPochodnej << endl;
	}
};


int main5() {
	//KlasaBazowa();

	{
	KlasaPochodna P1;
	P1.wyswietl();
	cout << endl;

	KlasaPochodna P2(100);
	P2.wyswietl();
	cout << endl;
	
	KlasaPochodna P3(100, 100);
	P3.wyswietl();
	cout << endl;
	
	KlasaPochodna P3(100, 100);
	KlasaPochodna P4(P3);
	P4.wyswietl();
	cout << endl;

	KlasaBazowa B1(P4);
	B1.wyswietl();
	//KlasaPochodna P5(B1);
	//B1.wyswietl();

	cout << endl;
	}

	cin.get();
	return 0;
}