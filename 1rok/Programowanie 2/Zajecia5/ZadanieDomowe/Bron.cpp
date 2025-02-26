#include "Bron.h"
#include <cstdio>

#include <iostream>
#include <string>
using namespace std;

Bron::Bron(const string& nazwa, float waga, float objetosc, int liczbaPunktowRazenia, int cena) : Przedmiot(nazwa, waga, objetosc), m_liczbaPunktowRazenia(liczbaPunktowRazenia), m_cena(cena) {
    cout << "Konstruktor klasy Bron" << endl;}

Bron::~Bron() {
    cout << "Destruktor klasy Bron" << endl;}

int Bron::pobierzLiczbaPunktowRazenia() const {
    return m_liczbaPunktowRazenia;}

void Bron::ustawLiczbaPunktowRazenia(int liczbaPunktowRazenia) {
    m_liczbaPunktowRazenia = liczbaPunktowRazenia;}

int Bron::pobierzCena() const {
    return m_cena;}

void Bron::ustawCena(int cena) {
    m_cena = cena;}

void Bron::wyswietl() const {
    Przedmiot::wyswietl();
    cout << "Liczba punktow razenia: " << m_liczbaPunktowRazenia << endl;
    cout << "Cena: " << m_cena << endl;}

