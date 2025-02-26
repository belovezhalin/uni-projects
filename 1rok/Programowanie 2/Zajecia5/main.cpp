#include <iostream>
#include "Bateria.h"
#include "UrzadzenieNaBaterie.h"
#include "AparatCyfrowy.h"
#include "TelefonKomorkowy.h"
#include "OdtwarzaczMultimedialny.h"
#include "Smartfon.h"
using namespace std;

//"g++ ${fileDirname}/**.cpp"
// https://www.youtube.com/watch?v=8IWFeUkZ4bo&t=1s
int main()
{

	Bateria b1;
	Bateria b2;

	UNB u(2);
	u.wloz(&b1, 0);
	if (u.czyKomplet())
		cout << "TAK1" << endl;

	u.wloz(&b2, 1);
	if (u.czyKomplet())
		cout << "TAK2" << endl;

	// u.wyjmij(1);
	if (u.czyKomplet())
		cout << "TAK3" << endl;

	u.rozladuj(10);

	cout << b1.getStanNaladowania() << endl;
	cout << b2.getStanNaladowania() << endl;

	Smartfon s(5);

	s.przezentuj();
	s.wlacz();

	cin.get();
	cin.ignore();
}
