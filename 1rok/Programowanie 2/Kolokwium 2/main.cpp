#include <iostream>
#include <vector>
#include "Motolotnia.cpp"
#include "Lotnia.cpp"
#include "Samolot.cpp"
#include "Szybowiec.cpp"
#include "StatekPowietrzny.cpp"
#include "Lotnisko.h"
using namespace std;

int main()
{
   Samolot s1("Airbus A320"), s3("Boeing 737");
   cout << s1; //Samolot Airbus A320
   Lotnisko<Samolot> balice(4);
   balice[1] = &s1;
   balice[3] = &s3;
   cout << balice; //Airbus A320 / Pusty hangar / Boeing 737 / Pusty hangar
   // balice[5] = &s1; Rzuca wyjątek "Nieprawidłowy numer hangarud"
   Lotnia a2("Czerwona");
   Lotnisko<Lotnia> aeroklub(3);
   aeroklub[2] = &a2;
   cout << a2; //Pusty hangar / Czerwona / Pusty hangar 
   Motolotnia m("Niebieska 80KM");
   m.dodajRok();
   StatekPowietrzny *ptr = &m;
   ptr->wyswietlWiek(); //Motolotnia Niebieska 80KM ma 1 lat
}