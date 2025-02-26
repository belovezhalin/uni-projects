#include <cstdio>
#include "Bron.h"

#ifndef __BRONSIECZNA_H__
#define __BRONSIECZNA_H__

#include <iostream>
#include <string>
using namespace std;

class BronSieczna : virtual public Bron {
public:
    BronSieczna(const std::string& nazwa, double waga, double objetosc, int liczbaPunktowRazenia, double dlugoscOstrza);
    void wyswietl() const;
    double pobierzDlugoscOstrza() const;
    void ustawDlugoscOstrza(double dlugoscOstrza);

private:
    double m_dlugoscOstrza;
};

#endif
