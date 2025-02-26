#include <iostream>
using namespace std;

/*int main() {
	char litera = 'A';
	
	for (size_t i = 0; i < 8; i++){
		if (i%2 != 0) cout << ' '<< litera++;	
		else cout << endl << litera++;
	}
	cout << endl << endl; 
	
	int n;
	cout << "Podaj ilosc w jednym rzedzie: ";
	cin >> n;
	for (size_t i = 0; litera < 91; i++){
	for (size_t i = 0; i < n; i++){
		if (i%n != 0) cout << ' '<< litera++;	
		else cout << endl << litera++;
	}
    }
}*/

int main() {
	int x = 1;
	
	for (size_t i = 0; i < 8; i++){
		if (i%10 != 0) cout << ' '<< x++;	
		else cout << endl << x++;
	}
	cout << endl << endl; 
	
	int n;
	cout << "Podaj ilosc w jednym rzedzie: ";
	cin >> n;
	for (size_t i = 0; x < 101; i++){
	for (size_t i = 0; i < n; i++){
		if (i%n != 0) cout << ' '<< x++;	
		else cout << endl << x++;
	}
}}

