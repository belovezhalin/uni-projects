#include "Czary.h"
#include <cstdio>

#include <iostream>
#include <string>
using namespace std;

Czary::Czary(std::string nazwa, double waga, double objetosc, int liczbaUzyc, int poziomMocy) : Przedmiot(nazwa, waga, objetosc), m_liczbaUzyc(liczbaUzyc), m_pozMocy(poziomMocy) {
    cout << "Konstruktor Czary" << endl;}

Czary::~Czary() {
    cout << "Destruktor Czary" << endl;}

void Czary::wyswietl() const {
    Przedmiot::wyswietl();
    cout << "Liczba uzyc: " << m_liczbaUzyc << endl;
    cout << "Poziom mocy: " << m_pozMocy << endl;}

int Czary::getPozMocy() const {
    return m_pozMocy;}

void Czary::setPozMocy(int poziomMocy) {
    if (poziomMocy > 0) m_pozMocy = poziomMocy;
    else cout << "Blad wartosci mocy" << endl;}

int Czary::getLiczbaUzyc() const {
    return m_liczbaUzyc;}

void Czary::setLiczbaUzyc(int liczbaUzyc) {
    if (liczbaUzyc > 0) m_liczbaUzyc = liczbaUzyc;
    else cout << "Blad wartosci lizby uzyc" << endl;}