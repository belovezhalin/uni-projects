//(c) 2024 Firma XYZ                                                          -komentarz prawny
//Ten kod jest licencjonowany na warunkach licencji ABC.
//Szczegóły w pliku LICENSE.

#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

//Ta funkcja oblicza silnie liczby używając rekurencji.                      -komentarz informacyjny
int silnia(int n) {
    if(n == 0) return 1;
    else return n * silnia(n - 1);
}

//Uzywamy tutaj mapy, aby przechowywac licznik wystapien,                    -komentarz wyjasniajacy 
//poniewaz zapewnia srednia zlozonosc czasowa O(1) dla operacji dodawania i wyszukiwania.
map<string, int> zlicz_wystapienia(const vector<string>& elementy) {
    map<string, int> liczniki;
    for(const auto& element : elementy) {
        if(liczniki.find(element) != liczniki.end()) liczniki[element]++;
        else liczniki[element] = 1;
    }
    return liczniki;
}

//UWAGA: Zmiana tej wartosci wplynie na stan globalny                        -komentarz ostrzezajacy
//i moze spowodowac nieoczekiwane zachowanie w innych czesciach aplikacji.
int GLOBALNA_WARTOSC_KONFIGURACJI = 42;

//TODO: Zaimplementuj obsluge bledow dla przypadkow brzegowych, gdy wejscie jest puste lub nieprawidlowe.   -komentarz TODO
string przetwarzaj_wejscie(const string& wejscie) {
    return wejscie; 
}

int main() {
    cout << "Silnia 5: " << silnia(5) << endl; 

    vector<string> owoce = {"jablko", "banan", "jablko"};
    auto liczniki = zlicz_wystapienia(owoce);
    for (const auto& para : liczniki) {
        cout << para.first << ": " << para.second << endl; 
    }

    cout << "Przetworzone wejscie: " << przetwarzaj_wejscie("  Test  ") << endl; 

    return 0;
}
