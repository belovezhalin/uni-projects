/////////////////////////////////////////////////////////////////////zadanie1
#include <iostream>
using namespace std;

struct student {
char imie[25];
int algebra, programowanie, architektura, wdi;
};

int main() { 

student a[5];

for(int i=0; i<5; i++) {
    cout << "Podaj imie studenta nr "<< i + 1 <<": ";
    cin >> a[i].imie;
    cout << "Podaj ocene z Algebry: ";
    cin >> a[i].algebra;
    cout << "Podaj ocene z Programowania: ";
    cin >> a[i].programowanie;
    cout << "Podaj ocene z Architektury komputerow: ";
    cin >> a[i].architektura;
    cout << "Podaj ocen? z Wstepu do Informatyki: ";
    cin >> a[i].wdi;
}

int n;
cout << "Podaj liczbe zapytan: ";
cin >> n;

int nr, przedmiot;

while(n--) {
cout << "Podaj nr studenta z przedzialu [1..5]: ";
cin >> nr;
nr--;

if (nr < 0 || nr >= 5) {
cout << "Brak indeksu!"<< endl;
continue;}

cout << "Podaj nr przedmiotu z przedzialu [0..3]: ";
cin >> przedmiot;
if (przedmiot < 0 || przedmiot > 3) {
cout << "Brak przedmiotu!" << endl;
continue;}

switch(przedmiot) {
      case 0: cout << "Student: " << a[nr].imie << ", ocena z Algebry: " << a[nr].algebra << endl;
break;
      case 1: cout << "Student: " << a[nr].imie << ", ocena z Programowania: " << a[nr].programowanie << endl; 
break;
      case 2: cout << "Student: " << a[nr].imie << ", ocena z Architektury komputerow: " << a[nr].architektura << endl;
break;
      case 3: cout << "Student: " << a[nr].imie << ", ocena z Wstepu do Informatyki: " << a[nr].wdi << endl;
break; 
}}}

/////////////////////////////////////////////////////////////////////zadanie2

#include <iostream>
using namespace std;

class stala2 {
	public: 
	const double d;
	stala2(const double pd);};
	
stala2::stala2(const double pd): d(pd) {}

/////////////////////////////////////////////////////////////////////zadanie3

#include <iostream>
using namespace std;

class A {
	public: 
	int x;
};

class B : private A {
	public: 
	int f(int x) {};
};

/////////////////////////////////////////////////////////////////////zadanie4

#include <iostream> 
using namespace std;

class punkt {
	public:
		int x1, y1, x2, y2;
};

class figura {
	public:
		int liczba;
		int *tab;
		punkt *w;
		figura(int liczba, punkt *w);
		~figura() {delete [] tab;}
};

figura::figura(int liczba, punkt *w) : wierzcholekliczba {
	tab = new punkt[liczba];
	for (int i = 0; i < wierzcholekliczba; tab[i] = punkt[i], i++);
}

class odcinek : public figura {
	public: 
	odcinek(punkt *w) : figura(2, w) {
		int ox = x1 + x2;
		int oy = y1 + y2;
		int glugosc = sqrt(ox*ox + oy*oy);
	}
};

/////////////////////////////////////////////////////////////////////zadanie5

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <ctime>
using namespace std;

struct malaria {
	unsigned int indeks;
	string rejon;
	string nazwisko;
	string imie;
	string data_urodzenia;
	int ilosc_farby;
	float tluszcz_farby;
	string klasa_farby;
};

int main(){
setlocale(LC_ALL, "");
srand(time(NULL));

malaria osoba[10];
osoba[0] = {1, "Bielawa", "Kalisz", "Eugenia", "1972-12-18", 155, 4.1, "I"};
osoba[1] = {83, "Olszyna", "Gora", "Lucyna", "1971-09-13", 158, 3.7, "II"};
osoba[2] = {208, "Strzelin", "Hudzik", "Anna", "1977-01-05", 149, 3.7, "E"};
osoba[3] = {270, "Czernicha", "Las", "Maria", "1976-04-14", 189, 3.8, "P"};
osoba[4] = {381, "Brodnica", "Janas", "Jan", "1976-10-15", 562, 3.6, "II"};
osoba[5] = {415, "Koronowo", "Knapik", "Jan", "1973-08-05", 323, 3.8, "E"};
osoba[6] = {457, "Lipno", "Dynda", "Henryk", "1974-08-22", 266, 3.7, "I"};
osoba[7] = {515, "Radomin", "Wojna", "Jacek", "1971-09-03", 108, 3.6, "I"};
osoba[8] = {636, "Pruszcz", "Mika", "Zofia", "1973-07-13", 125, 3.8, "I"};
osoba[9] = {341, "Krakow", "Anna", "Krol", "2000-02-13", 23, 2.3, "I";};

system("pause");
}




