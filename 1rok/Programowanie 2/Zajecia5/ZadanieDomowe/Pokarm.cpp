#include "Pokarm.h"
#include <cstdio>

#include <iostream>
#include <string>
using namespace std;

Pokarm::Pokarm(const std::string& nazwa, double objetosc, double waga, int kalorie, bool zawieraGluten) : Przedmiot(nazwa, objetosc, waga), kalorie_(kalorie), zawieraGluten_(zawieraGluten) {
    cout << "Konstruktor Pokarm" << endl;}

int Pokarm::pobierzKalorie() const {
    return kalorie_;}

bool Pokarm::czyZawieraGluten() const {
    return zawieraGluten_;}

void Pokarm::ustawKalorie(int kalorie) {
    kalorie_ = kalorie;}

void Pokarm::ustawZawieraGluten(bool zawieraGluten) {
    zawieraGluten_ = zawieraGluten;}
