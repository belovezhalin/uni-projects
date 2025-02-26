#include <iostream>
using namespace std;

class student {
	public:
	string imie, nazwisko, uczelnia, wydzial, kierunek;
	int numer, rok;
	bool status;
	
	void wprowadz_dane();
	void pokaz_dane();
};

void student::wprowadz_dane() {
	cout << "Wprowadz dane: " << endl;
		cout << "Podaj imie: "; 
		cin >> imie;
		cout << "Podaj nazwisko: ";
		cin >> nazwisko;
		cout << "Podaj numer indeksu: ";
		cin >> numer;
		cout << "Podaj status (aktywny/nieaktywny): ";
		cin >> status;
		cout << "Podaj uczelnie: ";
		cin >> uczelnia;
		cout << "Podaj wydzial: ";
		cin >> wydzial;
		cout << "Podaj kierunek: ";
		cin >> kierunek;
		cout << "Podaj rok studiow: ";
		cin >> rok;
		cout << endl;
}

void student::pokaz_dane() {
	cout << "Dane studenta: " << endl << endl;
	cout << "Imie: " << imie << endl;
	cout << "Nazwisko: " << nazwisko << endl;
	cout << "Numer indeksu: " << numer << endl;
	cout << "Status: " << status << endl;
	cout << "Uczelnia: " << uczelnia << endl;
	cout << "Wydzial: " << wydzial << endl;
	cout << "Kierunek: " << kierunek << endl;
	cout << "Rok studiow: " << rok << endl;
}

int main() {
	
	student s;
	
	s.wprowadz_dane();
	s.pokaz_dane();
	return 0;
}
