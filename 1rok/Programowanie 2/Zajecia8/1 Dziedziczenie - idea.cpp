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


Je�li mamy gotow� klas� Samochod, a potrzebna jest nam klasa Taksowka, mamy do wyboru kilka dr�g :

przerobi� klas� Samochod, na klas� Taksowka
mamy now� klas�, ale tracimy star�
doda� klas� Taksowka na wz�r klasy Samochod
musimy pami�ta�, by ka�d� poprawk� w klasie Samochod nanosi� r�wnie� w klasie Taksowka

+++ napraw(samochod)

ZAWIERA VS JEST

zbudowa� klas� Taksowka wykorzystuj�c klas� Samochod i mechanizm dziedziczenia
zachowujemy star� klas�, a w nowej klasie piszemy tylko to co chcemy doda� lub zmieni�.

Dziedziczenie to mechanizm pozwalaj�cy definiowa� nowe klasy przy wykorzystaniu klas ju� zdefiniowanych poprzez podanie r�nic i uzupe�nie�.
Dziedziczenie jest trzeci� cech� charakterystyczn� programowania obiektowego.
---------


dza si� nast�puj�c� terminologi�

klasa podstawowa (lub klasa bazowa, klasa macierzysta)
jest to klasa, kt�r� b�dziemy rozbudowywa� (na przyk�ad Jednoslad)
klasa pochodna
jest to klasa, kt�ra rozbudowuje (dziedziczy) jaka� klas� podstawow� (na przyk�ad Rower dziedziczy Jednoslad)
dziedziczenie wielopokoleniowe
Dziedziczenie klasy, kt�ra ju� jest klas� pochodn� (na przyk�ad: Taks�wka dziedziczy po Samochodzie, Samochod po klasie PojazdSpalinowy, z kolei PojazdSpalinowy dziedziczy po klasie Pojazd)
dziedziczenie wielokrotne
sytuacja, w kt�rej klasa dziedziczy z wielu klas jednocze�nie (na przyk�ad Kapelan mo�e dziedziczy� tak po klasie Duchowny jak i po klasie Wojskowy).



---------


Por�wnanie kompozycji i dziedziczenia.

+dziedziczenie wielokrotne



*/



/*
NEXT:

Destruktor, konstruktor kopiuj�cy i operator przypisania w klasie pochodnej

Je�li klasa pochodna nie definiuje swojego destruktora, 
to kompilator pr�buje go wygenerowa� automatycznie metod� "sk�adnik po sk�adniku". 
Wykorzystuje przy tym destruktor klasy macierzystej do zlikwidowania sk�adnik�w pochodz�cych z klasy macierzystej. Podobnie dzieje si� z konstruktorem kopiuj�cym i z operatorem przypisania.

dziedziczenie kilkupokoleniowe

wska�niki w dziedziczeniu

C++ - dziedziczenie prywatne, operator przypisania w klasie pochodnej

C++ - dziedziczenie wielokrotne i wirtualne

C++ - dziedziczenie wielokrotne i wirtualne

C++ - polimorfizm

C++ - klasy abstrakcyjne

C++ - wielometody i RTTI
*/