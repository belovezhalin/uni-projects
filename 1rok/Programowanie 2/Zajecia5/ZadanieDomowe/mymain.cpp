#include <iostream>
#include "Przedmiot.h"
#include "Bron.h"

using namespace std;

int main() {
    Przedmiot p1("Ksiazka", 1.0, 0.5);
    Bron p2("Miecz", 2.0, 2.0, 10);
    Bron p3("Luk", 1.5, 1.0, 8);
    
    p1.wyswietl();
    p2.wyswietl();
    p3.wyswietl();
    
    return 0;
}