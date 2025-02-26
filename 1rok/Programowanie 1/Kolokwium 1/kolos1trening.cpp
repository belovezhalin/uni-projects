#include <iostream>
using namespace std;
int main()
{
	int x = 0;
while (x++ < 10) {
cout << x;
}

}
// #include <iostream>
// #include <cmath>
// #include <conio.h>
// #include <iomanip>
// #include <math.h>
// #include <cstdlib>
// #include <time.h>
// using namespace std;

// /*int main(){
// int x = 0;
// while (x++ < 10) {
// cout << x;}
// }*/

// /*main(){
// 	const double EPS = 0.00000001;
// 	double x;
// 	x = 0;
	
// 	while (fabs(1-x) > EPS) {
// 		x += 0.1;
// 		cout << x << endl;}
		
// 	cout << endl << endl;
// }*/

// /*main() {
// char znak;
// znak='A';
// cout << znak; //A
// //konwersja � znak-liczba
// cout << znak << int(znak) << endl; //A 65
// cout << znak << (int) znak << endl;//A 65
// cout << znak << char(65) << endl;//A A
// //znaki jak liczby!!!
// cout << znak+0 << znak+1 << endl;//65 66
// cout << '1'+'1' << 1+1 << endl; //98 2
// }*/

// /*int main(){
// int podaj;
// char znak;
// cout << "podaj";
// cin >> znak;
// podaj=(int)znak;
// cout << "jest to" << podaj ;
// system ("pause");}*/

// /*main() {
// 	float a, b, pole;
	
// 	cout << "Podaj dlugosc i szerokosc prostokata: ";
// 	cin >> a >> b;
	
// 	pole = a * b;
	
// 	//cout << fixed;
// 	//cout << setprecision (3);
// 	cout << "Pole prostokata wynosi: " << setprecision(3) << fixed << pole << endl;
// }*/

// /*main() {
// 	int a, b, c;
// 	cout << "Podaj bok a: ";
// 	cin >> a;
// 	cout << "Podaj bok b: ";
// 	cin >> b;
// 	cout << "Podaj bok c: ";
// 	cin >> c;
	
// 	if (a * a + b * b == c * c) {
// 		cout << "Boki a = " << a << ", b = " << b << " i c = " << c << " tworza trojkat prostokatny" << endl;}
// 	else {
// 		cout << "Boki a = " << a << ", b = " << b << " i c = " << c << " nie tworza trojkata prostokatnego" << endl;}
// 	}*/
	
// /*main() {
// 	int losuj, zgadnij;
	
// 	cout << "Program losuje liczbe od 0 do 9. Zgadnij ja." << endl;
// 	cin >> zgadnij; 
	
// 	srand(time(0));
// 	losuj = rand() % 10;
	
// 	if (losuj == zgadnij) cout << "Udalo ci sie!" << endl;
// 	else cout << "Bardzo mi przykro, ale wylosowana liczba to: " << losuj << endl;
// }*/

// /*main() {
//    char znak;
   
//    cout << "Program wyswietla duze litery alfabetu od A do Z i od Z do A. " << endl;
   
//    for (znak = 'A'; znak <= 'Z'; znak++) {cout << znak << " ";}
   
//    cout << endl;
   
//    for (znak = 'Z'; znak >= 'A'; znak--) {cout << znak << " ";}
// }*/

// //void fun(double d, int i, bool b);
// //void fun(double, int, bool);
// //void fun(double d, int i);
// //void fun(int i, double d);
// //void fun(int it, double dbl);

// /*bool isprime (int const x) {
// 	if (x <= 3) return x > 1;
// 	else if (x % 2 == 0 || x % 3 == 0) return false;
// 	else {
// 		for (int i = 5; i * i <= x; i += 6) {
// 			if (x % i == 0 || x % (i + 2) == 0) {return false;}
// 		}
// 	return true;
// 	}
// }

// main() {
// 	int zakres = 0;
// 	cout << "Zakres: ";
// 	cin >> zakres;
	
// 	for (int i = zakres; i > 1; i--) {
// 		if (isprime(i)) {
// 			cout << "Najwieksza liczba pierwsza w zakresie to " << i << endl;
// 			return 0;}
// 	}}*/
	
// /*main() {
// 	int x = 0;
// 	x -=1;
// 	cout << x;
// }*/




