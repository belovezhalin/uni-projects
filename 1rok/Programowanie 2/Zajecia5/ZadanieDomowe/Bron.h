#include <cstdio>
#include "Przedmiot.h"
#ifndef __BRON_H__
#define __BRON_H__

#include <iostream>
#include <string>
using namespace std;

class Bron : virtual public Przedmiot {
public:
    Bron(const std::string& nazwa, float waga, float objetosc, int liczbaPunktowRazenia, int cena = 0);

    virtual ~Bron();

    int pobierzLiczbaPunktowRazenia() const;
    void ustawLiczbaPunktowRazenia(int liczbaPunktowRazenia);

    int pobierzCena() const;
    void ustawCena(int cena);
    double pobierzWage() const;
    string pobierzNazwe() const;
    double pobierzObjetosc() const;
    virtual void wyswietl() const;

protected:
    int m_liczbaPunktowRazenia;
    int m_cena;};

#endif
