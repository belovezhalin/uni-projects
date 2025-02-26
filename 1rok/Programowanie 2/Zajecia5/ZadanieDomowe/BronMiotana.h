#include <cstdio>
#include "Bron.h"

#ifndef __BRONMIOTANA_H__
#define __BRONMIOTANA_H__

#include <iostream>
#include <string>
using namespace std;

class BronMiotana : virtual public Bron {
public:
    BronMiotana(const string& nazwa, double waga, double objetosc, int liczbaPunktowRazenia, double zasieg);
    virtual ~BronMiotana();

    double pobierzZasieg() const;
    void ustawZasieg(double zasieg);
    string pobierzNazwe() const;

    virtual void wyswietl() const;

private:
    double m_zasieg;};

#endif