#include <iostream>
using namespace std;

int main() {
	int tab[10] = {};
	
	cout << "Wczytaj 10 calkowitych elementow tablicy! " << endl;
	for (size_t i = 0; i <= 9; i++) {cin >> tab[i];}
	
	cout << "Koncowa tablica 10elementowa: ";
	for (size_t i = 0; i <= 9; i++) {cout << tab[i] << " ";}
	cout << endl;
	
	cout << "a) Wartosc pierwszego elementu tablicy: " << *tab << endl;
	cout << "b) Wartosc elementu piatego: " << *(tab + 4) << endl;
	cout << "c) Zawartosc calej tablicy: ";
	
	for (size_t i = 0; i <= 9; i++) {
		cout << *(tab + i) << " ";}
}
