#include <iostream>
using namespace std;

class Ksiazka {
	public:
		string autor;
		string tytul;
		string wydawnictwo;
		int rok;
		string kategoria;
		int isbn;
		
		void dodaj_ksiazke() {
		cout << "Wprowadz dane: " << endl;
		cout << "Podaj autora: "; 
		cin >> autor;
		cout << "Podaj tytul: ";
		cin >> tytul;
		cout << "Podaj wydawnictwo: ";
		cin >> wydawnictwo;
		cout << "Podaj rok wydania: ";
		cin >> rok;
		cout << "Podaj kategorie (podrecznik, beletrystyka, dla dzieci, popularnonaukowa)): ";
		cin >> kategoria;
		cout << "Podaj ISBN: ";
		cin >> isbn;
		cout << endl;
		}
		
		void pokaz_ksiazke() {
		cout << "Twoja ksiazka: " << endl << endl;
		cout << "Autor: " << autor << endl;
		cout << "Tytul: " << tytul << endl;
		cout << "Wydawnictwo: " << wydawnictwo << endl;
		cout << "Rok wydania: " << rok << endl;
		cout << "Kategoria: " << kategoria << endl;
		cout << "ISBN: " << isbn << endl;
		}
};

int main() {
	
	Ksiazka k;

	k.dodaj_ksiazke();
	k.pokaz_ksiazke();	
	
	return 0;
}
