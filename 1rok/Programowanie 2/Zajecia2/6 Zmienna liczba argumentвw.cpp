#include <iostream>
#include <cstdarg>

using namespace std;

void zaprezentujArgumenty(const char* typy, ...)
{
	int calkowita;
	char*  napis;
	double  zmiennoprzecinkowa;

	va_list ap;

	va_start(ap, typy); //typy - ostatni argument przed kropkami

	int i = 0; char c;
	while ((c = typy[i++]) != '\0')
	{
		switch (c)
		{
		case 'c':
			calkowita = va_arg(ap, int);
			cout << "Liczba int   : " << calkowita << endl;
			break;
		case 'z':
			zmiennoprzecinkowa = va_arg(ap, double);
			cout << "Liczba double: " << zmiennoprzecinkowa << endl;
			break;
		case 'n':
			napis = va_arg(ap, char*);
			cout << "Napis  : " << napis << endl;
			break;
		default:
			cout << "Nieprawidlowy kod typu" << endl << endl;
			//goto KONIEC;
			va_end(ap);
			return;
		}
	}
	//KONIEC:
	cout << endl;
	va_end(ap);
}

int main()
{
	zaprezentujArgumenty("nzcn", "Ala", 4.9, 7, "Bob");
	zaprezentujArgumenty("izc", "Ala", 4.9, 7);

	cin.ignore();
	return 0;
}

//Zadanie domowe
//�	Cz�� 1 - Zaimplementuj funkcj� o podanej poni�ej sygnaturze (1p.)

//void rozdzielNaHex(string plikWejscie, int liczbaWyjsc, string plikWyjscie1, ...);

/*
Funkcja ta ma rozdzieli� linijki z pliku tekstowego o nazwie podanej w argumencie �plikWejscie� i zapisa� je do plik�w �plikWyjscie1�, �plikWyj�cie2� 
i kolejnych. Pierwsza linijka z pliku wej�ciowego ma trafi� do pierwszego pliku wyj�ciowego, druga do drugiego i tak dalej, z zap�tleniem plik�w wyj�ciowych.
Liczba plik�w wyj�ciowych podana jest w argumencie �liczbaWyjsc�.Obs�uga plik�w ma si� odbywa� �w stylu� C++.

Dane w pliku wej�ciowym to liczby ca�kowite w zapisie dziesi�tnym.Nale�y je przed zapisaniem zamieni� na zapis heksadecymalny z du�ymi literami.W tym celu 
nale�y wykorzysta� strumie� �cout� i zmieni� parametry jego dzia�ania.Po zako�czeniu wykonywania funkcji stan strumienia powinien by� taki sam jak przed jej 
wywo�aniem.
*/

//�	Cz�� 2 - Zaimplementuj funkcj� o podanej poni�ej sygnaturze (1p.)

//void polaczNaDec(string plikWyj�cie, int liczbaWejsc, string plikWej�cie1, ...);

/*
Funkcja ta ma by� �odwrotno�ci�� funkcji z poprzedniego zadania � ma w analogiczny spos�b ��czy� linijki z plik�w wej�ciowych z liczbami heksadecymalnymi 
i zapisywa� je do pliku wyj�ciowego jako liczby decymalne(spos�b konwersji - dowolny).
*/
