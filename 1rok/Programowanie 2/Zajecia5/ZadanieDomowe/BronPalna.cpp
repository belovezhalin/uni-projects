#include "Bronpalna.h"
#include <cstdio>

#include <iostream>
#include <string>
using namespace std;

BronPalna::BronPalna(const string& nazwa, double waga, double objetosc, int liczbaPunktowRazenia, int pojemnoscMagazynka, const string& rodzajAmunicji) : Bron(nazwa, waga, objetosc, liczbaPunktowRazenia), m_pojemnoscMagazynka(pojemnoscMagazynka), m_rodzajAmunicji(rodzajAmunicji) {
    cout << "Konstruktor klasy BronPalna" << endl;}

BronPalna::~BronPalna() {
    cout << "Destruktor klasy BronPalna" << endl;}

int BronPalna::pobierzPojemnoscMagazynka() const {
    return m_pojemnoscMagazynka;}

void BronPalna::ustawPojemnoscMagazynka(int pojemnoscMagazynka) {
    m_pojemnoscMagazynka = pojemnoscMagazynka;}

const string& BronPalna::pobierzRodzajAmunicji() const {
    return m_rodzajAmunicji;}

void BronPalna::ustawRodzajAmunicji(const string& rodzajAmunicji) {
    m_rodzajAmunicji = rodzajAmunicji;}

void BronPalna::wyswietl() const {
    cout << "BronPalna: " << pobierzNazwe() << ", waga: " << pobierzWage() << ", objetosc: " << pobierzObjetosc() << ", liczba punktow razenia: " << pobierzLiczbaPunktowRazenia() << ", pojemnosc magazynka: " << m_pojemnoscMagazynka << ", rodzaj amunicji: " << m_rodzajAmunicji << endl;}