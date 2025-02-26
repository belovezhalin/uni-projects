#include <iostream>
#include <typeinfo>

using namespace std;


int main() {

	cout << "Prawda: " << true << endl;
	cout << "Liczba: " << 17 << endl;

	ios::fmtflags flagi(cout.flags()); //przestrzenie nazw, zwracany int
	cout << "flagi: " << flagi << endl;
	
	//http://en.cppreference.com/w/cpp/io/ios_base/fmtflags
	//http://staff.elka.pw.edu.pl/~rnowak2/zprwiki/doku.php?id=klasy_bazowe_dla_strumieni

	//cout << typeid(cout.boolalpha).name() << endl;// typ enum - "nazwany int" w przestrzeni nazw
 	cout << "boolalpha: " << cout.boolalpha	<<	endl;
	cout << "showpos: "<< cout.showpos	<<	endl;
	 
	cout.setf(cout.boolalpha | cout.showpos	);
	
	cout << "flagi: " << cout.flags() << endl;
	cout << "Prawda: " << true << endl;
	cout << "Liczba: " << 17 << endl;

	cout.unsetf(cout.boolalpha);
	
	cout << "flagi: " << cout.flags() << endl;
	cout << "Prawda: " << true << endl;
	cout << "Liczba: " << 17 << endl;
	
	cout << endl;

/*
	double x = 4235.14;
	cout << "Liczba: " << x << endl;

	int precyzjaPrzedZmianami;
	cout << "precyzja " << (precyzjaPrzedZmianami = cout.precision()) << endl;
	cout.precision(2);
	cout << "flagi: " << cout.flags() << endl;

	cout << "Liczba: " << x << endl;

	cout.precision(precyzjaPrzedZmianami);
	cout << "Liczba: " << x << endl;
*/	



	//cin.ignore();
	//return 0;
}
