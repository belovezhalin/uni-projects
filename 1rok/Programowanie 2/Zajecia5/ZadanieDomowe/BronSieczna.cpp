#include "BronSieczna.h"
#include <cstdio>

#include <iostream>
#include <string>
using namespace std;

BronSieczna::BronSieczna(const string& nazwa, double waga, double objetosc, int liczbaPunktowRazenia, double dlugoscOstrza) : Bron(nazwa, waga, objetosc, liczbaPunktowRazenia), m_dlugoscOstrza(dlugoscOstrza) {
    cout << "Konstruktor klasy BronSieczna" << endl;}

void BronSieczna::wyswietl() const {
    cout << "BronSieczna: " << pobierzNazwe() << ", waga: " << pobierzWage() << ", objetosc: " << pobierzObjetosc() << ", liczba punktow razenia: " << pobierzLiczbaPunktowRazenia() << ", dlugosc ostrza: " << m_dlugoscOstrza << endl;}

double BronSieczna::pobierzDlugoscOstrza() const {
    return m_dlugoscOstrza;}

void BronSieczna::ustawDlugoscOstrza(double dlugoscOstrza) {
    m_dlugoscOstrza = dlugoscOstrza;}