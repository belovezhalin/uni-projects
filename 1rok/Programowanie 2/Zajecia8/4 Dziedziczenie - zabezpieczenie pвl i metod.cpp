#include <iostream>
using namespace std;

/*
Spos�b dziedziczenia

klasa bazowa - sama klasa - klasa pochodna

public:
nie zmienia praw dost�pu ani w samej klasie ani w klasie pochodnej
protected:
w samej klasie - public staje si� protected / odziedziczone sk�adniki publiczne w klasie pochodnej maj� dost�p protected
private :
w samej klasie - public staje si� protected / wszystkie odziedziczone sk�adniki klasie pochodnej maj� dost�p private
*/

/*
class Pojazd {
public:
	int publicznePojazd;
protected:
	int chronionePojazd;
private:
	int prywatnePojazd;

	void metoda() {
		publicznePojazd = 1;
		chronionePojazd = 2;
		prywatnePojazd = 3;
	}
};

class Samochod : public Pojazd { 
//class Samochod : private Pojazd { //private - domyslny
//class Samochod : protected Pojazd {
	void metoda() {
		publicznePojazd = 1;
		chronionePojazd = 2;
		prywatnePojazd = 3;
	}

public:
//		Pojazd::publicznePojazd;
protected:
//		Pojazd::publicznePojazd;
};


class Taksowka : public Samochod {
	void metoda() {
		publicznePojazd = 1;
		chronionePojazd = 2;
		prywatnePojazd = 3;
	}
};


int main() {
	
	Pojazd p;
	p.publicznePojazd = 1;
	p.chronionePojazd = 2;
	p.prywatnePojazd = 3;

	Samochod s;
	s.publicznePojazd = 1;
	s.chronionePojazd = 2;
	s.prywatnePojazd = 3;


	Taksowka t;
	t.publicznePojazd = 1;
	t.chronionePojazd = 2;
	t.prywatnePojazd = 3;

	cin.get();
	cin.ignore();
	return 0;
}
*/