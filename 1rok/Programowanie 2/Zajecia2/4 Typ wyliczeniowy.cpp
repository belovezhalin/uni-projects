#include <iostream>
#include <cstdarg>
#include <typeinfo>
using namespace std;


enum Kolor { czerwony, zielony, niebieski };

int main()
{

	cout << czerwony << "  " << niebieski << endl;

	Kolor mojUlubiony = niebieski;

	cout << mojUlubiony << endl;

	mojUlubiony = Kolor(4); //uwaga - poza tablic¹
	cout << mojUlubiony << endl;

	//Jak zdobyæ nazwê koloru?
	//https://stackoverflow.com/questions/5093460/how-to-convert-an-enum-type-variable-to-a-string

	cout << typeid(czerwony).name() << endl;
	
	
	/*
	enum Kolor2 { czerwony, zielony, niebieski };// - zas³anianie nazw, inny typeid; typ enum - "nazwany int" w przestrzeni nazw
	cout << typeid(czerwony).name() << endl;
	//cout << typeid(cout).name() << endl;
	*/

	cin.ignore();
	return 0;
}
