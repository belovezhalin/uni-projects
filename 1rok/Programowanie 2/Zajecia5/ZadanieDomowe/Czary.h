#include <cstdio>
#include "Przedmiot.h"

#ifndef __CZARY_H__
#define __CZARY_H__

#include <iostream>
#include <string>
using namespace std;

class Czary : virtual public Przedmiot {
public:
    Czary(std::string nazwa, double waga, double objetosc, int liczbaUzyc, int poziomMocy);
    virtual ~Czary();
    virtual void wyswietl() const;
    int getPozMocy() const;
    void setPozMocy(int poziomMocy);
    int getLiczbaUzyc() const;
    void setLiczbaUzyc(int liczbaUzyc);

private:
    int m_pozMocy;
    int m_liczbaUzyc;};

#endif
