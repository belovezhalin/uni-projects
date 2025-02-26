#ifndef Szybowiec_H
#define Szybowiec_H

#include "StatekPowietrzny.h"
#include <iostream>
#include <string>
using namespace std;

class Szybowiec : public virtual StatekPowietrzny
{
public:
   Szybowiec();
   ~Szybowiec();
   Szybowiec(string nazwa);
   void wyswietlWiek() const override;
   friend ostream &operator<<(ostream &os, const Szybowiec &s);
};

ostream &operator<<(ostream &os, const Szybowiec &s);

#endif 
