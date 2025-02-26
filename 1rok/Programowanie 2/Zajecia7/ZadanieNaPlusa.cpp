#include <iostream>
#include <string>
using namespace std;

class AbsolwentUJ
{
private:
    static int liczbaAbsolwentow;
    static double sredniaOgolna;
    string imie;
    string nazwisko;
    string kierunek;
    int rocznik;
    double sredniaOcena;

public:
    static const string uczelnia;

    AbsolwentUJ(string imie, string nazwisko, string kierunek, int rocznik, double sredniaOcena)
        : imie(imie), nazwisko(nazwisko), kierunek(kierunek), rocznik(rocznik), sredniaOcena(sredniaOcena)
    {
        ++liczbaAbsolwentow;
        sredniaOgolna = (sredniaOgolna * (liczbaAbsolwentow - 1) + sredniaOcena) / liczbaAbsolwentow;
    }

    void wyswietlDane() const
    {
        cout << "Imie i nazwisko: " << imie << " " << nazwisko << endl;
        cout << "Kierunek: " << kierunek << endl;
        cout << "Rocznik: " << rocznik << endl;
        cout << "Uczelnia: " << uczelnia << endl;
        cout << "Srednia ocena: " << sredniaOcena << endl;
        cout << "Srednia ocena ogolna: " << sredniaOgolna << endl;
    }

    void zmienSredniaOcene(double nowaSredniaOcena)
    {
        sredniaOgolna = (sredniaOgolna * liczbaAbsolwentow - sredniaOcena + nowaSredniaOcena) / liczbaAbsolwentow;
        sredniaOcena = nowaSredniaOcena;
    }

    static double getsredniaOgolna()
    {
        return sredniaOgolna;
    }
};

int AbsolwentUJ::liczbaAbsolwentow = 0;
double AbsolwentUJ::sredniaOgolna = 0.0;
const string AbsolwentUJ::uczelnia = "Uniwersytet Jagiellonski";

int main()
{
    AbsolwentUJ absolwent("Jan", "Kowalski", "Informatyka", 2020, 4.5);
    absolwent.wyswietlDane();
    cout << "Srednia ocena ogolna: " << AbsolwentUJ::getsredniaOgolna() << endl << endl;
    absolwent.zmienSredniaOcene(4.0);
    absolwent.wyswietlDane();
    cout << "Srednia ocena ogolna: " << AbsolwentUJ::getsredniaOgolna() << endl;

    return 0;
}