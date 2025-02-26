#include <iostream>
using namespace std;

class osoba {
	public:
	string imie, nazwisko, ulica, dom;
	
	void wprowadz_dane();
	void pokaz_dane();
	void tabela();
};

void osoba::tabela() {
	string s = nazwisko + ' ' + imie + ' ' + ulica + ' ' + dom;
	cout << s;
}

void osoba::wprowadz_dane() {
		cout << "Podaj nazwisko: "; 
		cin >> nazwisko;
		cout << "Podaj imie: ";
		cin >> imie;
		cout << "Podaj ulice: ";
		cin >> ulica;
		cout << "Podaj nr domu: ";
		cin >> dom;
		cout << endl;
}

void osoba::pokaz_dane() {
	cout << "Nazwisko: " << nazwisko << endl;
	cout << "Imie: " << imie << endl;
	cout << "Ulica: " << ulica << endl;
	cout << "Numer domu: " << dom << endl;
}

int main() {
	int n = 0;
	
	osoba o;
	
	cout << "Podaj ilosc osob: ";
	cin >> n;
	cout << endl;
	
	if (n != 0) {
	for (int i = 1; i <= n; i++) {
		cout << "Dane dotyczace " << i << ". osoby: " << endl;
		o.wprowadz_dane();}
		
	cout << "Wyswietlenie danych: " << endl << endl;
	
	for (int i = 1; i <= n; i++) {
		cout << "Dane dotyczace " << i << ". osoby: " << endl;
		o.pokaz_dane();
		cout << endl;}
		
	for (int i = 1; i <= n; i++) {
		cout << "Tablica danych: " << endl;
		o.tabela();
		cout << endl;}
}

if (n == 0) cout << "Brak osob.";

	return 0;
}
