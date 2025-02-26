#include <cstdio>
#include "Bron.h"

#ifndef __BRONPALNA_H__
#define __BRONPALNA_H__

#include <iostream>
#include <string>
using namespace std;

class BronPalna : virtual public Bron {
public:
    BronPalna(const string& nazwa, double waga, double objetosc, int liczbaPunktowRazenia, int pojemnoscMagazynka, const string& rodzajAmunicji);
    virtual ~BronPalna();

    int pobierzPojemnoscMagazynka() const;
    void ustawPojemnoscMagazynka(int pojemnoscMagazynka);

    const string& pobierzRodzajAmunicji() const;
    void ustawRodzajAmunicji(const string& rodzajAmunicji);

    virtual void wyswietl() const;

private:
    int m_pojemnoscMagazynka;
    string m_rodzajAmunicji;};

#endif
