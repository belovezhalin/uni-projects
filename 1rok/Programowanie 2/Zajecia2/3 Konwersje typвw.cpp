	#include <iostream>
	#include <typeinfo>
	using namespace std;

	int main() {

		int i = 1;
		double d;

		d = i;
		d = (double)i;

		cout << d << endl;
		
		cout << typeid(i).name() << endl;                          //konwersja na lancuch znakow
		cout << typeid(d).name() << endl;
		cout << typeid((double) i).name() << endl;
		
		
		int g = 2;
		char j = 4;
		cout << typeid(j).name()  << endl;
		cout << (g|j) << endl;
		cout << typeid(g|j).name()  << endl;




		//cin.ignore();
		//return 0;
	}

