#include <cstdio>
#include "Przedmiot.h"

#ifndef __POKARM_H__
#define __POKARM_H__

#include <iostream>
#include <string>
using namespace std;

class Pokarm : virtual public Przedmiot {
public:
    Pokarm(const std::string& nazwa, double objetosc, double waga, int kalorie, bool zawieraGluten);
    int pobierzKalorie() const;
    bool czyZawieraGluten() const;
    void ustawKalorie(int kalorie);
    void ustawZawieraGluten(bool zawieraGluten);
    virtual void wyswietl() const;

private:
    int kalorie_;
    bool zawieraGluten_;};

#endif