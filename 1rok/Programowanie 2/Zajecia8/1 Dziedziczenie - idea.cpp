#include <iostream>
using namespace std;

class Jednoslad {
public:
	int liczbaKol;

	Jednoslad(int lK = 1) {
		liczbaKol = lK;
	}

	void wyswietl() {
		cout << "Jednoslad: liczba kol " << liczbaKol << endl;
	}

};

class Motocykl : public Jednoslad {
public:
	int pojemnoscSilnika;

	Motocykl(int pS = 125) {
		pojemnoscSilnika = pS;
	}

	void wyswietl() {
		cout << "Motocykl: liczba kol " << liczbaKol << ", pojemnosc silnika: " << pojemnoscSilnika << endl;
	}
};

class Rower : public Jednoslad {
public:
	int dlugoscKorby;

	Rower(int dK = 175) {
		dlugoscKorby = dK;
	}

	void wyswietl() {
		cout << "Rower: liczba kol " << liczbaKol << ", dlugosc korby: " << dlugoscKorby << endl;
	}
};

int main3() {
	Jednoslad j;
	j.wyswietl();

	Motocykl m;
	m.wyswietl();
	
	Rower r;
	r.wyswietl();

	cin.get();
	return 0;
}



//
/*


Jeœli mamy gotow¹ klasê Samochod, a potrzebna jest nam klasa Taksowka, mamy do wyboru kilka dróg :

przerobiæ klasê Samochod, na klasê Taksowka
mamy now¹ klasê, ale tracimy star¹
dodaæ klasê Taksowka na wzór klasy Samochod
musimy pamiêtaæ, by ka¿d¹ poprawkê w klasie Samochod nanosiæ równie¿ w klasie Taksowka

+++ napraw(samochod)

ZAWIERA VS JEST

zbudowaæ klasê Taksowka wykorzystuj¹c klasê Samochod i mechanizm dziedziczenia
zachowujemy star¹ klasê, a w nowej klasie piszemy tylko to co chcemy dodaæ lub zmieniæ.

Dziedziczenie to mechanizm pozwalaj¹cy definiowaæ nowe klasy przy wykorzystaniu klas ju¿ zdefiniowanych poprzez podanie ró¿nic i uzupe³nieñ.
Dziedziczenie jest trzeci¹ cech¹ charakterystyczn¹ programowania obiektowego.
---------


dza siê nastêpuj¹c¹ terminologiê

klasa podstawowa (lub klasa bazowa, klasa macierzysta)
jest to klasa, któr¹ bêdziemy rozbudowywaæ (na przyk³ad Jednoslad)
klasa pochodna
jest to klasa, która rozbudowuje (dziedziczy) jakaœ klasê podstawow¹ (na przyk³ad Rower dziedziczy Jednoslad)
dziedziczenie wielopokoleniowe
Dziedziczenie klasy, która ju¿ jest klas¹ pochodn¹ (na przyk³ad: Taksówka dziedziczy po Samochodzie, Samochod po klasie PojazdSpalinowy, z kolei PojazdSpalinowy dziedziczy po klasie Pojazd)
dziedziczenie wielokrotne
sytuacja, w której klasa dziedziczy z wielu klas jednoczeœnie (na przyk³ad Kapelan mo¿e dziedziczyæ tak po klasie Duchowny jak i po klasie Wojskowy).



---------


Porównanie kompozycji i dziedziczenia.

+dziedziczenie wielokrotne



*/



/*
NEXT:

Destruktor, konstruktor kopiuj¹cy i operator przypisania w klasie pochodnej

Jeœli klasa pochodna nie definiuje swojego destruktora, 
to kompilator próbuje go wygenerowaæ automatycznie metod¹ "sk³adnik po sk³adniku". 
Wykorzystuje przy tym destruktor klasy macierzystej do zlikwidowania sk³adników pochodz¹cych z klasy macierzystej. Podobnie dzieje siê z konstruktorem kopiuj¹cym i z operatorem przypisania.

dziedziczenie kilkupokoleniowe

wskaŸniki w dziedziczeniu

C++ - dziedziczenie prywatne, operator przypisania w klasie pochodnej

C++ - dziedziczenie wielokrotne i wirtualne

C++ - dziedziczenie wielokrotne i wirtualne

C++ - polimorfizm

C++ - klasy abstrakcyjne

C++ - wielometody i RTTI
*/