#ifndef Motolotnia_H
#define Motolotnia_H

#include "Lotnia.h"
#include "Samolot.h"
#include <iostream>
#include <string>
using namespace std;

class Motolotnia : public Lotnia, public Samolot
{
public:
   Motolotnia();
   ~Motolotnia();
   Motolotnia(string nazwa);
   void dodajRok();
   void wyswietlWiek() const override;
   friend ostream &operator<<(ostream &os, const Motolotnia &s);
};

ostream &operator<<(ostream &os, const Motolotnia &s);

#endif 
