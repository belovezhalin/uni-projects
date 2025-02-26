#include <iostream>
#include <string>
using namespace std;

class Punkt {
	double x;
	double y;
	Punkt* nastepny;


public:
	Punkt(double _x = 0, double _y = 0, Punkt* _nastepny = NULL): x(_x), y(_y) {
		nastepny = _nastepny;
	}

	void dodajNastepny(Punkt* _nastepny) {
		nastepny = _nastepny;
	}

	Punkt* podajNastepny() {
		return nastepny;
	}

	void wyswietl() {
		cout << "Punkt " << x << " " << y << endl;
	}

};

class Lamana {
	Punkt* pierwszy;

public:

	Lamana(Punkt* _pierwszy = NULL) {
		pierwszy = _pierwszy;
	}

	void dodajNastepny(Punkt* _nastepny) {
		_nastepny->dodajNastepny(NULL);  //(*_nastepny).dodajNastepny(NULL);
		if (pierwszy == NULL) {
			pierwszy = _nastepny;
			return;
		}
		Punkt* ostatni = pierwszy;
		while (!(ostatni->podajNastepny() == NULL)) {
			ostatni = ostatni->podajNastepny();
		}
		ostatni->dodajNastepny(_nastepny);
	}

	void wyswietl() {
		cout << "Lamana" << endl;
		Punkt* tymczasowy = pierwszy;
		while (tymczasowy != NULL) {
			tymczasowy->wyswietl();
			tymczasowy = tymczasowy->podajNastepny();
		}
		cout << endl;

	}
};

int main() {

	Lamana l;

	l.wyswietl();

	Punkt p1(3., 5.);
	l.dodajNastepny(&p1);
	l.wyswietl();

	Punkt p2(2., 7.); //, &p1 - will not break
	l.dodajNastepny(&p2);
	l.wyswietl();

	Punkt p3(1., 9.);
	l.dodajNastepny(&p3);
	l.wyswietl();
	
	Punkt p4(3., 5.);
	l.dodajNastepny(&p4);
	l.wyswietl();


	return 0;

}
