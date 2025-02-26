#include <iostream>
using namespace std;

class samochod {
	public:
		string marka;
		string model;
		int rok;
		int pojemnosc;
		int przyspieszenie;
		int spalanie;
		
		void dodaj_samochod() {
		cout << "Wprowadz dane swojego samochodu: " << endl;
		cout << "Podaj marke: "; 
		cin >> marka;
		cout << "Podaj model: ";
		cin >> model;
		cout << "Podaj rocznik (rok produkcji): ";
		cin >> rok;
		cout << "Podaj pojemnosc silnika [cm^3]: ";
		cin >> pojemnosc;
		cout << "Podaj wartosc przyspieszenia od 0 do 100km/h [s]: ";
		cin >> przyspieszenie;
		cout << "Podaj wartosc spalania(l): ";
		cin >> spalanie;
		cout << endl;
		}
		
		void pokaz_zamochod() {
		cout << "Jezdzisz: " << endl << endl;
		cout << "Marka: " << marka << endl;
		cout << "Model: " << model << endl;
		cout << "Rocznik: " << rok << endl;
		cout << "Pojemnosc: " << pojemnosc << " cm^3"<< endl;
		cout << "Przyspieszenie: " << przyspieszenie << " s" << endl;
		cout << "Spalanie: " << spalanie << " l" << endl;
		}
};

int main() {
	
	samochod s;

	s.dodaj_samochod();
	s.pokaz_zamochod();	
	
	return 0;
}
