#include "BronMiotana.h"
#include <cstdio>

#include <iostream>
#include <string>
using namespace std;

BronMiotana::BronMiotana(const string& nazwa, double waga, double objetosc, int liczbaPunktowRazenia, double zasieg) : Bron(nazwa, waga, objetosc, liczbaPunktowRazenia), m_zasieg(zasieg) {
    cout << "Konstruktor klasy BronMiotana" << endl;}

BronMiotana::~BronMiotana() {
    cout << "Destruktor klasy BronMiotana" << endl;}

double BronMiotana::pobierzZasieg() const {
    return m_zasieg;}

void BronMiotana::ustawZasieg(double zasieg) {
    m_zasieg = zasieg;}

void BronMiotana::wyswietl() const {
    cout << "BronMiotana: " << pobierzNazwe() << ", waga: " << pobierzWage() << ", objetosc: " << pobierzObjetosc() << ", liczba punktow razenia: " << pobierzLiczbaPunktowRazenia() << ", zasieg: " << m_zasieg << endl;}

string BronMiotana::pobierzNazwe() const {
    return Przedmiot::pobierzNazwe();}