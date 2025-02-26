#ifndef __PRZEDMIOT_H__
#define __PRZEDMIOT_H__

#include <string>
using namespace std;

class Przedmiot {
public: 
    Przedmiot();
    Przedmiot(string nazwa, double objetosc, double waga);
    virtual ~Przedmiot();
    virtual void wyswietl() const;

    string getNazwa() const;
    void setNazwa(string nazwa);
    double getObjetosc() const;
    void setObjetosc(double objetosc);
    double getWaga() const;
    void setWaga(double waga);
    string pobierzNazwe() const;
    double pobierzObjetosc() const;
    virtual void wyswietl() const;


private:
    string nazwa;
    double objetosc;
    double waga;};

#endif