#include <iostream>
#include <algorithm>
using namespace std;
const int lim = 6;

class dane {
	public:
	int suma = 0;
	double liczby[lim];
	int wprowadz_dane();
	void posortuj_dane(int ilosc);
	void wyswietl_wynik(int ilosc);
};

int main() {
	
	dane elementy;
	int wartosc = elementy.wporawdz_dane();
	elementy.posortuj_dane(wartosc);
	elementy.wyswietl_wynik (wartosc);
	
	return 0;
}

int dane::wprowadz_dane () {
	cout << "Podaj liczby: " << endl;
	
	for (int i = 0; i < lim; i++) {cin >> liczby[i]; ++suma;}
	return suma;
}

void dane::posortuj_dane(int ilosc) {
	sort(liczby, liczby + ilosc);
}

void dane::wyswietl_wynik(int ilosc) {
	cout << endl << " Po sortowaniu: " << endl;
	
	for (int i = 0; i < ilosc; i++) cout << liczby << endl;
}
